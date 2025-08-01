#pragma once
/* Ce fichier est la classe Queen qui h�rite de Pi�ce.
* @file: Queen.h
* @authors: Gia-Sherwin Ly
* @matricule: 2137375
* @date:12 avril 2022
*/

#pragma warning(push, 0) // Sinon Qt fait des avertissements � /W4.
#include <QObject>
#include <QGraphicsPixmapItem>
#include <QGraphicsSceneMouseEvent>
#include "Square.hpp"
#include "Piece.hpp"
#pragma pop()
#include <functional>

using namespace std; // Dans ce cours on accepte le using namespace std dans le .hpp .

class Square;

class Queen : public Piece
{
public:
	Queen() = default;
	virtual ~Queen() = default;
	bool validationMouvement(int posXApres, int posYApres) override;
	QString getNamePiece() override;

};

