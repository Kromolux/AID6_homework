#ifndef CURE_HPP
# define CURE_HPP
# include <iostream>
# include "AMateria.hpp"
# include "Character.hpp"

class Cure : public AMateria
{
public:

	Cure(void);
	Cure(std::string const & type);
	Cure(Cure const & input);
	Cure const & operator=(Cure const & input);
	~Cure(void);

	std::string const & getType(void) const;

	AMateria *	clone(void) const;
	void		use(Character & target, const int & power);
};

#endif