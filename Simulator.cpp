#pragma once
/* Ce fichier est la classe King qui hérite de Pièce.
* @file: Bishop.cpp
* @authors: Gia-Sherwin Ly, Fatima Mellata, Maroua Ouhib
* @matricule: 2137375, 2147725, 2154712
* @date:12 avril 2022
*/

#pragma warning(push, 0) // Sinon Qt fait des avertissements à /W4.
#include <QObject>
#include <QGraphicsPixmapItem>
#include <QGraphicsSceneMouseEvent>
#include <iostream>
#include "Square.hpp"
#include "Piece.hpp"
#include "King.hpp"
#include "Board.hpp"
#include "Simulator.h"
#pragma pop()
#include <functional>

Simulator::Simulator(Piece* piece, shared_ptr<Square> field[8][8], int  tempPosX, int tempPosY) {
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			simulateField[i][j] = field[i][j];
		}
	}
	savedPosX_ = piece->getPosX();
	savedPosY_ = piece->getPosY();
	tempPosX_ = tempPosX;
	tempPosY_ = tempPosY;
	piece_ = piece;
	piece->setPosX(tempPosX);
	piece->setPosY(tempPosY);

	simulateField[tempPosX][tempPosY]->putPieceOnSquare(piece);
	simulateField[savedPosX_][savedPosY_]->putPieceOnSquare(nullptr);
}
Simulator:: ~Simulator() {
	//field_[piece->getSavedPosX()][piece->getSavedPosY()]->putPieceOnSquare(piece);
//field_[piece->getPosX()][piece->getPosY()]->putPieceOnSquare(nullptr);
//piece->setPosX(piece->getSavedPosX());
//piece->setPosY(piece->getSavedPosY());
	simulateField[savedPosX_][savedPosY_]->putPieceOnSquare(piece_);
	simulateField[tempPosX_][tempPosY_]->putPieceOnSquare(nullptr);
	piece_->setPosX(savedPosX_);
	piece_->setPosY(savedPosY_);
}