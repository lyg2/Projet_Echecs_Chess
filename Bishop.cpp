#pragma once
// Le Mod�le pour calculatrice simple.
// Par Francois-R.Boyer@PolyMtl.ca

#pragma warning(push, 0) // Sinon Qt fait des avertissements � /W4.
#include <QObject>
#include <QGraphicsPixmapItem>
#include <QGraphicsSceneMouseEvent>
#include <iostream>
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

//void Bishop::movePiece(int i, int j) {
//	piece* piece;
//	board board;
//	if (i != 0 && j != 0) {
//	int nextposxy = board.field_[piece.getposx() + i][piece.getposy() + j];
//	}
//}

bool Bishop::validationMouvement(int posXApres, int posYApres) {
	//D�placement diagonale
	if ((abs(posXApres - getPosX()))==(abs(posYApres - getPosY()))
		&& (abs(posXApres - getPosX()))!=0) {
	return true;
	}
	return false;
}