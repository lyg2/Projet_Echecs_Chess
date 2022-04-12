#pragma once
// Le Modèle pour calculatrice simple.
// Par Francois-R.Boyer@PolyMtl.ca

#pragma warning(push, 0) // Sinon Qt fait des avertissements à /W4.
#include <QObject>
#include <QGraphicsPixmapItem>
#include <QGraphicsSceneMouseEvent>
#include <iostream>
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

//void King::movePiece(int x1, int y1) {
//	piece piece;
//	board board;
//	if (i != 0) {
//		int nextposx = board.field_[piece.getposx() + i][j];
//		int nextposx = getfield[piece.getposx() + i];
//
//	}
//	else if (j != 0) {
//		int nextposy = board.field_[i][piece.getposy() + j];
//	}
//	else if (i != 0 && j != 0) {
//		int nextposxy = board.field_[piece.getposx() + i][piece.getposy() + j];
//	}
//
//}

bool King::validationMouvement(int posXApres, int posYApres) {
	//Déplacement horizontale
	if ((abs(posXApres - getPosX()) == 1) && (posYApres - getPosY()) == 0) {
		return true;
	}

	//Déplacement verticale
	else if ((posXApres - getPosX() == 0) && (abs(posYApres - getPosY()) == 1)) {
		return true;
	}

	//Déplacement diagonale
	else if ((abs(posXApres - getPosX()) == 1) && (abs(posYApres - getPosY())) == 1) {
		return true;
	}
	return false;
}
