#ifndef ICEBOLT_HPP
# define ICEBOLT_HPP
# include <iostream>
# include "AMateria.hpp"
# include "Character.hpp"

class Icebolt : public AMateria
{
public:

	Icebolt( void );
	Icebolt( std::string const & type );
	Icebolt( Icebolt const & input );
	Icebolt const & operator=( Icebolt const & rhs );
	~Icebolt( void );

	std::string const & getType( void ) const;

	AMateria *	clone( void ) const;
	void		use( Character & target, const int & power );
};

#endif