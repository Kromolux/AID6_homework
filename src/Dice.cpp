#include "../inc/Dice.hpp"

// Constructor
Dice::Dice( const int sides, const int bonus ) : _sides( sides ), _bonus( bonus ), _lastRoll( 0 )
{
	_sideDigits = getDigits(sides);
}

// Copy-Constructor
Dice::Dice( const Dice & copy ) : _sides( copy._sides ), _bonus( copy._bonus ), _lastRoll( copy._lastRoll )
{}

// Deconstructor
Dice::~Dice( void )
{}


// Assignment Operator
Dice	&	Dice::operator=( const Dice & rhs )
{
	if ( this != &rhs )
	{
		_sides = rhs._sides;
		_bonus = rhs._bonus;
		_lastRoll = rhs._lastRoll;
	}
	return ( *this );
}

// Method to roll the dice and return the result
int	Dice::roll( void )
{
	_lastRoll = ( std::rand( ) % _sides ) + 1 + _bonus;
	return ( _lastRoll );
}

// Method to get the value of the last roll
int	Dice::getLastRoll( void ) const
{
	return ( _lastRoll );
}

// Method to set the number of sides (if you want to change it after creation)
void	Dice::setSides( const int sides )
{
	if (sides > 0)
	{
		_sides = sides;
	}
}

// Method to get the number of sides
int	Dice::getSides( void ) const
{
	return ( _sides );
}

void	Dice::setBonus( const int bonus )
{
	_bonus = bonus;
}

int		Dice::getBonus( void ) const
{
	return ( _bonus );
}
