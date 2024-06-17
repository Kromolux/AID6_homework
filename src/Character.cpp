/*! \file

	@brief Definition of the class Character: Main Character class in use
 */

/* Implementation of the Character class */


#include "../inc/Character.hpp"

// Constructors:
Character::Character()
{}

Character::Character(std::string const name, const int HP, const int MP)
{
	this->_name = name;
	_MaxHP = _HP = HP;
	_MaxMP = _MP = MP;
	_MaxAP = _AP = 1;
	_changeHP = 0;
	_changeMP = 0;
}

Character::Character(Character const & copy)
{
	*this = copy;
	this->_name = copy._name + "_copy";
}

// Deconstructor:
Character::~Character(void)
{
	for (size_t i = 0; i < _spellBook.size(); ++i)
	{
		delete _spellBook[i];
	}
}

Character const & Character::operator=(Character const & rhs)
{
	this->_name = rhs._name + "_assigned";
	_HP = rhs._HP;
	_MP = rhs._MP;

	return (*this);
}

// set-ter and get-ter:
std::string const & Character::getName(void) const
{
	return (this->_name);
}

int		Character::getAP(void) const
{
	return (_AP);
}

void	Character::changeAP(const int change)
{
	_AP += change;
	if (_AP > _MaxAP)
		_AP = _MaxAP;
}

int		Character::getChangeHP(void)
{
	int	tmp = _changeHP;
	_changeHP = 0;
	return (tmp);
}

int		Character::getChangeMP(void)
{
	int	tmp = _changeMP;
	_changeMP = 0;
	return (tmp);
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

void	Character::changeHP(const int change)
{
	if (_status == STATUS_DEAD)		// If the Character is DEAD, no change in HP is allowed, return
		return ;

	if ((change + _HP) > _MaxHP)	// If the (change HP + actual HP) value is greater than the maxHP
	{
		_changeHP = _MaxHP - _HP;	// Sets changeHP to (maxHP - HP)
		_HP = _MaxHP;				// Sets actual HP to maxHP
	}
	else
	{
		_changeHP += change;		// Adds the change value provided to _changeHP
		_HP += change;				// Adds the change value provided to _HP
	}

	if (_HP <= 0)					// If the Character _HP is less or equal zero
	{
		_status = STATUS_DEAD;		// Set the Character Status to DEAD
	}
}

void	Character::changeMP(const int change)
{
	if ((change + _MP) > _MaxMP)	// If the (change MP + actual MP) value is greater than the maxMP
	{
		_changeMP = _MaxMP - _MP;	// Sets changeMP to (maxMP - MP)
		_MP = _MaxMP;				// Sets actual MP to maxMP
	}
	else
	{
		_changeMP += change;		// Adds the change value provided to _changeMP
		_MP += change;				// Adds the change value provided to _MP
	}
}

std::vector<Dice> &	Character::getDiceSupply(void)
{
	return (_diceSupply);
}

std::vector<AMateria*> &	Character::getSpellBook(void)
{
	return (_spellBook);
}

t_status const &	Character::getStatus(void) const
{
	return (_status);
}

void	Character::setStatus(t_status const statusNr)
{
	_status = statusNr;
}

std::string	const & Character::getFaction(void) const
{
	return (_faction);
}

void	Character::setFaction(std::string const faction)
{
	_faction = faction;
}


// Adder functions:
void	Character::addDice(Dice const dice)
{
	_diceSupply.push_back(dice);
}

void	Character::addSpell(AMateria * spell)
{
	_spellBook.push_back(spell);
}

// Selector functions:
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

size_t	Character::EnemySelectSpell(void)
{
	// enemies just have one spell at this time, may add more later ;-)
	// it will only cast the spell at pos 1 from the spellbook
	return (1);
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
