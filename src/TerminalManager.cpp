/*! \file

	@brief Definition of the TerminalManager functions.
 */

/* Implementation of the TerminalManager functions.*/

#include "../inc/TerminalManager.h"

struct termios *newTerminalG = NULL;
struct termios *oldTerminalG = NULL;

int		myGetch(void)
{
	int	buffer = 0;

	fflush(stdout);
	getchTerminal();
	read(STDIN_FILENO, &buffer, 4);		// read first int 4 bytes to get control chars too
	fflush(stdin);						// empty keyboard buffer
	restoreTerminal();

	return (buffer);
}

void	initTerminal(void)
{
	newTerminalG = (termios *) malloc(sizeof(termios));
	oldTerminalG = (termios *) malloc(sizeof(termios));

	tcgetattr(STDIN_FILENO, oldTerminalG);				// get terminal settings
	*newTerminalG = *oldTerminalG;						// clone terminal settings
	newTerminalG->c_lflag &= ~ICANON;					// set non-canonical mode
	newTerminalG->c_lflag &= ~ECHO;						// disable echo
}

void	getchTerminal(void)
{
	tcsetattr(STDIN_FILENO, TCSANOW, newTerminalG);		// set terminal settings
}

void	restoreTerminal(void)
{
	if (oldTerminalG)
		tcsetattr(STDIN_FILENO, TCSADRAIN, oldTerminalG);
}

void	freeTerminal(void)
{
	free(newTerminalG);
	free(oldTerminalG);
}

void	clearLine(int const row)
{
	printf("\033[%d;2H", row);
	//fflush(stdin);
	printf("\033[K");
	moveCursor(row, 80);
	printf("║");
}

// clears the game output lines row 17 to ro 23 col 2 
void	clearOutput(void)
{
	for (int i = 17; i < 24; ++i)
	{
		printf("\033[%d;2H", i);
		printf("\033[K");
		moveCursor(i, 80);
		printf("║");
	}
}

// sets the cursor to the position row, col in the terminal
void	moveCursor(int const row, int const col)
{
	printf("\033[%d;%dH", row, col);
	fflush(stdout);
}

void	drawBoxDoubleLine(int row, int col, int height, int width)
{
	drawBoxRandom(row, col, height, width, "╔", "╗", "╚", "╝", "║", "═");
}

void	drawBoxSingleLine(int row, int col, int height, int width)
{
	drawBoxRandom(row, col, height, width, "┌", "┐", "└", "┘", "│", "─");
}

void	drawBoxRandom(int row, int col, int height, int width, const char *ul, const char * ur, const char * dl, const char * dr, const char * btb, const char * blr)
{
	// draw top line with corners
	moveCursor(row, col);
	printf("%s", ul);
	for (int i = 1; i < width - 1; ++i)
		printf("%s", blr);
	printf("%s", ur);

	// draw bottom line with corners
	moveCursor(row + height - 1, col);
	printf("%s", dl);
	for (int i = 1; i < width - 1; ++i)
		printf("%s", blr);
	printf("%s", dr);

	// draw left and right lines
	for (int i = 1; i < height - 1; ++i)
	{
		moveCursor(row + i, col);
		printf("%s", btb);
		moveCursor(row + i, col + width - 1);
		printf("%s", btb);
	}
}


void	signalHandler(int sign)
{
	(void) sign;
	printf(RED "\n***signal handler called! Game aborted.***\n" RESET);
	restoreTerminal();
	exit(-1);
}

void	pressAnyKey(int const row)
{
	printf("=> Press any key *\b");
	myGetch();
	clearLine(row);
}
