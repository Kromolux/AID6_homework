#include "../inc/Meditate.hpp"

Meditate::Meditate(void) : AMateria("Meditate")
{}

Meditate::Meditate(std::string const & type) : AMateria(type)
{}

Meditate::Meditate(Meditate const & input) : AMateria("Meditate_copy")
{
	*this = input;
}

Meditate const & Meditate::operator=(Meditate const & rhs)
{
	if ( this != &rhs )
	{
		_type = rhs._type;
	}
	return ( *this );
}

Meditate::~Meditate(void)
{}

std::string const & Meditate::getType(void) const
{
	return (this->_type);
}

AMateria *	Meditate::clone(void) const
{
	return (new Meditate("Meditate_clone"));
}

void	Meditate::use(Character & target, const int & power)
{
	//printf(GREEN " heals <%i> %s's wounds " RESET, power, target.getName().c_str());
	//target.incHP(power);
	printf(YELLOW " meditates and restores <%i> MP" RESET, power);
	target.incMP(power);
}
