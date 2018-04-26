#include "GameBoard.h"

void processGameBoard(const GameBoard& board)
{
	const GamePiece& piece = board.at(0, 0);

	// Doesn't compile
	//board.at(1, 2) = piece;
}

int main()
{
	GameBoard board(10, 10);
	GamePiece piece;

	board.at(0, 0) = piece;
	board.at(0, 1) = board.at(0, 0);

	GameBoard board2;
	board2 = board;

	processGameBoard(board2);

	return 0;
}
