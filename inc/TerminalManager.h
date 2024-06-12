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

extern struct termios *newTerminalG;
extern struct termios *oldTerminalG;

int		myGetch(void);
void	initTerminal(void);
void	getchTerminal(void);
void	restoreTerminal(void);
void	freeTerminal(void);

void	clearLine(int row);
void	clearOutput(void);

void	moveCursor(int row, int col);

void	drawBoxDoubleLine(int row, int col, int height, int width);
void	drawBoxSingleLine(int row, int col, int height, int width);
void	drawBoxRandom(int row, int col, int height, int width, const char *ul, const char * ur, const char * dl, const char * dr, const char * btb, const char * blr);

void	signalHandler(int sign);

#endif
