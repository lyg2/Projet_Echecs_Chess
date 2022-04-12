#pragma once
/* Ce fichier est la classe Pièce.
* @file: Bishop.cpp
* @authors: Gia-Sherwin Ly, Fatima Mellata, Maroua Ouhib
* @matricule: 2137375, 2147725, 2154712
* @date:12 avril 2022
*/

#pragma warning(push, 0) // Sinon Qt fait des avertissements à /W4.
#include <QObject>
#include <QGraphicsPixmapItem>
#include <QGraphicsSceneMouseEvent>
#include "Square.hpp"
#include "Piece.hpp"
#include "King.hpp"
#pragma pop()
#include <functional>

//bool Piece::ifMoved(int newPosX, int newPosY) {
//	return true;
//}
//
//bool Piece::eatPiece(int newPosX, int newPosY)
//{
//	return true;
//}