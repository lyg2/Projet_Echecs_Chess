#pragma once
// Le Modèle pour calculatrice simple.
// Par Francois-R.Boyer@PolyMtl.ca

#pragma warning(push, 0) // Sinon Qt fait des avertissements à /W4.
#include <QObject>
#include <QGraphicsPixmapItem>
#include <QGraphicsSceneMouseEvent>
#include "Square.hpp"
#include "Piece.hpp"
#include "Bishop.hpp"
#include "Board.hpp"
#pragma pop()
#include <functional>

using namespace std; // Dans ce cours on accepte le using namespace std dans le .hpp .

void Bishop::setPossibleMoves() {
	/*Piece* piece;
	Board board;

	for (int i = -1; i <= 1; i++) {
		for (int j = -1; j <= 1; j++) {
			int movePosXY = board.field_[piece.getPosX() + i][piece.getPosY() + j];
			(piece.possibleMoves_).push_back(movePosXY);
		}
	}*/
}

void Bishop::movePiece(int i, int j) {
	/*Piece* piece;
	Board board;
	if (i != 0 && j != 0) {
	int nextPosXY = board.field_[piece.getPosX() + i][piece.getPosY() + j];
	}*/
}

bool Bishop::validationMouvement() {
	return false;
}