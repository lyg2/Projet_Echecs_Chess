/* Ce fichier est de tester les fonctionnalités de la logique du jeu.
* @file: TestModele.cpp
* @authors: Gia-Sherwin Ly
* @matricule: 2137375
* @date:12 avril 2022
*/

#include "Bishop.hpp"
#include "Board.hpp"
#include "Game.hpp"
#include "King.hpp"
#include "Knight.h"
#include "Movement.h"
#include "Piece.hpp"
#include "Queen.h"
#include "Rook.hpp"
#include "Simulator.h"
#include "Square.hpp"
#include <filesystem>

//On doit changer le répertoire de travail dans google test adapter en $(SolutionDir), sinon les fichiers ne vont pas être trouvés.
#if __has_include("gtest/gtest.h")
#include "gtest/gtest.h"
#endif
#ifdef TEST

 
TEST(Philidor, simple) {
	Modele::Game modele;
	Board* board = new Board;
	modele.setBoard(board);
	modele.getBoard()->drawBoard();
	modele.setIsNewGame(false);
	EXPECT_EQ(modele.getIsNewGame(), false);
	modele.getBoard()->loadChessGame("chessgame_files/philidor1777.txt");
	EXPECT_EQ(modele.getBoard()->isStalemate("White"), false);
	EXPECT_EQ(modele.getBoard()->isStalemate("Black"), false);
	modele.setIsYourTurn(true);
	EXPECT_EQ(modele.getIsYourTurn(), true);
	modele.setColorTurn("White");
	EXPECT_EQ(modele.getColorTurn(), "White");
	modele.setHasSelectedPiece(true);
	EXPECT_EQ(modele.getHasSelectedPiece(), true);

	modele.setSelectedPiece(modele.getBoard()->getFieldSquare(0, 3)->getPiece());
	EXPECT_EQ(modele.getSelectedPiece()->getNamePiece(), "WhiteQueen");
	EXPECT_EQ(modele.getSelectedPiece(), modele.getBoard()->getFieldSquare(0, 3)->getPiece());
	EXPECT_EQ(modele.getBoard()->isValidMove(modele.getSelectedPiece(), 1, 2), true);
	EXPECT_EQ(modele.getBoard()->isValidMove(modele.getSelectedPiece(), 1, 3), true);
	modele.getBoard()->movePieceOnBoard(modele.getSelectedPiece(), 1, 2);
	EXPECT_EQ(modele.getSelectedPiece()->getPosX(), 1);
	EXPECT_EQ(modele.getSelectedPiece()->getPosY(), 2);

	modele.setSelectedPiece(modele.getBoard()->getFieldSquare(1, 1)->getPiece());
	EXPECT_EQ(modele.getSelectedPiece()->getNamePiece(), "BlackRook");

	EXPECT_EQ(modele.getBoard()->isValidMove(modele.getSelectedPiece(), 0, 1), false);
	EXPECT_EQ(modele.getBoard()->isValidMove(modele.getSelectedPiece(), 2, 1), false);
	EXPECT_EQ(modele.getBoard()->isValidMove(modele.getSelectedPiece(), 1, 3), false);
	EXPECT_EQ(modele.getBoard()->isValidMove(modele.getSelectedPiece(), 1, 2), true);

	modele.setSelectedPiece(modele.getBoard()->getFieldSquare(1, 0)->getPiece());
	EXPECT_EQ(modele.getSelectedPiece()->getNamePiece(), "BlackKing");
	EXPECT_EQ(modele.getSelectedPiece(), modele.getBoard()->getFieldSquare(1, 0)->getPiece());
	EXPECT_EQ(modele.getBoard()->isValidMove(modele.getSelectedPiece(), 0, 0), true);
	modele.getBoard()->movePieceOnBoard(modele.getSelectedPiece(), 0, 0);
	EXPECT_EQ(modele.getSelectedPiece()->getPosX(), 0);
	EXPECT_EQ(modele.getSelectedPiece()->getPosY(), 0);

	modele.setSelectedPiece(modele.getBoard()->getFieldSquare(1, 2)->getPiece());
	EXPECT_EQ(modele.getSelectedPiece(), modele.getBoard()->getFieldSquare(1, 2)->getPiece());
	EXPECT_EQ(modele.getBoard()->isValidMove(modele.getSelectedPiece(), 1, 1), true);
	EXPECT_EQ(modele.getBoard()->isValidMove(modele.getSelectedPiece(), 2, 2), false);
	modele.getBoard()->movePieceOnBoard(modele.getSelectedPiece(), 1, 1);
	EXPECT_EQ(modele.getSelectedPiece()->getPosX(), 1);
	EXPECT_EQ(modele.getSelectedPiece()->getPosY(), 1);

	EXPECT_EQ(modele.getBoard()->isCheckmate("White"), true);
	EXPECT_EQ(modele.getBoard()->isCheckmate("Black"), false);
}
//
TEST(Stalemate, simple) {
	Modele::Game modele;
	Board* board = new Board;
	modele.setBoard(board);
	modele.getBoard()->drawBoard();
	modele.getBoard()->loadChessGame("chessgame_files/test_stalemate.txt");
	EXPECT_EQ(modele.getBoard()->isStalemate("White"), true);
	EXPECT_EQ(modele.getBoard()->isStalemate("Black"), false);

}
//
TEST(Knights, simple) {
	Modele::Game modele;
	Board* board = new Board;
	modele.setBoard(board);
	modele.getBoard()->drawBoard();
	modele.getBoard()->loadChessGame("chessgame_files/Knights_Of_The_Round_Table.txt");


	modele.setSelectedPiece(modele.getBoard()->getFieldSquare(6, 6)->getPiece());
	EXPECT_EQ(modele.getSelectedPiece()->getNamePiece(), "BlackKnight");
	EXPECT_EQ(modele.getSelectedPiece(), modele.getBoard()->getFieldSquare(6, 6)->getPiece());
	EXPECT_EQ(modele.getBoard()->isValidMove(modele.getSelectedPiece(), 4, 5), true);
	modele.getBoard()->movePieceOnBoard(modele.getSelectedPiece(), 4, 5);
	EXPECT_EQ(modele.getSelectedPiece()->getPosX(), 4);
	EXPECT_EQ(modele.getSelectedPiece()->getPosY(), 5);

	modele.setSelectedPiece(modele.getBoard()->getFieldSquare(3, 3)->getPiece());
	EXPECT_EQ(modele.getSelectedPiece(), modele.getBoard()->getFieldSquare(3, 3)->getPiece());
	EXPECT_EQ(modele.getBoard()->isValidMove(modele.getSelectedPiece(), 4, 5), true);
	modele.getBoard()->movePieceOnBoard(modele.getSelectedPiece(), 4, 5);
	EXPECT_EQ(modele.getSelectedPiece()->getPosX(), 4);
	EXPECT_EQ(modele.getSelectedPiece()->getPosY(), 5);
}
//
TEST(Bishops, simple) {
	Modele::Game modele;
	Board* board = new Board;
	modele.setBoard(board);
	modele.getBoard()->drawBoard();
	modele.getBoard()->loadChessGame("chessgame_files/Bishops.txt");
	
	modele.setSelectedPiece(modele.getBoard()->getFieldSquare(7, 0)->getPiece());
	EXPECT_EQ(modele.getSelectedPiece()->getNamePiece(), "WhiteBishop");
	EXPECT_EQ(modele.getSelectedPiece(), modele.getBoard()->getFieldSquare(7, 0)->getPiece());
	EXPECT_EQ(modele.getBoard()->isValidMove(modele.getSelectedPiece(), 0, 7), true);
	EXPECT_EQ(modele.getBoard()->isValidMove(modele.getSelectedPiece(), 3, 3), false);
	modele.getBoard()->movePieceOnBoard(modele.getSelectedPiece(), 0, 7);
	EXPECT_EQ(modele.getSelectedPiece()->getPosX(), 0);
	EXPECT_EQ(modele.getSelectedPiece()->getPosY(), 7);
}

TEST(Kings, simple) {
	Modele::Game modele;
	Board* board = new Board;
	modele.setBoard(board);
	modele.getBoard()->drawBoard();
	King* temp_piece=nullptr;
	try{
		modele.getBoard()->loadChessGame("chessgame_files/TD6_Q2_Too_many_kings.txt");
	}
	catch (logic_error& e) {
	}
	EXPECT_EQ(temp_piece->getCount(), 2);
	
}

TEST(Check_White_King, simple) {
	Modele::Game modele;
	Board* board = new Board;
	modele.setBoard(board);
	modele.getBoard()->drawBoard();
	modele.setIsNewGame(false);
	EXPECT_EQ(modele.getIsNewGame(), false);
	modele.getBoard()->loadChessGame("chessgame_files/philidor1777.txt");

	modele.setSelectedPiece(modele.getBoard()->getFieldSquare(1, 1)->getPiece());
	modele.getBoard()->movePieceOnBoard(modele.getSelectedPiece(), 2, 1);
	EXPECT_EQ(modele.getBoard()->isCheckmate("Black"), false);
}

#endif
