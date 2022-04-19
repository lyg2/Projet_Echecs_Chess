#pragma once
/* Ce fichier est la classe Queen qui h�rite de Pi�ce.
* @file: Queen.cpp
* @authors: Gia-Sherwin Ly
* @matricule: 2137375
* @date:12 avril 2022
*/

#pragma warning(push, 0) // Sinon Qt fait des avertissements � /W4.
#include <QObject>
#include <QGraphicsPixmapItem>
#include <QGraphicsSceneMouseEvent>
#include <QString>
#include <iostream>
#include "Square.hpp"
#include "Piece.hpp"
#include "Queen.h"
#include "Board.hpp"
#pragma pop()
#include <functional>

bool Queen::validationMouvement(int posXApres, int posYApres) {
	//D�placement horizontale
	if ((abs(posXApres - getPosX()) >= 1) && (posYApres - getPosY()) == 0) {
		return true;
	}

	//D�placement verticale
	else if ((posXApres - getPosX() == 0) && (abs(posYApres - getPosY()) >= 1)) {
		return true;
	}
	//D�placement diagonale
	else if ((abs(posXApres - getPosX())) == (abs(posYApres - getPosY()))
		&& (abs(posXApres - getPosX())) != 0) {
		return true;
	}
	return false;
}

QString Queen::getNamePiece() {
	return QString::fromStdString(getPieceColor() + "Queen");
}