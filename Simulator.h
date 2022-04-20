#pragma once
/* Ce fichier est la classe Simulator qui permet de simuler le mouvement d'une pièce et de la remettre à sa position initiale à sa destruction
* @file: Simulator.cpp
* @authors: Gia-Sherwin Ly
* @matricule: 2137375
* @date:12 avril 2022
*/
#include "Piece.hpp"
#include "Board.hpp"
#include "Square.hpp"

class Simulator {
public:
	Simulator(Piece* piece, shared_ptr<Square> field[8][8], int tempPosX, int tempPosY);
	~Simulator();
	shared_ptr<Square> simulateField[8][8];
private:
	
	Piece* piece_;
	Piece* enemyPiece_;
	int tempPosX_;
	int tempPosY_;
	int savedPosX_;
	int savedPosY_;
};
//void Board::simulateNextPosition(Piece* piece, int nextPosX, int nextPosY)
//piece->setSavedPosX(piece->getPosX());
//	piece->setSavedPosY(piece->getPosY());
//
//	piece->setPosX(nextPosX);
//	piece->setPosY(nextPosY);
//	field_[nextPosX][nextPosY]->putPieceOnSquare(piece);
//	field_[piece->getSavedPosX()][piece->getSavedPosY()]->putPieceOnSquare(nullptr);

//field_[piece->getSavedPosX()][piece->getSavedPosY()]->putPieceOnSquare(piece);
//field_[piece->getPosX()][piece->getPosY()]->putPieceOnSquare(nullptr);
//piece->setPosX(piece->getSavedPosX());
//piece->setPosY(piece->getSavedPosY());