#pragma once
/* Ce fichier est l'implémentation de classe Bishop
* @file: Bishop.cpp
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
#include "Bishop.hpp"
#include "Board.hpp"
#pragma pop()
#include <functional>

using namespace std; // Dans ce cours on accepte le using namespace std dans le .hpp .

bool Bishop::validationMouvement(int posXApres, int posYApres) {
	//Déplacement diagonale
	if ((abs(posXApres - getPosX()))==(abs(posYApres - getPosY()))
		&& (abs(posXApres - getPosX()))!=0) {
	return true;
	}
	return false;
}

QString Bishop::getNamePiece() {
	return QString::fromStdString(getPieceColor()+"Bishop");
}