#pragma once
// Le Modèle pour calculatrice simple.
// Par Francois-R.Boyer@PolyMtl.ca

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

class King : public Piece
{
public:
	King() { count_++; };
	~King() { count_--; };
	static int getCount() { return count_; };
	void setPossibleMoves() override;
	bool validationMouvement(int posXApres, int posYApres) override;
	QString getNamePiece() override;
private:
	static int count_;

};

