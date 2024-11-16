/*
 * @file main.cpp
 * @brief Main program for an 8x8 Reversi Board game
 * Created on: 11 Nov 2024
 * Author: Abhinav Kumaar Krishna Kumar
 *
 * Initializes the Board game and the console view. Players take turns to make moves,
 * and the game continues until no valid moves are possible for both players.
 * Displays the current state of the board after each turn.
 * Supports two players and a simple console interface.
 *
 * @return 0 upon successful completion
 */

#include <iostream>
#include <cstdlib>

using namespace std;

// Include Reversi Board and Console View headers
#include "ReversiBoard.h"
#include "ReversiConsoleView.h"

// Main program
int main()
{
	cout << "REVERSI BOARD GAME" << endl;

	// Initialize the game board and the console view
	ReversiBoard game;
	ReversiConsoleView view(&game);

	int X, Y;

	// Player 1 starts the game
	ReversiBoard::State currentPlayer = ReversiBoard::Player1;

	while (true)
	{
		// Display the current board state
		view.printBoard();
		cout << "Current player = Player" << (currentPlayer == ReversiBoard::Player1 ? "1" : "2") << endl;

		// Check if the current player has any valid moves
		if (game.hasAvailableMoves(currentPlayer))
		{
			cout << "Enter coordinates (X Y) for your move (0-7): ";
			cin >> X >> Y;

			// Attempt to place the current player's piece at the specified coordinates
			bool operationSuccessful = game.setFieldState(X, Y, currentPlayer);

			if (operationSuccessful)
			{
				// Switch to the other player only if the move was successful
				currentPlayer = (currentPlayer == ReversiBoard::Player1) ? ReversiBoard::Player2 : ReversiBoard::Player1;
			}
			else
			{
				// Inform the player if the move was invalid
				cout << "Invalid coordinates or move! Please try again (coordinates should be between 0 and 7)." << endl;
			}
		}
		else
		{
			// No valid moves are available for the current player
			cout << "No more moves available for Player" << (currentPlayer == ReversiBoard::Player1 ? "1" : "2") << "." << endl;
			break;  // Exit the game loop
		}
	}

	cout << "Game over! Thank you for playing." << endl;
	return 0;
}
