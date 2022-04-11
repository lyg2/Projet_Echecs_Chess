#pragma once
// Le Mod�le pour calculatrice simple.
// Par Francois-R.Boyer@PolyMtl.ca

#pragma warning(push, 0) // Sinon Qt fait des avertissements � /W4.
#include <QObject>
#include <QGraphicsPixmapItem>
#include <QGraphicsSceneMouseEvent>
#include "Square.hpp"
#include "Piece.hpp"
#include "King.hpp"
#include "Board.hpp"
#pragma pop()
#include <functional>



void King::setPossibleMoves(int i, int j) {
	Piece piece;
	Board board;

	for (int i = -1; i <= 1; i++) {
		for (int j = -1; j <= 1; j++) {
			int movePosX = board.field_[piece.getPosX() + i][j];
			int movePosY = board.field_[i][piece.getPosY() + j];
			int movePosXY = board.field_[piece.getPosX() + i][piece.getPosY() + j];
			(piece.possibleMoves_).push_back(movePosX);
			(piece.possibleMoves_).push_back(movePosY);
			(piece.possibleMoves_).push_back(movePosXY);
		}
	}
}

void King::movePiece(int i, int j) {
	Piece piece;
	Board board;
	if (i != 0) {
		int nextPosX = board.field_[piece.getPosX() + i][j];
	}
	else if (j != 0) {
		int nextPosY = board.field_[i][piece.getPosY() + j];
	}
	else if (i != 0 && j != 0) {
		int nextPosXY = board.field_[piece.getPosX() + i][piece.getPosY() + j];
	}

}
