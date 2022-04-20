/* Ce fichier est la classe Knight qui hérite de pièce
* @file: Knight.h
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

using namespace std; // Dans ce cours on accepte le using namespace std dans le .hpp .

class Knight : public Piece {
public:
	Knight() = default;
	virtual ~Knight() = default;
	bool validationMouvement(int posXApres, int posYApres) override;
	QString getNamePiece() override;

};
