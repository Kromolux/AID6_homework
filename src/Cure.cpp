/*! \file

	@brief Definition of the class Cure for handling cure materia in the game.
 */

/* Implementation of the Cure class */


#include "../inc/Cure.hpp"

Cure::Cure(void) : AMateria("Cure")
{}

Cure::Cure(std::string const & type) : AMateria(type)
{}

Cure::Cure(Cure const & copy) : AMateria("Cure_copy")
{
	*this = copy;
}

Cure::~Cure(void)
{}

Cure const & Cure::operator=(Cure const & rhs)
{
	if ( this != &rhs )
	{
		_type = rhs._type;
	}
	return ( *this );
}


std::string const & Cure::getType(void) const
{
	return (this->_type);
}

AMateria *	Cure::clone(void) const
{
	return (new Cure("Cure_clone"));
}

void	Cure::use(Character & target, const int & power)
{
	printf(GREEN " heals <%i> %s's wounds " RESET, power, target.getName().c_str());
	target.changeHP(power);
}
