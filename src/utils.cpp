/*! \file

	@brief Definition of the utils functions.
 */

/* Implementation of the Helperfunctions.*/

#include "../inc/utils.h"

int	getDigits(const int sides)
{
	long int tmp = sides;
	int	digits = 1;

	if (sides < 0)
		tmp *= -1;
	
	while (tmp > 9)
		tmp /= 10;

	return (digits);
}
