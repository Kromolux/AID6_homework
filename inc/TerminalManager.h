/*!	\file
	\brief Defines macros and functions for terminal management and text-based graphics.

	This header file provides macros for various graphical characters and symbols,
	as well as functions to handle terminal input and output operations.
*/

#pragma once
#ifndef TERMINALMANAGER_H
# define TERMINALMANAGER_H

# include <stdlib.h>
# include <termios.h>
# include <cstdio>
# include <signal.h>
# include "colors.h"

// Box Drawing Characters
# define HLINE "─"
# define VLINE "│"
# define TL "┌"  // Top Left
# define TR "┐"  // Top Right
# define BL "└"  // Bottom Left
# define BR "┘"  // Bottom Right
# define VL "├"  // Vertical and Left
# define VR "┤"  // Vertical and Right
# define TH "┬"  // Top and Horizontal
# define BH "┴"  // Bottom and Horizontal
# define VH "┼"  // Vertical and Horizontal
# define DHLINE "═"  // Double Horizontal
# define DVLINE "║"  // Double Vertical
# define DTL "╔"  // Double Top Left
# define DTR "╗"  // Double Top Right
# define DBL "╚"  // Double Bottom Left
# define DBR "╝"  // Double Bottom Right

// Block Elements
# define FULL "█"
# define DARK "▓"
# define MEDIUM "▒"
# define LIGHT "░"

// Geometric Shapes
# define BSQ "■"  // Black Square
# define WSQ "□"  // White Square
# define BUT "▲"  // Black Up-Pointing Triangle
# define WUT "△"  // White Up-Pointing Triangle
# define BDT "▼"  // Black Down-Pointing Triangle
# define WDT "▽"  // White Down-Pointing Triangle
# define BDI "◆"  // Black Diamond
# define WDI "◇"  // White Diamond
# define BCIR "●"  // Black Circle
# define WCIR "○"  // White Circle

// Arrows
# define LARROW "←"
# define UARROW "↑"
# define RARROW "→"
# define DARROW "↓"
# define LRARROW "↔"
# define UDARROW "↕"

// Mathematical Symbols
# define PM "±"  // Plus-Minus
# define MUL "×"  // Multiplication
# define DIV "÷"  // Division
# define SQRT "√"  // Square Root
# define INF "∞"  // Infinity
# define AEQ "≈"  // Almost Equal
# define NEQ "≠"  // Not Equal

// Miscellaneous Symbols
# define BSTAR "★"  // Black Star
# define WSTAR "☆"  // White Star
# define CHECK "✓"  // Check Mark
# define CROSS "✗"  // Ballot X
# define SUN "☀"  // Black Sun with Rays
# define UMB "☂"  // Umbrella
# define SNOW "☃"  // Snowman
# define COFFEE "☕"  // Hot Beverage
# define SWORD "⚔" //(U+2694): Crossed Swords
# define BSPS "♠" //(U+2660): Black Spade Suit
# define BCLS "♣" //(U+2663): Black Club Suit
# define BHES "♥" //(U+2665): Black Heart Suit
# define BDIS "♦" //(U+2666): Black Diamond Suit

// Non printable Special Symbols
# define ENTER '\n'
# define BACKSPACE '\b'
# define SPACEBAR ' '
# define LF '\n'

# ifndef DEBUG
#  define DEBUG 0
# endif

extern struct termios *newTerminalG;	/*!< Pointer to the new terminal settings */
extern struct termios *oldTerminalG;	/*!< Pointer to the old terminal settings */

/*!	\brief Gets a single character from the terminal without echo.

	\return The character read.
*/
int		myGetch(void);

/*!	\brief Initializes the terminal settings for raw input.
*/
void	initTerminal(void);

/*!	\brief Sets the terminal to raw input mode for getch.
*/
void	getchTerminal(void);

/*!	\brief Restores the terminal settings to their original state.
*/
void	restoreTerminal(void);

/*!	\brief Frees the allocated terminal settings.
*/
void	freeTerminal(void);

/*!	\brief Clears the specified line in the terminal.
	\param row The row to clear.
*/
void	clearLine(int row);

/*!	\brief Clears the terminal output.
*/
void	clearOutput(void);

/*!	\brief Moves the cursor to the specified position.

	\param row The row to move to.
	\param col The column to move to.
*/
void	moveCursor(int row, int col);

/*!	\brief Draws a box with double lines at the specified position and dimensions.

	\param row The starting row of the box.
	\param col The starting column of the box.
	\param height The height of the box.
	\param width The width of the box.
*/
void	drawBoxDoubleLine(int row, int col, int height, int width);

/*!	\brief Draws a box with single lines at the specified position and dimensions.

	\param row The starting row of the box.
	\param col The starting column of the box.
	\param height The height of the box.
	\param width The width of the box.
*/
void	drawBoxSingleLine(int row, int col, int height, int width);

/*!	\brief Draws a box with custom characters at the specified position and dimensions.

	\param row The starting row of the box.
	\param col The starting column of the box.
	\param height The height of the box.
	\param width The width of the box.
	\param ul The character for the upper-left corner.
	\param ur The character for the upper-right corner.
	\param dl The character for the lower-left corner.
	\param dr The character for the lower-right corner.
	\param btb The character for the top and bottom borders.
	\param blr The character for the left and right borders.
*/
void	drawBoxRandom(int row, int col, int height, int width, const char *ul, const char * ur, const char * dl, const char * dr, const char * btb, const char * blr);

/*!	\brief Handles signals sent to the terminal.

	This function is designed to handle various signals sent to the terminal. It is typically
	used to clean up or reset the terminal state when the application receives an interrupt
	signal (such as SIGINT). This can help ensure that the terminal is left in a consistent
	state even if the application is interrupted.

	\param sign The signal number that was received.
*/
void	signalHandler(int sign);

#endif
