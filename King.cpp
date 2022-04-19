#pragma once
/* Ce fichier est la classe King qui hérite de Pièce.
* @file: King.cpp
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
#pragma pop()
#include <functional>

int King::count_ = 0;

King:: King() {
	if (count_ >= 2) {
		throw logic_error("Trying to instanciate more than two Kings\n");
	}
	count_++;
}
King:: ~King() 
{ 
	count_--;
}

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

QString King::getNamePiece() {
	return QString::fromStdString(getPieceColor()+"King");
}
