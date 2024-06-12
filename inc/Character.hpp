#ifndef CHARACTER_HPP
# define CHARACTER_HPP
# include <iostream>
# include "AMateria.hpp"
# include "Dice.hpp"
# include "TerminalManager.h"
# include <vector>

typedef enum e_status
{
	STATUS_DEAD,
	STATUS_UNDEAD,
	STATUS_ALIVE
}			 t_status;

class AMateria;

class Character
{

public:
	
	Character(std::string const name, const int HP, const int MP);
	Character(Character const & input);
	Character const & operator=(Character const & input);
	~Character(void);

	std::string const & getName( void ) const;

	void	addDice(Dice dice);
	void	addSpell(AMateria * spell);

	std::string	displayStats(void) const;

	int		getHP(void) const;
	int		getMaxHP(void) const;
	int		getMP(void) const;
	int		getMaxMP(void) const;
	int		getChangeHP(void);
	int		getChangeMP(void);
	
	int		getAP(void) const;
	void	incAP(const int change);

	void	incHP(const int change);
	void	incMP(const int change);

	size_t	PlayerSelectSpell(void);
	size_t	PlayerSelectTarget(Character ** gameMap);
	void	castSpellAtTarget(size_t spellNr, Character * target, int power);

	size_t	EnemySelectSpell(void);
	int		getDiceResult(const int MPSpend) const;

	t_status	getStatus(void) const;
	void	setStatus(t_status statusNr);

	std::string	const & getFaction(void) const;
	void	setFaction(std::string faction);
	
	std::vector<Dice> &	getDiceSupply(void);
	std::vector<AMateria*> &	getSpellBook(void);

private:

	Character( void );
	
	std::string	_name;
	t_status	_status;
	std::string	_faction;

	std::vector<Dice>		_diceSupply;
	std::vector<AMateria*>	_spellBook;
	std::vector<AMateria*>	_skillSupply;

	int	_HP;
	int	_MaxHP;
	int	_changeHP;
	int	_MP;
	int	_MaxMP;
	int	_changeMP;
	int	_AP;
	int	_MaxAP;

};

#endif