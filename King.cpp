#pragma once
/* Ce fichier est la classe King qui h�rite de Pi�ce.
* @file: Bishop.cpp
* @authors: Gia-Sherwin Ly, Fatima Mellata, Maroua Ouhib
* @matricule: 2137375, 2147725, 2154712
* @date:12 avril 2022
*/

#pragma warning(push, 0) // Sinon Qt fait des avertissements � /W4.
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

int King::count_ = 0;

bool King::validationMouvement(int posXApres, int posYApres) {
	//D�placement horizontale
	if ((abs(posXApres - getPosX()) == 1) && (posYApres - getPosY()) == 0) {
		return true;
	}

	//D�placement verticale
	else if ((posXApres - getPosX() == 0) && (abs(posYApres - getPosY()) == 1)) {
		return true;
	}

	//D�placement diagonale
	else if ((abs(posXApres - getPosX()) == 1) && (abs(posYApres - getPosY())) == 1) {
		return true;
	}
	return false;
}

QString King::getNamePiece() {
	return QString::fromStdString(getPieceColor()+"King");
}
