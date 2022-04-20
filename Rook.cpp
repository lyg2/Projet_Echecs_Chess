#pragma once
/* Ce fichier est l'impl�mentation de la classe Rook.
* @file: Rook.cpp
* @authors: Gia-Sherwin Ly
* @matricule: 2137375
* @date:12 avril 2022
*/

#pragma warning(push, 0) // Sinon Qt fait des avertissements � /W4.
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
	//D�placement horizontale
	if ((abs(posXApres - getPosX()) >= 1) && (posYApres - getPosY()) == 0) {
		return true;
	}

	//D�placement verticale
	else if ((posXApres - getPosX() == 0) && (abs(posYApres - getPosY()) >= 1)) {
		return true;
	}
	return false;
}

QString Rook::getNamePiece() {
	return QString::fromStdString(getPieceColor() + "Rook");
}