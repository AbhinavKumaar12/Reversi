/*
 * @file ReversiBoard.cpp
 * @brief Implementation of the ReversiBoard class methods
 * Created on: 11 Nov 2024
 * Author: Abhinav Kumaar Krishna Kumar
 */
#include "ReversiBoard.h"

/*
 * @brief Default constructor which initializes the Reversi Board
 *
 * @attention The constructor assigns all the cells of the board
 * to an empty state and sets the initial four pieces in the center
 * for each player.
 */
ReversiBoard::ReversiBoard()
{
	for (int i = 0; i < BOARD_SIZE; i++)
	{
		for (int j = 0; j < BOARD_SIZE; j++)
		{
			board[i][j] = State::Empty;
		}
	}
    // Set initial pieces for both players at the center of the board
    board[3][3] = board[4][4] = State::Player1;
	board[3][4] = board[4][3] = State::Player2;
}

/*
 * @brief Checks if the move is valid for the current coordinates and player.
 * Optionally flips pieces if the move is valid and flip is set to true.
 *
 * @param int X                : [IN] The X Coordinate
 * @param int Y                : [IN] The Y Coordinate
 * @param State currentPlayer  : [IN] The current player's state
 * @param bool flip            : [IN] If true, flips the pieces if the move is valid
 *
 * @return True if the position is a valid move for the player; otherwise, false
 */
bool ReversiBoard::isValidMove(int X, int Y,
		State currentPlayer, bool flip)
{
	// Check if the move is within bounds and the cell is empty
	if (X < 0 || X >= BOARD_SIZE || Y < 0 || Y >= BOARD_SIZE
				|| board[X][Y] != State::Empty)
	{
		return false;
	}

	// Determine the opponent's state
	State opponent = (currentPlayer == Player1) ? Player2 : Player1;
	bool isMoveValid = false;

	// Possible directions for capturing opponent pieces
	const int coordinates[8][2] =
	{{ -1, -1 },
	{ -1, 0 },
	{ -1, 1 },
	{ 0, -1 },
	{ 0, 1 },
	{ 1, -1 },
	{ 1, 0 },
	{ 1, 1 } };

	for (int i = 0; i < 8; i++)  // Iterate over all 8 directions
	{
		int directionX = coordinates[i][0];
		int directionY = coordinates[i][1];

		int r = X + directionX;
		int c = Y + directionY;
		bool hasOpponentPiece = false;

		// Traverse in the current direction while encountering opponent pieces
		while (r >= 0 && r < BOARD_SIZE && c >= 0 && c < BOARD_SIZE && board[r][c] == opponent)
		{
			hasOpponentPiece = true;
		    r += directionX;
		    c += directionY;
		}

		// If a valid move is found, optionally flip the pieces if 'flip' is true
		if (hasOpponentPiece && r >= 0 && r < BOARD_SIZE && c >= 0 && c < BOARD_SIZE && board[r][c] == currentPlayer)
		{
			isMoveValid = true;
	        if (flip)
	        {
	        	r -= directionX;
	            c -= directionY;
		        while (r != X || c != Y)
		        {
		        	board[r][c] = currentPlayer;
		            r -= directionX;
		            c -= directionY;
		        }
	        }
		}
	}
	return isMoveValid;
}

/*
 * @brief Returns the state of the cell at the specified coordinates
 *
 * @param int X 				: [IN] The X Coordinate
 * @param int Y  				: [IN] The Y Coordinate
 *
 * @return The state of the cell at the specified coordinates if within bounds
 */
ReversiBoard::State ReversiBoard::queryState(int X, int Y) const
{
	return board[X][Y];
}

/*
 * @brief Sets the state of the cell at the specified coordinates if the move is valid.
 * If the move is valid, it also flips the opponent's pieces accordingly.
 *
 * @param int X  				: [IN] The input X Coordinate
 * @param int Y  				: [IN] The input Y Coordinate
 * @param State currentPlayer 	: [IN] The current player's state
 *
 * @return True if the position is valid and the move was made; otherwise, false.
 */
bool ReversiBoard::setFieldState(int X, int Y, State currentPlayer)
{
	if (isValidMove(X, Y, currentPlayer, true))
	{
		board[X][Y] = currentPlayer;
		return true;
	}
	return false;
}

/*
 * @brief Checks if there are any valid moves available for the specified player
 *
 * @param State currentPlayer : [IN] The current player's state
 *
 * @return True if there are valid moves available for the player; otherwise, false.
 */
bool ReversiBoard::hasAvailableMoves(State player)
{
	for (int i = 0; i < BOARD_SIZE; i++)
	{
		for (int j = 0; j < BOARD_SIZE; j++)
		{
			if (isValidMove(i, j, player))
			{
				return true;
			}
		}
	}
	return false;
}

/*
 * @brief Destructor (no dynamic memory allocation, so no specific cleanup required)
 */
ReversiBoard::~ReversiBoard()
{
}
