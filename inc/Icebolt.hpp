/*!	\file

	@brief Declaration of the class Icebolt for handling Icebolt materia in the game.
 */

/*!	\class Icebolt
	\brief Represents a Icebolt materia in the game, used for damaging characters.
	The Icebolt class is derived from the AMateria class and provides specific
	functionality for damaging characters.
*/

#ifndef ICEBOLT_HPP
# define ICEBOLT_HPP
# include <iostream>
# include "AMateria.hpp"
# include "Character.hpp"

class Icebolt : public AMateria
{
public:
	// Constructors:
	/*! \brief Default constructor.
		
		Initializes the Icebolt materia with type "Icebolt".
	*/
	Icebolt( void );

	/*!	\brief Parameterized constructor.

		Initializes the Icebolt materia with the provided string.
		
		\param type The type to initialize the Icebolt materia with.
	*/
	Icebolt(std::string const & type);

	/*!	\brief Copy constructor.

		\param copy The Icebolt object to be copied.
	*/
	Icebolt(Icebolt const & copy);

	// Deconstructor:
	/*!	\brief Deconstructor.

		Cleans up the Icebolt object.
	*/
	~Icebolt(void);

	// Operators
	/*! \brief Assignment operator.

		\param rhs rhs The Icebolt object to assign from.
		\return A reference to this Icebolt object.
	*/
	Icebolt const & operator=(Icebolt const & rhs);

	/*! \brief Get the type of the Icebolt materia.

		\return A constant reference to the type string.
	*/
	std::string const & getType(void) const;

	/*! \brief Clones the Icebolt object.

		\return A pointer to the newly cloned Icebolt object.
	*/
	AMateria *	clone(void) const;

	/*!	\brief Uses the Icebolt materia on a target character to damage them.

		\param target The character to shot at.
		\param power The amount of damage power to apply.
	*/
	void		use(Character & target, const int & power);
};

#endif