/*
 * @file ReversiConsoleView.cpp
 * @brief Implementation of the ReversiConsoleView class for displaying the Reversi Board game
 * Created on: 11 Nov 2024
 * Author: Abhinav Kumaar Krishna Kumar
 */

#include "ReversiConsoleView.h"
#include <iostream>

/*
 * @brief Parameterized Constructor for initializing ReversiConsoleView with a ReversiBoard.
 *
 * @param rB : [IN] Pointer to a ReversiBoard object that holds the game state.
 *             This allows the view to access and display the board state.
 */
ReversiConsoleView::ReversiConsoleView(const ReversiBoard *rB)
{
	rboard = rB;
}

/*
 * @brief Prints the current state of the Reversi Board to the console.
 *        Displays '*' for empty cells, 'X' for Player 1's pieces, and 'O' for Player 2's pieces.
 */
void ReversiConsoleView::printBoard() const
{
	char output;
	for (int i = 0; i < BOARD_SIZE; i++)
	{
		for (int j = 0; j < BOARD_SIZE; j++)
		{
			switch (rboard->queryState(i, j))
			{
			case ReversiBoard::Empty:
				output = '*';  // Empty cells represented by '*'
				break;
			case ReversiBoard::Player1:
				output = 'X';  // Player 1's pieces represented by 'X'
				break;
			case ReversiBoard::Player2:
				output = 'O';  // Player 2's pieces represented by 'O'
				break;
			default:
				output = '*';
				break;
			}

			std::cout << output << " ";
		}
		std::cout << std::endl;
	}
}

/*
 * @brief Destructor (no dynamic memory cleanup required)
 */
ReversiConsoleView::~ReversiConsoleView()
{
}
