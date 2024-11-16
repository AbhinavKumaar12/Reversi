/*
 * @file ReversiConsoleView.h
 * @brief Declares the ReversiConsoleView class for displaying the Reversi game board in the console
 * Created on: 11 Nov 2024
 * Author: Abhinav Kumaar Krishna Kumar
 */

#ifndef REVERSICONSOLEVIEW_H_
#define REVERSICONSOLEVIEW_H_

#include "ReversiBoard.h"

/*
 * @class ReversiConsoleView
 * @brief This class provides a console-based visual representation of the Reversi Board game.
 * It is responsible for printing the board's current state and displaying player moves.
 */
class ReversiConsoleView
{
private:

	/* Size of the Reversi board */
	static const int BOARD_SIZE = 8;

	/* Pointer to a ReversiBoard object, which holds the game state */
	const ReversiBoard *rboard;

public:

	/*
	 * @brief Parameterized Constructor for initializing ReversiConsoleView with a ReversiBoard
	 *
	 * @param rB : [IN] Pointer to a ReversiBoard object that contains the current game state.
	 *             This allows the view to access and display the board.
	 */
	ReversiConsoleView(const ReversiBoard *rB);

	/*
	 * @brief Prints the current state of the Reversi Board to the console.
	 *        Displays the board grid with symbols for empty cells and player pieces.
	 */
	void printBoard() const;

	/*
	 * @brief Destructor (no dynamic memory cleanup needed)
	 */
	~ReversiConsoleView();
};

#endif /* REVERSICONSOLEVIEW_H_ */
