#ifndef MEDITATE_HPP
# define MEDITATE_HPP
# include <iostream>
# include "AMateria.hpp"
# include "Character.hpp"

class Meditate : public AMateria
{
public:

	Meditate( void );
	Meditate( std::string const & type );
	Meditate( Meditate const & input );
	Meditate const & operator=( Meditate const & rhs );
	~Meditate( void );

	std::string const & getType( void ) const;

	AMateria *	clone( void ) const;
	void		use( Character & target, const int & power );
};

#endif