/* Ce fichier est de tester les fonctionnalités de la logique du jeu.
* @file: TestModele.cpp
* @authors: Gia-Sherwin Ly
* @matricule: 2137375
* @date:12 avril 2022
*/

//#include "Chess.hpp"
//#include "Rook.hpp"
//#include "King.hpp"
//#include "Bishop.hpp"
//#include "Game.hpp"
//
#if __has_include("gtest/gtest.h")
#include "gtest/gtest.h"
#endif
#ifdef TEST
//
//TEST(Rook, simple) {
//	Rook rook;
//	rook.setPossibleMoves(-1, 0);
//	rook.setPossibleMoves(0, -1);
//	rook.setPossibleMoves(1, 0);
//	rook.setPossibleMoves(0, 1);
//	rook.setPossibleMoves(0, 0);
//	//EXPECT_EQ(calc.obtenirValeur(), 143);
//	rook.movePiece(-1, 0);
//	rook.movePiece(0, -1);
//	rook.movePiece(1, 0);
//	rook.movePiece(0, 1);
//	rook.movePiece(0, 0);
//	//EXPECT_EQ(calc.obtenirValeur(), 218);
//}
//
//TEST(King, simple) {
//	King king;
//	king.setPossibleMoves(-1, 0);
//	king.setPossibleMoves(0, -1);
//	king.setPossibleMoves(1, 0);
//	king.setPossibleMoves(0, 1);
//	king.setPossibleMoves(0, 0);
//	king.setPossibleMoves(-1, -1);
//	king.setPossibleMoves(-1, 1);
//	king.setPossibleMoves(1, 1);
//	king.setPossibleMoves(1, -1);
//	//EXPECT_EQ(calc.obtenirValeur(), 143);
//	king.movePiece(-1, 0);
//	king.movePiece(0, -1);
//	king.movePiece(1, 0);
//	king.movePiece(0, 1);
//	king.movePiece(0, 0);
//	king.movePiece(-1, -1);
//	king.movePiece(-1, 1);
//	king.movePiece(1, 1);
//	king.movePiece(1, -1);
//	//EXPECT_EQ(calc.obtenirValeur(), 218);
//}
//
//TEST(Bishop, simple) {
//	Bishop bishop;
//	bishop.setPossibleMoves(0, 0);
//	bishop.setPossibleMoves(-1, -1);
//	bishop.setPossibleMoves(-1, 1);
//	bishop.setPossibleMoves(1, 1);
//	bishop.setPossibleMoves(1, -1);
//	//EXPECT_EQ(calc.obtenirValeur(), 143);
//	bishop.movePiece(0, 0);
//	bishop.movePiece(-1, -1);
//	bishop.movePiece(-1, 1);
//	bishop.movePiece(1, 1);
//	bishop.movePiece(1, -1);
//	//EXPECT_EQ(calc.obtenirValeur(), 218);
//}
//
//TEST(Calc, operations) {
//	Calc calc;
//	calc.ajouterChiffre(1);
//	calc.ajouterChiffre(4);
//	calc.ajouterChiffre(3);
//	calc.operationPlus();
//	calc.ajouterChiffre(2);
//	calc.ajouterChiffre(1);
//	calc.ajouterChiffre(8);
//	calc.operationEgal();
//	EXPECT_EQ(calc.obtenirValeur(), 143+218);
//	calc.ajouterChiffre(1);
//	calc.ajouterChiffre(4);
//	calc.ajouterChiffre(3);
//	calc.operationMoins();
//	calc.ajouterChiffre(2);
//	calc.ajouterChiffre(1);
//	calc.ajouterChiffre(8);
//	calc.operationEgal();
//	EXPECT_EQ(calc.obtenirValeur(), 143-218);
//}
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
