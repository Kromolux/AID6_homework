/*!	\file

	\brief Declaration of the Game class responsible for managing the game logic and characters.
*/

/*!	\class Game
	\brief Manages the game logic and characters.

	The Game class is responsible for managing the game's main logic, including turns,
	character creation, enemy management, and user interface interactions.
*/

#ifndef GAME_HPP
# define GAME_HPP

# include "Character.hpp"
# include <ctime>
# include <iostream>

# include "../inc/Dice.hpp"
# include "../inc/AMateria.hpp"
# include "../inc/Meditate.hpp"
# include "../inc/Icebolt.hpp"
# include "../inc/Cure.hpp"
# include "../inc/TerminalManager.h"

# define MAXNAMECHARS 19
# define STATSROW 12
# define STATSCOL 3

/*!	\brief Enumeration representing different types of enemies.

	\enum e_enemy
*/
typedef enum e_enemy
{
	SKELETON_FROSTMAGE,			/*!< Skeleton frost mage */
	SKELETON_HEALER,			/*!< Skeleton healer */
	SKELETON_NECROMANCER		/*!< Skeleton necromancer */
}			 t_enemy;


class Game
{
protected:
	bool _Playerturn;			/*!< Flag indicating if it's the player's turn */

	Character *_gameMap[10];	/*!< Array representing the game map */

	int	_terminalRow;			/*!< Terminal row for output printf */
	int	_terminalCol;			/*!< Terminal column for output printf */
	int	_terminalMaxRow;		/*!< Maximum terminal row */

public:
	// Constructors:
	/*!	\brief Default constructor for the Game class.

		Initializes the Game class with the default parameters.
	*/
	Game(void);

	/*!	\brief Deconstructor.

		Cleans up resources allocated for Game object
	*/
	~Game(void);

	/*!	\brief Initializes a new game.
	*/
	void	initNewGame(void);

	/*!	\brief Enters the game loop.
	*/
	void	gameLoop(void);

	/*!	\brief Executes the enemy's turn.
	*/
	void	enemyTurn(void);

	/*!	\brief Executes the player's turn.
	*/
	void	playerTurn(void);

	/*!	\brief Displays a bar representing character statistics.

		\param size The size of the bar.
		\param current The current value of the statistic.
		\param change The change in the statistic.
		\param max The maximum value of the statistic.
		\param color The color of the bar.
	*/
	void	displayBar(int size, int current, int change, int max, const char * color);

	/*!	\brief Displays all entities on the game map.
	*/
	void	displayAllEntites(void);

	/*!	\brief Displays an entity at the specified position on the game map.

		\param col The column position.
		\param row The row position.
		\param idx The index of the entity.
	*/
	void	displayEntity(int col, int row, int idx);

	/*!	\brief Creates a new player character.

		\param idx The index of the player.
	*/
	void	createNewPlayer(int idx);

	/*!	\brief Creates a new enemy character.

		\param idx The index of the enemy.
		\param enemyNr The type of enemy to create.
	*/
	void	createNewEnemy(int idx, t_enemy enemyNr);

	/*!	\brief Checks if the enemy is dead.

		\return True if the enemy is dead, false otherwise.
	*/
	bool	isEnemyDead(void);

	/*!	\brief Restores action points for the Characters.
	*/
	void	restoreAP(void);

	/*!	\brief Gets the status text corresponding to a status number.

		\param statusNr The status number.
		\return The status text.
	*/
	std::string	getStatusText(t_status statusNr);

	/*!	\brief Gets the player character pointer.

		\return A pointer to the player character.
	*/
	Character * getPlayer(void);

	/*!	\brief Gets the result of a dice roll for a character.

		\param user The character rolling the dice.
		\param MPSpend The amount of mana points spent. Zero means the spell costs no mana
		\return The result of the dice roll.
	*/
	int		getDiceResult(Character * user, const int MPSpend);
};

#endif