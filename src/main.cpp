/*! \file

	@brief The main function - entry point.
 */


#include "../inc/Game.hpp"

int	main(void)
{
	//init signal handler for ctl c to reset terminal settings
	signal(SIGINT, &signalHandler);

	//create game object
	Game MyGame;

	MyGame.initNewGame();
	MyGame.gameLoop();

	return (0);
}
