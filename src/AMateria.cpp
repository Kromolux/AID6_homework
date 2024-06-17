/*! \file
 *
 * @brief Definition of the class AMateria: An abstract class for materials used as spells.
 */

/* Implementation of the AMateria class */

#include "../inc/AMateria.hpp"

// Constructors
AMateria::AMateria(std::string const & type)
{
	this->_type = type;
}

AMateria::AMateria(AMateria const & input)
{
	*this = input;
}

// Deconstructor
AMateria::~AMateria(void)
{}

// Operators
AMateria const & AMateria::operator=(AMateria const & input)
{
	this->_type = input._type;
	return (*this);
}

// Get-ter
std::string	const & AMateria::getType(void) const
{
	return (this->_type);
}

// Use function
void	AMateria::use(Character & target, const int & power)
{
	(void) target;
	(void) power;
}
