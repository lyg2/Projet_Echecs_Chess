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

class Queen : public Piece
{
public:
	Queen() = default;
	virtual ~Queen() = default;
	bool validationMouvement(int posXApres, int posYApres) override;
	QString getNamePiece() override;

};

