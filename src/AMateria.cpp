#include "../inc/AMateria.hpp"

AMateria::AMateria(std::string const & type)
{
	this->_type = type;
}

AMateria::AMateria(AMateria const & input)
{
	*this = input;
}

AMateria const & AMateria::operator=(AMateria const & input)
{
	this->_type = input._type;
	return (*this);
}

AMateria::~AMateria(void)
{}

std::string	const & AMateria::getType(void) const
{
	return (this->_type);
}

void	AMateria::use(Character & target, const int & power)
{
	(void) target;
	(void) power;
}
