#ifndef GAME_HPP
# define GAME_HPP

# include "Character.hpp"
# include <ctime>
# include <iostream>

# include "../inc/Dice.hpp"
# include "../inc/AMateria.hpp"
# include "../inc/Meditate.hpp"
# include "../inc/Icebolt.hpp"
# include "../inc/Cure.hpp"
# include "../inc/TerminalManager.h"

# define MAXNAMECHARS 19
# define STATSROW 12
# define STATSCOL 3

typedef enum e_enemy
{
	SKELETON_FROSTMAGE,
	SKELETON_HEALER,
	SKELETON_NECROMANCER
}			 t_enemy;


class Game
{
private:
	int	_NrOfPlayers;
	bool _Playerturn;

	Character *_gameMap[10];

	int	_terminalRow;
	int	_terminalCol;
	int	_terminalMaxRow;

public:
	Game(void);
	~Game(void);

	void	initNewGame(void);
	void	gameLoop(void);

	void	enemyTurn(void);
	void	playerTurn(void);

	void	displayBar(int size, int current, int max, const char * color);
	void	displayAllEntites(void);
	void	displayEntity(int col, int row, int idx);

	void	createNewPlayer(int idx);
	void	createNewEnemy(int idx, t_enemy enemyNr);
	bool	isEnemyDead(void);
	void	restoreAP(void);

	std::string	getStatusText(t_status statusNr);

	Character * getPlayer(void);

	int		getDiceResult(Character * user, const int MPSpend);
};

#endif