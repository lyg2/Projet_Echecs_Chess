/* Ce fichier est la classe Bishop qui hérite de Pièce.
* @file: Bishop.hpp
* @authors: Gia-Sherwin Ly
* @matricule: 2137375
* @date:12 avril 2022
*/
#pragma once
#pragma warning(push, 0) // Sinon Qt fait des avertissements à /W4.
#include <QObject>
#include <QGraphicsPixmapItem>
#include <QGraphicsSceneMouseEvent>
#include "Square.hpp"
#include "Piece.hpp"
#pragma pop()
#include <functional>

using namespace std; // Dans ce cours on accepte le using namespace std dans le .hpp .

class Square;


class Bishop : public Piece
{
public:
	Bishop() = default;
	bool validationMouvement(int posX, int posY) override;
	QString getNamePiece() override;

};
