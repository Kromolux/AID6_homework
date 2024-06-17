/*!	\file

	@brief Declaration of the class Meditate for handling Meditate materia in the game.
 */

/*!	\class Meditate
	\brief Represents a Meditate materia in the game, used for restoring magic/ mana points of characters.
	The Meditate class is derived from the AMateria class and provides specific
	functionality for restoring characters MP.
*/


#ifndef MEDITATE_HPP
# define MEDITATE_HPP
# include <iostream>
# include "AMateria.hpp"
# include "Character.hpp"

class Meditate : public AMateria
{
public:
	// Constructors:
	/*! \brief Default constructor.
		
		Initializes the Meditate materia with type "Meditate".
	*/
	Meditate(void);

	/*!	\brief Parameterized constructor.

		Initializes the Cure materia with the provided string.
		
		\param type The type to initialize the Cure materia with.
	*/
	Meditate(std::string const & type);

	/*!	\brief Copy constructor.

		\param copy The Meditate object to be copied.
	*/
	Meditate(Meditate const & copy);

	// Deconstructor:
	/*!	\brief Deconstructor.

		Cleans up the Meditate object.
	*/
	~Meditate(void);

	// Operators
	/*! \brief Assignment operator.

		\param rhs rhs The Meditate object to assign from.
		\return A reference to this Meditate object.
	*/
	Meditate const & operator=(Meditate const & rhs);

	/*! \brief Get the type of the Meditate materia.

		\return A constant reference to the type string.
	*/
	std::string const & getType(void) const;

	/*! \brief Clones the Meditate object.

		\return A pointer to the newly cloned Meditate object.
	*/
	AMateria *	clone(void) const;

	/*!	\brief Uses the Meditate materia on a target character to restore MP.

		\param target The character to restore MP.
		\param power The amount of restore power to apply.
	*/
	void		use(Character & target, const int & power);
};

#endif