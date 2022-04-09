#pragma once
// Le Modèle pour calculatrice simple.
// Par Francois-R.Boyer@PolyMtl.ca

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