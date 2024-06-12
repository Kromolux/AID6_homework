#include "../inc/Cure.hpp"

Cure::Cure(void) : AMateria("Cure")
{}

Cure::Cure(std::string const & type) : AMateria(type)
{}

Cure::Cure(Cure const & input) : AMateria("Cure_copy")
{
	*this = input;
}

Cure const & Cure::operator=(Cure const & rhs)
{
	if ( this != &rhs )
	{
		_type = rhs._type;
	}
	return ( *this );
}

Cure::~Cure(void)
{}

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
	target.incHP(power);
}
