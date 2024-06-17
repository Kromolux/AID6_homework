/*! \file

	@brief Defines macros for terminal text colors and styles.
*/

/*!	\brief This header file provides macros for setting various text colors and styles
		 in the terminal using ANSI escape codes.
*/

#ifndef COLORS_H
# define COLORS_H

/*!	\brief Resets the text color to default.
	\def RESET
*/
# define RESET "\033[0m"

/*!	\brief Sets the text color to black.
	\def BLACK
*/
# define BLACK "\033[30m"

/*!	\brief Sets the text color to red.
	\def RED
*/
# define RED "\033[31m"

/*!	\brief Sets the text color to green.
	\def GREEN
*/
# define GREEN "\033[32m"

/*!	\brief Sets the text color to yellow.
	\def YELLOW
*/
# define YELLOW "\033[33m"

/*!	\brief Sets the text color to blue.
	\def BLUE
*/
# define BLUE "\033[34m"

/*!	\brief Sets the text color to magenta.
	\def MAGENTA
*/
# define MAGENTA "\033[35m"

/*!	\brief Sets the text color to cyan.
	\def CYAN
*/
# define CYAN "\033[36m"

/*!	\brief Sets the text color to white.
	\def WHITE
*/
# define WHITE "\033[37m"

/*!	\brief Sets the text color to bold black.
	\def BOLDBLACK
*/
# define BOLDBLACK "\033[1m\033[30m"

/*!	\brief Sets the text color to bold red.
	\def BOLDRED
*/
# define BOLDRED "\033[1m\033[31m"

/*!	\brief Sets the text color to bold green.
	\def BOLDGREEN
*/
# define BOLDGREEN "\033[1m\033[32m"

/*!	\brief Sets the text color to bold yellow.
	\def BOLDYELLOW
*/
# define BOLDYELLOW "\033[1m\033[33m"

/*!	\brief Sets the text color to bold blue.
	\def BOLDBLUE
*/
# define BOLDBLUE "\033[1m\033[34m"

/*!	\brief Sets the text color to bold magenta.
	\def BOLDMAGENTA
*/
# define BOLDMAGENTA "\033[1m\033[35m"

/*!	\brief Sets the text color to bold cyan.
	\def BOLDCYAN
*/
# define BOLDCYAN "\033[1m\033[36m"

/*!	\brief Sets the text color to bold white.
	\def BOLDWHITE
*/
# define BOLDWHITE "\033[1m\033[37m"

#endif
