/*!	\file

	@brief Declaration of the class Dice for handling Dices in the game.
 */

/*!	\class Dice
	\brief Represents a Dice in the game, used for rolling a Dice - getting random numbers.
*/


#ifndef DICE_HPP
# define DICE_HPP

# include <stdlib.h>
# include "utils.h"

class Dice
{
protected:
	int	_sides;			/*!<The number of sides the dice has */
	int	_bonus;			/*!<The number of bonus added the rolled result */
	int	_lastRoll;		/*!<The result of the last roll */
	int	_sideDigits;	/*!<The number of sidedigits the dice has as sides*/

public:
	// Constructors:
	/*!	\brief Parameterized constructor. Used as default constructor too

		Initializes the number of sides (default to 6), number of bonus (default to 0) and
		the number of sidedigits.
		
		\param sides Number of sides the dice has. (default 6)
		\param bonus number of bonus the dice has. (defualt 0)
	*/
	Dice(const int sides = 6, const int bonus = 0);

	/*! \brief Copy constructor.

		Creates a copy of the given Dice object.
		\param copy The Dice object to be copied.
	*/
	Dice(const Dice & copy);

	/*!	\brief Deconstructor.

		Cleans up resources allocated for Dice objects
	*/
	~Dice(void);

	// Operators
	/*!	\brief Assignment operator.

		Assigns the variables of the given Dice object to the current object.

		\param rhs The Dice object on the right-hand side of the assignment.

		\return Reference to the current Dice object after assignment.
	*/
	Dice	&	operator=(const Dice & rhs);

	// set-ter and get-ter
	/*!	\brief Gets the the number of sides of the dice.

		\return number of _sides.
	*/
	int		getSides(void) const;

	/*!	\brief Sets the the number of sides of the dice.

		\param sides Number of new sides of the dice.
	*/
	void	setSides(const int sides);

	/*!	\brief Gets the the number of bonus of the dice.

		\return number of _bonus.
	*/
	int		getBonus(void) const;

	/*!	\brief Sets the the number of bonus of the dice.

		\param bonus Number of new bonus of the dice.
	*/
	void	setBonus(const int bonus);

	/*!	\brief Method to roll the dice and return the result

		\return number of the new _lastRoll.
	*/
	int		roll(void);

	/*!	\brief Method to get the value of the last roll

		\return number of _lastRoll.
	*/
	int		getLastRoll(void) const;
};

#endif
