/*!	\file

	@brief Declaration of the class AMateria: An abstract class for materials used as spells.
 */

/*!	\class AMateria
	\brief The class is used to hold inherited material classes, used as spells for the Character class to cast.
	circular include for Character class
*/


#ifndef AMATERIA_HPP
# define AMATERIA_HPP
# include "Character.hpp"

class Character;

class AMateria
{

protected:
	std::string	_type;	/*!<The name of the materia */

public:
	// Constructors:
	/*!	\brief Parameterized constructor.

		Initializes the AMatiera class with the provided string.
		
		\param type String of the matieral type/ name.
	*/
	AMateria(std::string const & type);

	/*! \brief Copy constructor.

		Creates a copy of the given Cure object.
		\param copy The AMateria object to be copied.
	*/
	AMateria(AMateria const & copy);

	/*! \brief Destructor, virtual is not called from the abstract class itself. */
	virtual ~AMateria(void);


	// Operators
	/*! \brief Assignment operator.

		\param rhs The AMateria object on the right-hand side of the assignment.
		\return A reference to the assigned AMateria object.
	*/
	AMateria const & operator=(AMateria const & rhs);

	/*! \brief Get the material name.

		\return A const reference to the std::string _type that contains the material name.
	*/
	std::string const & getType(void) const;

	/*! \brief Clone the material.

		\return A new created object of the same type.
	*/
	virtual	AMateria *	clone(void) const = 0;

	/*! \brief Use the materia.

		\param target The target of the spell, where it is casted at.
		\param power The power of the spell itself.
		The materia function use gets called.
	*/
	virtual void		use(Character & target, const int & power);

private:
	/*! \brief Default constructor.
		
		Is not usable, since it is a private constructor.
	*/
	AMateria(void);
	
};

#endif