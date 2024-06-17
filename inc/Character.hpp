/*!	\file

	@brief Declaration of the class Character: Main Character class in use
*/

/*!	\class Character
	\brief Represents the Character used in the Game class, it can hold several variables.

	This class provides functionalities for working with Characters in a 2-dimensional game map.
*/

#ifndef CHARACTER_HPP
# define CHARACTER_HPP
# include <iostream>
# include "AMateria.hpp"
# include "Dice.hpp"
# include "TerminalManager.h"
# include <vector>

/*!	\brief Represents the status of an entity.

	\enum e_status
	This enumeration defines the possible statuses an entity can have.
 */
typedef enum e_status
{
	STATUS_DEAD,		/*!< Entity is dead. */
	STATUS_UNDEAD,		/*!< Entity is undead. */
	STATUS_ALIVE		/*!< Entity is alive. */
}			 t_status;

class AMateria;

class Character
{
protected:
	std::string	_name;		/*!<The name of the character itself */
	t_status	_status;	/*!<The status of the character - enum struct */
	std::string	_faction;	/*!<The faction of the character - string */

	std::vector<Dice>		_diceSupply;	/*!<A container Vector that can hold the Dice class */
	std::vector<AMateria*>	_spellBook;		/*!<A container Vector that can hold the AMateria pointer class */

	int	_HP;		/*!<The health points - HP */
	int	_MaxHP;		/*!<The maximum health points */
	int	_changeHP;	/*!<Change of the health points since last time */
	int	_MP;		/*!<The magic/mana points - MP */
	int	_MaxMP;		/*!<The maximum magic/mana points */
	int	_changeMP;	/*!<Change of the magic/ mana points since last time */
	int	_AP;		/*!<The action points - AP */
	int	_MaxAP;		/*!<The maximum action points */

public:
	// Constructors
	/*!	\brief Parameterized constructor.

		Initializes the Character class with the provided parameters.
		
		\param name Name of the Character as string.
		\param HP Actual and maximum health points.
		\param MP Actual and maximum magic/ mana points.
	*/
	Character(std::string const name, const int HP, const int MP);

	/*! \brief Copy constructor.

		Creates a copy of the given Character object.
		\param copy The Character object to be copied.
	*/
	Character(Character const & copy);

	/*!	\brief Deconstructor.

		Cleans up resources allocated for AMateria objects stored in the vector _spellBook.
	*/
	~Character(void);

	// Operators
	/*!	\brief Assignment operator.

		Assigns the variables of the given Character object to the current object.

		\param rhs The Character object on the right-hand side of the assignment.

		\return Reference to the current Character object after assignment.
	*/
	Character const & operator=(Character const & rhs);

	// set-ter and get-ter
	/*!	\brief Gets the the Name of the Character.

		\return Name string.
	*/
	std::string const & getName(void) const;

	/*!	\brief Gets the HP of the Character.

		\return HP value.
	*/
	int		getHP(void) const;

	/*!	\brief Gets the maximum HP of the Character.

		\return max HP value.
	*/
	int		getMaxHP(void) const;

	/*!	\brief Changes the HP value of the Character by the provided integer.

		\param change The value added up to the actual value.
	*/
	void	changeHP(const int change);

	/*!	\brief Gets the MP of the Character.

		\return MP value.
	*/
	int		getMP(void) const;

	/*!	\brief Gets the maximum MP of the Character.

		\return max MP value.
	*/
	int		getMaxMP(void) const;

	/*!	\brief Changes the MP value of the Character by the provided integer.

		\param change The value added up to the actual value.
	*/
	void	changeMP(const int change);

	/*!	\brief Gets the changed HP value of the Character.

		\return change HP value.
	*/
	int		getChangeHP(void);

	/*!	\brief Gets the changed MP value of the Character.

		\return change MP value.
	*/
	int		getChangeMP(void);
	
	/*!	\brief Gets the AP value of the Character.

		\return AP value.
	*/
	int		getAP(void) const;

	/*!	\brief Changes the AP value of the Character by the provided integer.

		\param change The value added up to the actual value.
	*/
	void	changeAP(const int change);

	/*!	\brief Gets the container vector for Dice objects.

		\return reference to _diceSupply.
	*/
	std::vector<Dice> &	getDiceSupply(void);

	/*!	\brief Gets the container vector for AMateria pointer objects.

		\return reference to _spellBook.
	*/
	std::vector<AMateria*> &	getSpellBook(void);

	/*!	\brief Gets the status of the Character.

		\return const reference to _status.
	*/
	t_status const &	getStatus(void) const;

	/*!	\brief Sets the Status enum value of the Character.

		\param statusNr The enum value of the new status.
	*/
	void	setStatus(t_status const statusNr);

	/*!	\brief Gets the faction string of the Character.

		\return const reference to _faction.
	*/
	std::string	const & getFaction(void) const;

	/*!	\brief Sets the Faction string of the Character.

		\param faction The enum value of the new status.
	*/
	void	setFaction(std::string const faction);

	/*!	\brief Adds a Dice object to the vector container _diceSupply.

		\param dice The Dice object.
	*/
	void	addDice(Dice const dice);

	/*!	\brief Adds a AMateria pointer to the vector container _spellBook.

		\param spell The new created AMateria object pointer.
	*/
	void	addSpell(AMateria * spell);

	/*!	\brief Prompts the player to select a spell from the spellbook.

		\return spellnumber in spellbook.
	*/
	size_t	PlayerSelectSpell(void);

	/*!	\brief Prompts the player to select a target from the gameMap.

		\param gameMap The gameMap double pointer "2D container of Characters - Array".
		\return Characternumber on the gameMap.
	*/
	size_t	PlayerSelectTarget(Character ** gameMap);

	/*!	\brief Logic for the enemy to select a spell from the spellbook.

		\return spellnumber in spellbook.
	*/
	size_t	EnemySelectSpell(void);

	/*!	\brief Casts the spell at the selected target with the provided power.

		\param spellNr The Spellnumber from the spellbook.
		\param target The target at which the spell is cast.
		\param power The power of the spell.
	*/
	void	castSpellAtTarget(size_t spellNr, Character * target, int power);

private:
	/*! \brief Default constructor.
		
		Is not usable, since it is a private constructor.
	*/
	Character(void);
};

#endif