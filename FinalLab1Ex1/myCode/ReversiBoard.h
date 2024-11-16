/*
 * @file ReversiBoard.h
 * @brief Declares the ReversiBoard class for the Reversi Board Game
 * Created on: 11 Nov 2024
 * Author: Abhinav Kumaar Krishna Kumar
 */

#ifndef REVERSIBOARD_H_
#define REVERSIBOARD_H_

/*
 * @class ReversiBoard
 *
 * @brief This class is a representation of the Reversi Board Game and its methods
 */
class ReversiBoard
{
public:

	/*
	 * @enum State
	 *
	 * @brief Enum represents the states of a cell on the Reversi Board
	 */
	typedef enum
		{
			Empty = 0, Player1 = 1, Player2 = 2
		} State;

private:

	/* Size of the Reversi Board */
	static const int BOARD_SIZE = 8;

	/* 2D array of State type to represent the Reversi Board */
	State board[BOARD_SIZE][BOARD_SIZE];

	/*
	 * @brief Checks if the position is valid for the current coordinates and player.
	 * Optionally flips the pieces if the move is valid and flip is set to true.
	 *
	 * @param int X                : [IN] The X Coordinate
	 * @param int Y                : [IN] The Y Coordinate
	 * @param State currentPlayer  : [IN] The current player's state
	 * @param bool flip            : [IN] If true, flips the pieces if the move is valid
	 *
	 * @return True if the position is a valid move for the player; otherwise false
	 */
	bool isValidMove(int X, int Y,
				State currentPlayer, bool flip = false);
public:

	/*
	 * @brief Default constructor which initializes the Reversi Board
	 *
	 * @attention The constructor assigns all the elements of the Reversi Board
	 * to the empty state and sets the initial four pieces for Player1 and Player2.
	 */
	ReversiBoard();

    /*
	 * @brief Returns the state of the cell at the specified coordinates.
	 *
	 * @param int X 				: [IN] The X Coordinate
	 * @param int Y  				: [IN] The Y Coordinate
	 *
	 * @return The state of the cell at the specified coordinates if they are within bounds; otherwise, undefined.
	 */
	State queryState(int X, int Y) const;

	/*
	 * @brief Sets the state of the cell for the entered coordinates if the move is valid.
	 * If the move is valid, it also flips the opponent's pieces accordingly.
	 *
	 * @param int X  				: [IN] The input X Coordinate
	 * @param int Y  				: [IN] The input Y Coordinate
	 * @param State currentPlayer 	: [IN] The current player's state
	 *
	 * @return True if the position is valid and the move was made; otherwise false.
	 */
	bool setFieldState(int X, int Y, State currentPlayer);

	/*
	 * @brief Checks if there are any valid moves available for the specified player.
     *
	 * @param State currentPlayer : [IN] The current player's state
	 *
	 * @return True if there are valid moves available for the player; otherwise false.
	 */
	bool hasAvailableMoves(State player);

	/*
	 * @brief Destructor (no dynamic memory allocation, so no specific cleanup required)
	 */
	~ReversiBoard();
};

#endif /* REVERSIBOARD_H_ */
