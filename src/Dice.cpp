/*! \file

	@brief Definition of the class Dice for handling Dices in the game.
 */

/* Implementation of the Dice class */


#include "../inc/Dice.hpp"

Dice::Dice( const int sides, const int bonus ) : _sides( sides ), _bonus( bonus ), _lastRoll( 0 )
{
	_sideDigits = getDigits(sides);
}

Dice::Dice( const Dice & copy ) : _sides( copy._sides ), _bonus( copy._bonus ), _lastRoll( copy._lastRoll )
{}

Dice::~Dice( void )
{}


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

int	Dice::getSides( void ) const
{
	return ( _sides );
}

void	Dice::setSides( const int sides )
{
	if (sides > 0)
	{
		_sides = sides;
	}
}

int		Dice::getBonus( void ) const
{
	return ( _bonus );
}

void	Dice::setBonus( const int bonus )
{
	_bonus = bonus;
}

int	Dice::roll( void )
{
	_lastRoll = ( std::rand( ) % _sides ) + 1 + _bonus;
	return ( _lastRoll );
}

int	Dice::getLastRoll( void ) const
{
	return ( _lastRoll );
}

