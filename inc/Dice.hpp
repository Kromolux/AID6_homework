#ifndef DICE_HPP
# define DICE_HPP

# include <stdlib.h>
# include "utils.h"

class Dice
{
protected:
	int	_sides;
	int	_bonus;
	int	_lastRoll;
	int	_sideDigits;

public:
	// Constructor that initializes the number of sides (default to 6) and seeds the random number generator
	Dice( const int sides = 6, const int bonus = 0 );
	// Copy-Constructor
	Dice( const Dice & copy );
	// Deconstructor
	~Dice( void );

	// Assignment Operator
	Dice	&	operator=( const Dice & rhs );

	// Method to roll the dice and return the result
	int		roll( void );

	// Method to get the value of the last roll
	int		getLastRoll( void ) const;

	// Method to set the number of sides (if you want to change it after creation)
	void	setSides( const int sides );

	// Method to get the number of sides
	int		getSides( void ) const;

	void	setBonus( const int bonus );
	int		getBonus( void ) const;

};

#endif