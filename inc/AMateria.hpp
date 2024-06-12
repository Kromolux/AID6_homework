#ifndef AMATERIA_HPP
# define AMATERIA_HPP
# include "Character.hpp"

class Character;

class AMateria
{

protected:
	std::string	_type;

public:

	AMateria( std::string const & type );
	AMateria( AMateria const & input );
	AMateria const & operator=( AMateria const & rhs );
	virtual ~AMateria( void );

	std::string const & getType( void ) const;

	virtual	AMateria *	clone( void ) const = 0;
	virtual void		use( Character & target, const int & power );

private:
	
	AMateria(void);
	
};

#endif