#pragma once
/* Ce fichier est la classe Simulator qui hérite de Pièce.
* @file: Simulator.cpp
* @authors: Gia-Sherwin Ly
* @matricule: 2137375
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
	enemyPiece_ = simulateField[tempPosX][tempPosY]->getPiece();
	piece->setPosX(tempPosX);
	piece->setPosY(tempPosY);

	simulateField[tempPosX][tempPosY]->putPieceOnSquare(piece);
	simulateField[tempPosX][tempPosY]->setHasPiece(true);
	simulateField[savedPosX_][savedPosY_]->putPieceOnSquare(nullptr);
	simulateField[savedPosX_][savedPosY_]->setHasPiece(false);
}
Simulator:: ~Simulator() {
	simulateField[savedPosX_][savedPosY_]->putPieceOnSquare(piece_);
	simulateField[savedPosX_][savedPosY_]->setHasPiece(true);
	if (enemyPiece_!=nullptr){
		simulateField[tempPosX_][tempPosY_]->putPieceOnSquare(enemyPiece_);
		simulateField[tempPosX_][tempPosY_]->setHasPiece(true);
	}
	else {
		simulateField[tempPosX_][tempPosY_]->putPieceOnSquare(nullptr);
		simulateField[tempPosX_][tempPosY_]->setHasPiece(false);
	}
	piece_->setPosX(savedPosX_);
	piece_->setPosY(savedPosY_);
}