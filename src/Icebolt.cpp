
#include "../inc/Icebolt.hpp"

Icebolt::Icebolt( void ) : AMateria( "Icebolt" )
{}

Icebolt::Icebolt( std::string const & type ) : AMateria( type )
{}

Icebolt::Icebolt( Icebolt const & input ) : AMateria( "Icebolt_copy" )
{
	*this = input;
}

Icebolt const & Icebolt::operator=( Icebolt const & rhs )
{
	if ( this != &rhs )
	{
		_type = rhs._type;
	}
	return ( *this );
}

Icebolt::~Icebolt( void )
{}

std::string const & Icebolt::getType( void ) const
{
	return ( this->_type );
}

AMateria *	Icebolt::clone( void ) const
{
	return (new Icebolt("Icebolt_clone"));
}

void	Icebolt::use(Character & target, const int & power)
{
	printf(BLUE " shoots an Icebolt <%i> at %s" RESET, power, target.getName().c_str());
	target.incHP(-1 * power);
}
