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
#include "Rook.hpp"
#include "Board.hpp"
#pragma pop()
#include <functional>

void Rook::setPossibleMoves() {
	/*Piece piece;
	Board board;

	for (int i = -1; i <= 1; i++) {
		for (int j = -1; j <= 1; j++) {
			int movePosX = board.field_[piece.getPosX() + i][j];
			int movePosY = board.field_[i][piece.getPosY() + j];
			(piece.possibleMoves_).push_back(movePosX);
			(piece.possibleMoves_).push_back(movePosY);
		}
	}*/
}

//void Rook::movePiece(int i, int j) {
//	piece piece;
//	board board;
//	if (i != 0) {
//		int nextposx = getfield[piece.getposx() + i][j];
//	}
//	else if (j != 0) {
//		int nextposy = board.field_[i][piece.getposy() + j];
//	}
//
//}

bool Rook::validationMouvement(int posXApres, int posYApres) {
	//Déplacement horizontale
	if ((abs(posXApres - getPosX()) >= 1) && (posYApres - getPosY()) == 0) {
		return true;
	}

	//Déplacement verticale
	else if ((posXApres - getPosX() == 0) && (abs(posYApres - getPosY()) >= 1)) {
		return true;
	}
	return false;
}