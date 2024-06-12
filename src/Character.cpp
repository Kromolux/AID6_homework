
#include "../inc/Character.hpp"

Character::Character()
{}

Character::Character(std::string const name, const int HP, const int MP)
{
	this->_name = name;
	_MaxHP = _HP = HP;
	_MaxMP = _MP = MP;
	_MaxAP = _AP = 1;
}

Character::Character(Character const & input)
{
	*this = input;
	this->_name = input._name + "_copy";
}

Character const & Character::operator=(Character const & input)
{
	this->_name = input._name + "_assigned";
	_HP = input._HP;
	_MP = input._MP;

	return (*this);
}

Character::~Character(void)
{
	for (size_t i = 0; i < _spellBook.size(); ++i)
	{
		delete _spellBook[i];
	}
}

std::string const & Character::getName(void) const
{
	return (this->_name);
}


std::vector<Dice> &	Character::getDiceSupply(void)
{
	return (_diceSupply);
}

std::vector<AMateria*> &	Character::getSpellBook(void)
{
	return (_spellBook);
}

void	Character::addDice(Dice dice)
{
	_diceSupply.push_back(dice);
}

void	Character::addSpell(AMateria * spell)
{
	_spellBook.push_back(spell);
}

size_t	Character::PlayerSelectSpell(void)
{
	size_t	spellNr;
	int		userinput;
	printf("=> Enter spell symbol ( )\b\b");
	do
	{
		do
		{
			userinput = myGetch();
		} while (userinput < '1' || userinput > '9');
		
		spellNr = (size_t) (userinput - '0');
	} while (spellNr >= _spellBook.size());
	printf("%li", spellNr);
	printf(") = %s", _spellBook.at(spellNr)->getType().c_str());
	return (spellNr);
}

size_t	Character::PlayerSelectTarget(Character ** gameMap)
{
	size_t	targetNr;
	int		userinput;

	printf(MAGENTA "=> Enter target symbol { }\b\b");
	do
	{
		do
		{
			userinput = myGetch();
		} while (userinput < '0' || userinput > '9');
		targetNr = (size_t) (userinput - '0');

	} while (!gameMap[targetNr]);
	printf("%li", targetNr);
	printf("} = %s" RESET, gameMap[targetNr]->getName().c_str());
	return (targetNr);
}


void	Character::castSpellAtTarget(size_t spellNr, Character * target, int power)
{
	if (_faction == "Player")
		printf(BOLDGREEN);
	else
		printf(BOLDRED);

	printf("%s" RESET, _name.c_str());
	_spellBook[spellNr]->use(*target, power);
}

size_t	Character::EnemySelectSpell(void)
{
	// enemies just have one spell at this time, may add more later ;-)
	return (1);
}

int		Character::getHP(void) const
{
	return (_HP);
}

int		Character::getMaxHP(void) const
{
	return (_MaxHP);
}

int		Character::getMP(void) const
{
	return (_MP);
}

int		Character::getMaxMP(void) const
{
	return (_MaxMP);
}

void	Character::incHP(const int change)
{
	if (_status == STATUS_DEAD)
		return ;

	_HP += change;
	if (_HP > _MaxHP)
		_HP = _MaxHP;
	if (_HP <= 0)
	{
		_HP = 0;
		_status = STATUS_DEAD;
	}
}

void	Character::incMP(const int change)
{
	_MP += change;
	if (_MP > _MaxMP)
		_MP = _MaxMP;
	if (_MP <= 0)
	{
		_MP = 0;
	}
}

t_status	Character::getStatus(void) const
{
	return (_status);
}

void	Character::setStatus(t_status statusNr)
{
	_status = statusNr;
}

std::string	const & Character::getFaction(void) const
{
	return (_faction);
}

void	Character::setFaction(std::string fraction)
{
	_faction = fraction;
}

int		Character::getAP(void) const
{
	return (_AP);
}

void	Character::incAP(const int change)
{
	_AP += change;
	if (_AP > _MaxAP)
		_AP = _MaxAP;
}
