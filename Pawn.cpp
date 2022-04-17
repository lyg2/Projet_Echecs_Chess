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
#include "Pawn.h"
#include "Board.hpp"
#pragma pop()
#include <functional>

using namespace std; // Dans ce cours on accepte le using namespace std dans le .hpp .

bool Pawn::validationMouvement(int posXApres, int posYApres) {

	if (getPieceColor() == "White") {
		//Déplacement de 2 cases verticale
		if (posXApres-getPosX() ==0 
			&& (posYApres - getPosY()==-1 || posYApres - getPosY() == -2)
			&& getPosY()==6)
		{
			return true;
		}
		else if (posXApres - getPosX() == 0 && posYApres - getPosY() == -1)
		{
			return true;
		}
		else if ((abs(posXApres - getPosX())) == 1 && posYApres - getPosY() == -1)
		{
			return true;
		}

	}

	else {
		if (posXApres - getPosX() == 0
			&& (posYApres - getPosY() == 1 || posYApres - getPosY() == 2)
			&& getPosY() == 1)
		{
			return true;
		}
		else if (posXApres - getPosX() == 0 && posYApres - getPosY() == 1)
		{
			return true;
		}
		else if ((abs(posXApres - getPosX())) == 1 && posYApres - getPosY() == 1)
		{
			return true;
		}
	}
	return false;
}

QString Pawn::getNamePiece() {
	return QString::fromStdString(getPieceColor() + "Pawn");
}