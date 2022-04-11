#pragma once
// Le Modèle pour calculatrice simple.
// Par Francois-R.Boyer@PolyMtl.ca

#pragma warning(push, 0) // Sinon Qt fait des avertissements à /W4.
#include <QObject>
#include <QGraphicsPixmapItem>
#include <QGraphicsSceneMouseEvent>
#include "Square.hpp"
#include "Piece.hpp"
#include "King.hpp"
#include "Board.hpp"
#pragma pop()
#include <functional>



void King::setPossibleMoves() {
//
//	for (int i = -1; i <= 1; i++) {
//		for (int j = -1; j <= 1; j++) {
//			int movePosX = getPosX() + i;
//			int movePosY = getPosY() + j;
//			int movePosDiago = [getPosX() + i][getPosY() + j];
//			(piece.possibleMoves_).push_back(movePosX);
//			(piece.possibleMoves_).push_back(movePosY);
//			(piece.possibleMoves_).push_back(movePosXY);
//		}
//	}
}

void King::movePiece(int x1, int y1) {
//	Piece piece;
//	Board board;
//	if (i != 0) {
//		//int nextPosX = board.field_[piece.getPosX() + i][j];
//		int nextPosX = getField[piece.getPosX() + i];
//
//	}
//	else if (j != 0) {
//		int nextPosY = board.field_[i][piece.getPosY() + j];
//	}
//	else if (i != 0 && j != 0) {
//		int nextPosXY = board.field_[piece.getPosX() + i][piece.getPosY() + j];
//	}
//
}

bool King::validationMouvement() {
	return false;
}
