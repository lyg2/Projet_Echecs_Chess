#pragma once
/* Ce fichier est la classe Rook qui hérite de Pièce.
* @file: Bishop.cpp
* @authors: Gia-Sherwin Ly, Fatima Mellata, Maroua Ouhib
* @matricule: 2137375, 2147725, 2154712
* @date:12 avril 2022
*/

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

QString Rook::getNamePiece() {
	return QString::fromStdString(getPieceColor() + "Rook");
}