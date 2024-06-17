/*!	\file

	@brief Declaration of the class Cure for handling cure materia in the game.
 */

/*!	\class Cure
	\brief Represents a Cure materia in the game, used for healing characters.
	The Cure class is derived from the AMateria class and provides specific
	functionality for curing characters.
*/

#ifndef CURE_HPP
# define CURE_HPP
# include <iostream>
# include "AMateria.hpp"
# include "Character.hpp"

class Cure : public AMateria
{
public:
	// Constructors:
	/*! \brief Default constructor.
		
		Initializes the Cure materia with type "Cure".
	*/
	Cure(void);

	/*!	\brief Parameterized constructor.

		Initializes the Cure materia with the provided string.
		
		\param type The type to initialize the Cure materia with.
	*/
	Cure(std::string const & type);

	/*!	\brief Copy constructor.

		\param copy The Cure object to be copied.
	*/
	Cure(Cure const & copy);

	// Deconstructor:
	/*!	\brief Deconstructor.

		Cleans up the Cure object.
	*/
	~Cure(void);

	// Operators
	/*! \brief Assignment operator.

		\param rhs rhs The Cure object to assign from.
		\return A reference to this Cure object.
	*/
	Cure const & operator=(Cure const & copy);

	/*! \brief Get the type of the Cure materia.

		\return A constant reference to the type string.
	*/
	std::string const & getType(void) const;

	/*! \brief Clones the Cure object.

		\return A pointer to the newly cloned Cure object.
	*/
	AMateria *	clone(void) const;

	/*!	\brief Uses the Cure materia on a target character to heal them.

		\param target The character to heal.
		\param power The amount of healing power to apply.
	*/
	void		use(Character & target, const int & power);
};

#endif