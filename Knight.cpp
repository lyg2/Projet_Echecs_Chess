#pragma once
/* Ce fichier est la classe Bishop qui hérite de Pièce.
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
#include "Knight.h"
#include "Board.hpp"
#pragma pop()
#include <functional>

using namespace std; // Dans ce cours on accepte le using namespace std dans le .hpp .

bool Knight::validationMouvement(int posXApres, int posYApres) {
	
	int width = 1;
	int length = 2;

	if ((abs(posXApres - getPosX()))==length && (abs(posYApres - getPosY()))==width) {
		return true;
	}
	else if ((abs(posXApres - getPosX())) == width && (abs(posYApres - getPosY())) == length) {
		return true;
	}
	return false;
}

QString Knight::getNamePiece() {
	return QString::fromStdString(getPieceColor() + "Knight");
}