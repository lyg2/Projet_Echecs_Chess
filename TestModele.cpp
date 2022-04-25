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
//
#if __has_include("gtest/gtest.h")
#include "gtest/gtest.h"
#endif
#ifdef TEST
//
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
	EXPECT_EQ(modele.getBoard()->getFieldSquare(0, 3)->getPiece()->getNamePiece(), "WhiteQueen");
	modele.setHasSelectedPiece(true);
	EXPECT_EQ(modele.getHasSelectedPiece(), true);

	modele.setSelectedPiece(modele.getBoard()->getFieldSquare(0, 3)->getPiece());
	EXPECT_EQ(modele.getSelectedPiece(), modele.getBoard()->getFieldSquare(0, 3)->getPiece());
	EXPECT_EQ(modele.getBoard()->isValidMove(modele.getSelectedPiece(), 1, 2), true);
	modele.getBoard()->movePieceOnBoard(modele.getSelectedPiece(), 1, 2);
	EXPECT_EQ(modele.getSelectedPiece()->getPosX(), 1);
	EXPECT_EQ(modele.getSelectedPiece()->getPosY(), 2);

	modele.setSelectedPiece(modele.getBoard()->getFieldSquare(1, 0)->getPiece());
	EXPECT_EQ(modele.getSelectedPiece(), modele.getBoard()->getFieldSquare(1, 0)->getPiece());
	EXPECT_EQ(modele.getBoard()->isValidMove(modele.getSelectedPiece(), 0, 0), true);
	modele.getBoard()->movePieceOnBoard(modele.getSelectedPiece(), 0, 0);
	EXPECT_EQ(modele.getSelectedPiece()->getPosX(), 0);
	EXPECT_EQ(modele.getSelectedPiece()->getPosY(), 0);

	modele.setSelectedPiece(modele.getBoard()->getFieldSquare(1, 2)->getPiece());
	EXPECT_EQ(modele.getSelectedPiece(), modele.getBoard()->getFieldSquare(1, 2)->getPiece());
	EXPECT_EQ(modele.getBoard()->isValidMove(modele.getSelectedPiece(), 1, 1), true);
	modele.getBoard()->movePieceOnBoard(modele.getSelectedPiece(), 1, 1);
	EXPECT_EQ(modele.getSelectedPiece()->getPosX(), 1);
	EXPECT_EQ(modele.getSelectedPiece()->getPosY(), 1);

	EXPECT_EQ(modele.getBoard()->isCheckmate("White"), true);
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
//TEST(Calc, changement_operation) {
//	Calc calc;
//	calc.ajouterChiffre(1);
//	calc.ajouterChiffre(4);
//	calc.ajouterChiffre(3);
//	calc.operationPlus();
//	calc.operationMoins();
//	calc.ajouterChiffre(2);
//	calc.ajouterChiffre(1);
//	calc.ajouterChiffre(8);
//	calc.operationEgal();
//	EXPECT_EQ(calc.obtenirValeur(), 143-218);
//	calc.ajouterChiffre(1);
//	calc.ajouterChiffre(4);
//	calc.ajouterChiffre(3);
//	calc.operationMoins();
//	calc.operationPlus();
//	calc.ajouterChiffre(2);
//	calc.ajouterChiffre(1);
//	calc.ajouterChiffre(8);
//	calc.operationEgal();
//	EXPECT_EQ(calc.obtenirValeur(), 143+218);
//}
//
#endif
