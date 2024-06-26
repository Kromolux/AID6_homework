/*! \file

	@brief Definition of the Game class responsible for managing the game logic and characters.
 */

/* Implementation of the Game class */


#include "../inc/Game.hpp"

Game::Game(void)
{
	_Playerturn = true;

	std::srand( static_cast<unsigned int>(std::time( NULL )));  // Seed the random number generator

	for (int i = 0; i < GAME_MAP_SIZE; ++i)
		_gameMap[i] = NULL;

	setlocale(LC_ALL, "");
	_terminalCol = GAME_TERMINAL_COL;
	_terminalRow = GAME_TERMINAL_ROW;
	_terminalMaxRow = 24;
}

Game::~Game(void)
{
	for (int i = 0; i < GAME_MAP_SIZE; ++i)
		if (_gameMap[i])
			delete _gameMap[i];
	freeTerminal();
}

void	Game::initNewGame(void)
{
	system("clear");
	initTerminal();
	drawBoxDoubleLine(1, 1, 24, 80);

	moveCursor(16, 1);
	printf("╠");
	for (int i = 1; i < 79; ++i)
		printf("═");
	printf("╣");
	moveCursor(1, 28);
	printf(YELLOW "[ Dice Treasure Hunter ]" RESET);

	moveCursor(_terminalRow, _terminalCol);

	createNewPlayer(2);
	clearLine(_terminalRow);

	createNewEnemy(4, SKELETON_FROSTMAGE);
	createNewEnemy(6, SKELETON_FROSTMAGE);
	createNewEnemy(8, SKELETON_FROSTMAGE);
}


void	Game::gameLoop(void)
{
	bool	playerwon = false;

	while (true)		// endless game loop
	{
		displayAllEntites();

		if (_Playerturn)
			playerTurn();
		else
			enemyTurn();

		clearOutput();
		restoreAP();
		_terminalRow = GAME_TERMINAL_ROW;
		_Playerturn ^= 1;

		if (isEnemyDead())								// game over! player has won the game -> end loop
		{
			playerwon = true;
			break;
		}
		if (getPlayer()->getStatus() == STATUS_DEAD)	// game over! player is dead -> end loop
			break;
	}

	displayAllEntites();
	moveCursor(_terminalRow, _terminalCol);
	if (playerwon)
		printf("***Congratulations %s! You have won the game!***", getPlayer()->getName().c_str());
	else
		printf("***Nice try %s! You died. Game Over!***", getPlayer()->getName().c_str());
	myGetch();
	moveCursor(25, 1);
}

void	Game::playerTurn(void)
{
	Character * player = getPlayer();
	int		power;

	moveCursor(16, 33);
	printf(BOLDGREEN "[ Player Turn ]" RESET);

	if (player->getMP() == 0)
	{
			power = getDiceResult(player, 0);
			moveCursor(_terminalRow, _terminalCol);
			player->castSpellAtTarget(0, player, power);
	}
	else
	{
		size_t spellBookSize = player->getSpellBook().size();

		printf(CYAN);
		for (size_t i = 1; i < spellBookSize; ++i)
		{
			moveCursor(_terminalRow + (int) i, _terminalCol);
			printf("(%li) %s", i, player->getSpellBook().at(i)->getType().c_str());
		}
		moveCursor(_terminalRow++, _terminalCol);
		size_t	spellNr = player->PlayerSelectSpell();
		printf(RESET);

		for (size_t i = 2; i < spellBookSize; ++i)
			clearLine(17 + (int) i);

		moveCursor(_terminalRow++, _terminalCol);
		size_t	targetNr = player->PlayerSelectTarget(_gameMap);
		power = getDiceResult(player, 1);
		moveCursor(_terminalRow, _terminalCol);
		player->castSpellAtTarget(spellNr, _gameMap[targetNr], power);
	}
	player->changeAP(-1);
	displayAllEntites();
	moveCursor(++_terminalRow, _terminalCol);
	pressAnyKey(_terminalRow);
}

void	Game::enemyTurn(void)
{
	Character	*enemy = NULL;
	size_t		spellNr = 0;
	int			power;

	moveCursor(16, 33);
	printf(BOLDRED "[ Enemy Turn ]" RESET DHLINE);

	for (int i = 1; i < 10; ++i)			// loop over all possible map positions
	{
		if (_gameMap[i])					// if there is an entity pointer
		{
			// If the enemy is not DEAD and has action points available
			if (_gameMap[i]->getFaction() == "Enemy" && _gameMap[i]->getStatus() != STATUS_DEAD && _gameMap[i]->getAP() > 0)
			{
				moveCursor(_terminalRow, _terminalCol);
				enemy = _gameMap[i];
				if (enemy->getMP() == 0)				// enemy is out of mana and needs to meditate to restore mana
				{
					power = getDiceResult(enemy, 0);
					moveCursor(_terminalRow++, _terminalCol);
					enemy->castSpellAtTarget(0, enemy, power);
				}
				else									// enemy can cast a spell
				{
					spellNr = enemy->EnemySelectSpell();
					power = getDiceResult(enemy, 1);
					moveCursor(_terminalRow++, _terminalCol);
					enemy->castSpellAtTarget(spellNr, getPlayer(), power);
				}
				enemy->changeAP(-1);
				displayAllEntites();
				moveCursor(_terminalRow, _terminalCol);
				pressAnyKey(_terminalRow);
				if (getPlayer()->getHP() <= 0)
					break;
			}
		}
	}
}

Character * Game::getPlayer(void)
{
	for (int i = 1; i < GAME_MAP_SIZE; ++i)		// loop over all possible map positions
	{
		if (_gameMap[i])				// if there is an entity pointer
		{
			if(_gameMap[i]->getFaction() == "Player")	// if the faction is "Player"
				return (_gameMap[i]);
		}
	}
	return (NULL);
}

void	Game::displayBar(int size, int currentP, int changeP, int maxP, const char * color)
{
	int	sizeBarCurrent = 0;
	int	sizeBarChange = 0;

	if (currentP < 0)			// entity has negativ points currently
	{
		if (changeP < 0)
			changeP -= currentP;	// subtract the current points from the change to get the remaining change number
	}
	else						// entity has positive points currently
	{
		sizeBarCurrent = (int) ( ((double) currentP * size / maxP) + 0.5);
	}

	// positive changeP => increased value - currentP contains it already
	if (changeP > 0)			// the change is positive means increase in value
	{
		sizeBarChange  = (int) ( ( (double) changeP * size / maxP) + 0.5);
		sizeBarCurrent -= sizeBarChange;
	}
	// negative changeP => decreased value - currentP does not contain it
	else if (changeP < 0)
	{
		sizeBarChange = (int) ( ( (double) changeP * size / maxP) - 0.5) * -1;
	}

	printf("%s", color);
	for (int i = 0; i < sizeBarCurrent; ++i)
		printf("█");

	printf(YELLOW);
	for (int i = 0; i < sizeBarChange; ++i)
		printf("▓");

	printf("%s", color);
	for (int i = sizeBarCurrent + sizeBarChange; i < size; ++i)
		printf("░");

	printf(RESET);
}

void	Game::displayAllEntites(void)
{
	int	idx = 1;
	int	startCol = STATS_COL;
	int	startRow = STATS_ROW;

	/* the game map is a 3 by 3 2D square. Idx zero is not used
		7	8	9
		4	5	6
		1	2	3
	*/
	for (int i = 0; i < 3; ++i)
	{
		for (int j = 0; j < 3; ++j, ++idx)
		{
			displayEntity(startCol + j * 26, startRow - i * 5, idx);
		}
	}
}

void	Game::displayEntity(int col, int row, int idx)
{
	Character * entity = _gameMap[idx];

	if (!entity)		// if the entity pointer is null, return
		return ;

	moveCursor(row, col);
	if (entity->getFaction() == "Player")
		printf(MAGENTA "{%i} " BOLDGREEN "%s" RESET, idx, entity->getName().c_str());
	else
		printf(MAGENTA "{%i} " BOLDRED "%s" RESET, idx, entity->getName().c_str());

	moveCursor(row + 1, col);

	switch (entity->getStatus())
	{
	case STATUS_DEAD:
		printf(RED);
		break;
	case STATUS_UNDEAD:
		printf(GREEN);
		break;
	case STATUS_ALIVE:
		printf(GREEN);
		break;
	default:
		printf(WHITE);
		break;
	}
	printf("[%s]" RESET, getStatusText(entity->getStatus()).c_str());

	moveCursor(row + 2,col);
	printf(WHITE "HP [%3i/%3i]" RESET, entity->getHP(), entity->getMaxHP());
	displayBar(10, entity->getHP(), entity->getChangeHP(), entity->getMaxHP(), RED);

	moveCursor(row + 3, col);
	printf(WHITE "MP [%3i/%3i]" RESET, entity->getMP(), entity->getMaxMP());
	displayBar(10, entity->getMP(), entity->getChangeMP(), entity->getMaxMP(), BLUE);
}

void	Game::createNewPlayer(int idx)
{
	Character ** newEntity = NULL;
	if (_gameMap[idx])
		delete newEntity;
	newEntity = &_gameMap[idx];

	char playername[MAX_NAME_CHARS + 1];
	printf("=> Please enter your name: ");
	std::cin.getline(playername, MAX_NAME_CHARS);

	*newEntity = (new Character(playername, 25, 10));
	(*newEntity)->setFaction("Player");
	(*newEntity)->addDice(Dice());
	(*newEntity)->addDice(Dice());
	(*newEntity)->addDice(Dice());
	(*newEntity)->addSpell(new Meditate());
	(*newEntity)->addSpell(new Icebolt());
	(*newEntity)->addSpell(new Cure());
	(*newEntity)->setStatus(STATUS_ALIVE);
}

void	Game::createNewEnemy(int idx, t_enemy enemyNr)
{
	Character ** newEntity = NULL;
	if (_gameMap[idx])
		delete newEntity;
	newEntity = &_gameMap[idx];

	switch (enemyNr)
	{
	case SKELETON_FROSTMAGE :
			*newEntity = (new Character("Skeleton Frostmage", 15, 5));
			(*newEntity)->addDice(Dice());
			(*newEntity)->addSpell(new Meditate());
			(*newEntity)->addSpell(new Icebolt());
			(*newEntity)->setStatus(STATUS_UNDEAD);
			(*newEntity)->setFaction("Enemy");
		break;
	
	default:
		break;
	}
}

bool	Game::isEnemyDead(void)
{
	for ( int i = 1; i < GAME_MAP_SIZE; ++i)		// loop over all possible map positions
	{
		if (_gameMap[i])				// if there is an entity pointer
		{
			if (_gameMap[i]->getFaction() == "Enemy")	// if the faction is "Enemy"
			{
				if (_gameMap[i]->getStatus() != STATUS_DEAD)	// if the entity is not DEAD return false
					return (false);
			}
		}
	}
	return (true);						// return true if all Enemies on the game map are DEAD
}

std::string	Game::getStatusText(t_status statusNr)
{
	switch (statusNr)
	{
	case STATUS_DEAD:
		return("---DEAD---");
	case STATUS_UNDEAD:
		return ("undead");
	case STATUS_ALIVE:
		return("alive");
	default:
		return("unknown");
	}
}

int		Game::getDiceResult(Character * user, const int MPSpend)
{
	int	power = 0;
	Dice	*dice;

	printf(YELLOW);
	moveCursor(_terminalRow++, _terminalCol);

	for (size_t i = 0; i < user->getDiceSupply().size(); ++i)
	{
		if (user->getMP() >= MPSpend)
		{
			dice = &user->getDiceSupply()[i];
			printf("[D%i+%i] = <%i> ", dice->getSides(), dice->getBonus(), dice->roll());
			power += dice->getLastRoll();
			user->changeMP(- MPSpend);
		}
	}
	printf(RESET);
	return (power);
}

void	Game::restoreAP(void)
{
	for (int i = 1; i < GAME_MAP_SIZE; ++i)		// loop over all possible map positions
	{
		if (_gameMap[i] && _gameMap[i]->getStatus() != STATUS_DEAD)
			_gameMap[i]->changeAP(1);
	}
}
