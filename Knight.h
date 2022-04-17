#pragma once
// Le Mod�le pour calculatrice simple.
// Par Francois-R.Boyer@PolyMtl.ca

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

using namespace std; // Dans ce cours on accepte le using namespace std dans le .hpp .

class Knight : public Piece {
public:
	Knight() = default;
	virtual ~Knight() = default;
	bool validationMouvement(int posXApres, int posYApres) override;
	QString getNamePiece() override;

};
