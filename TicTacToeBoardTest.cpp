/**
 * Unit Tests for TicTacToeBoard
**/

#include <gtest/gtest.h>
#include "TicTacToeBoard.h"
 
class TicTacToeBoardTest : public ::testing::Test
{
	protected:
		TicTacToeBoardTest(){} //constructor runs before each test
		virtual ~TicTacToeBoardTest(){} //destructor cleans up after tests
		virtual void SetUp(){} //sets up before each test (after constructor)
		virtual void TearDown(){} //clean up after each test, (before destructor) 
};

/* EXAMPLE TEST FORMAT
TEST(TicTacToeBoardTest, unitTestName)
{
	ASSERT_TRUE(true);
}
*/

TEST(TicTacToeBoardTest, Oturn) {
	TicTacToeBoard board;
	Piece piece = board.toggleTurn();
	ASSERT_EQ(piece, O);
}

TEST(TicTacToeBoardTest, Xturn) {
	TicTacToeBoard board;
	Piece piece = board.toggleTurn();
	piece = board.toggleTurn();
	ASSERT_EQ(piece, X);
}

TEST(TicTacToeBoardTest, placeX) {
	TicTacToeBoard board;
	Piece piece = board.placePiece(0,0);
	ASSERT_EQ(piece, X);
}

TEST(TicTacToeBoardTest, placeXAndSwitchTurn) {
	TicTacToeBoard board;
	board.placePiece(0,0);
	Piece piece = board.toggleTurn();
	ASSERT_EQ(piece, X);
}

TEST(TicTacToeBoardTest, placeO) {
	TicTacToeBoard board;
	board.toggleTurn();
	Piece piece = board.placePiece(0,0);
	ASSERT_EQ(piece, O);
}

TEST(TicTacToeBoardTest, placeOAndSwitchTurn) {
	TicTacToeBoard board;
	board.toggleTurn();
	board.placePiece(0,0);
	Piece piece = board.toggleTurn();
	ASSERT_EQ(piece, O);
}

TEST(TicTacToeBoardTest, notAllowedToPlace) {
	TicTacToeBoard board;
	board.placePiece(0,0);
	Piece piece = board.placePiece(0,0);
	ASSERT_EQ(piece, X);
}

TEST(TicTacToeBoardTest, outOfBoundsRowNegative) {
	TicTacToeBoard board;
	Piece piece = board.placePiece(-1, 0);
	ASSERT_EQ(piece, Invalid);
}

TEST(TicTacToeBoardTest, outOfBoundsColumnNegative) {
	TicTacToeBoard board;
	Piece piece = board.placePiece(0, -1);
	ASSERT_EQ(piece, Invalid);
}

TEST(TicTacToeBoardTest, outOfBoundsRowPositive) {
	TicTacToeBoard board;
	Piece piece = board.placePiece(3, 0);
	ASSERT_EQ(piece, Invalid);
}

TEST(TicTacToeBoardTest, outOfBoundsColumnPositive) {
	TicTacToeBoard board;
	Piece piece = board.placePiece(0, 3);
	ASSERT_EQ(piece, Invalid);
}

TEST(TicTacToeBoardTest, findingOutOfBoundsRowNegative) {
	TicTacToeBoard board;
	Piece piece = board.getPiece(-1, 0);
	ASSERT_EQ(piece, Invalid);
}

TEST(TicTacToeBoardTest, findingOutOfBoundsColumnNegative) {
	TicTacToeBoard board;
	Piece piece = board.getPiece(0, -1);
	ASSERT_EQ(piece, Invalid);
}

TEST(TicTacToeBoardTest, findingOutOfBoundsRowPositive) {
	TicTacToeBoard board;
	Piece piece = board.getPiece(3, 0);
	ASSERT_EQ(piece, Invalid);
}

TEST(TicTacToeBoardTest, findingOutOfBoundsColumnPositive) {
	TicTacToeBoard board;
	Piece piece = board.getPiece(0, 3);
	ASSERT_EQ(piece, Invalid);
}

TEST(TicTacToeBoardTest, findingBlank) {
	TicTacToeBoard board;
	Piece piece = board.getPiece(0, 0);
	ASSERT_EQ(piece, Blank);
}

TEST(TicTacToeBoardTest, findingX) {
	TicTacToeBoard board;
	board.placePiece(0,0);
	Piece piece = board.getPiece(0, 0);
	ASSERT_EQ(piece, X);
}

TEST(TicTacToeBoardTest, findingO) {
	TicTacToeBoard board;
	board.toggleTurn();
	board.placePiece(0,0);
	Piece piece = board.getPiece(0, 0);
	ASSERT_EQ(piece, O);
}

TEST(TicTacToeBoardTest, WinningStraightFromFirstRowFirstColumn) {
	TicTacToeBoard board;
	board.placePiece(0,0);
	board.toggleTurn();
	board.placePiece(0,1);
	board.toggleTurn();
	board.placePiece(0,2);
	Piece piece = board.getWinner();
	ASSERT_EQ(piece, X);
}

TEST(TicTacToeBoardTest, WinningDiagonalFromFirstRowFirstColumn) {
	TicTacToeBoard board;
	board.placePiece(0,0);
	board.toggleTurn();
	board.placePiece(1,1);
	board.toggleTurn();
	board.placePiece(2,2);
	Piece piece = board.getWinner();
	ASSERT_EQ(piece, X);
}

TEST(TicTacToeBoardTest, WinningDownFromFirstRowFirstColumn) {
	TicTacToeBoard board;
	board.placePiece(0,0);
	board.toggleTurn();
	board.placePiece(0,1);
	board.toggleTurn();
	board.placePiece(0,2);
	Piece piece = board.getWinner();
	ASSERT_EQ(piece, X);
}

TEST(TicTacToeBoardTest, WinningDownFromFirstRowSecondColumn) {
	TicTacToeBoard board;
	board.placePiece(0,1);
	board.toggleTurn();
	board.placePiece(1,1);
	board.toggleTurn();
	board.placePiece(2,1);
	Piece piece = board.getWinner();
	ASSERT_EQ(piece, X);
}

TEST(TicTacToeBoardTest, WinningDownFromFirstRowThirdColumn) {
	TicTacToeBoard board;
	board.placePiece(0,2);
	board.toggleTurn();
	board.placePiece(1,2);
	board.toggleTurn();
	board.placePiece(2,2);
	Piece piece = board.getWinner();
	ASSERT_EQ(piece, X);
}

TEST(TicTacToeBoardTest, WinningStraightFromSecondRowFirstColumn) {
	TicTacToeBoard board;
	board.placePiece(1,0);
	board.toggleTurn();
	board.placePiece(1,1);
	board.toggleTurn();
	board.placePiece(1,2);
	Piece piece = board.getWinner();
	ASSERT_EQ(piece, X);
}

TEST(TicTacToeBoardTest, WinningStraightFromThirdRowFirstColumn) {
	TicTacToeBoard board;
	board.placePiece(2,0);
	board.toggleTurn();
	board.placePiece(2,1);
	board.toggleTurn();
	board.placePiece(2,2);
	Piece piece = board.getWinner();
	ASSERT_EQ(piece, X);
}

TEST(TicTacToeBoardTest, GameStillGoing) {
	TicTacToeBoard board;
	board.placePiece(2,0);
	board.placePiece(2,1);
	board.placePiece(2,2);
	Piece piece = board.getWinner();
	ASSERT_EQ(piece, Invalid);
}

TEST(TicTacToeBoardTest, CatsGame) {
	TicTacToeBoard board;
	board.placePiece(0,0);
	board.placePiece(0,1);
	board.placePiece(0,2);
	board.placePiece(1,0);
	board.toggleTurn();
	board.placePiece(1,1);
	board.placePiece(1,2);
	board.toggleTurn();
	board.placePiece(2,0);
	board.toggleTurn();
	board.placePiece(2,1);
	board.placePiece(2,2);
	Piece piece = board.getWinner();
	ASSERT_EQ(piece, Blank);
}

TEST(TicTacToeBoardTest, PlacePiece) {
	TicTacToeBoard board;
	board.placePiece(0,0);
	board.placePiece(0,1);
	board.placePiece(0,2);
	board.placePiece(1,0);
	board.toggleTurn();
	board.placePiece(1,1);
	board.placePiece(1,2);
	board.toggleTurn();
	board.placePiece(2,0);
	board.toggleTurn();
	board.placePiece(2,1);
	board.placePiece(2,2);
	Piece piece = board.placePiece(2,2);
	ASSERT_EQ(piece, Invalid);
}
