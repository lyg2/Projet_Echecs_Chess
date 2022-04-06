#pragma once
// Le Modèle pour calculatrice simple.
// Par Francois-R.Boyer@PolyMtl.ca

#pragma warning(push, 0) // Sinon Qt fait des avertissements à /W4.
#include <QObject>
#include <QGraphicsPixmapItem>
#include <QGraphicsSceneMouseEvent>
#include "Square.hpp"
#pragma pop()
#include <functional>

using namespace std; // Dans ce cours on accepte le using namespace std dans le .hpp .

class Square;
class Piece : public QGraphicsPixmapItem
{
public:
	Piece(QString colorPlayer = "", QGraphicsItem* parent = 0);
	void mouseSelectEvent(QGraphicsSceneMouseEvent* event);

	void setPieceOnSquare(Square* square) {
		square_ = square;
	};
	Square* getSquare() {
		return square_;
	};

	void setPieceColor(QString color) { color_ = color; };
	QString getPieceColor() { return color_; };

	void setIsOnSquare(bool isOnSquare) {
		isOnSquare_ = isOnSquare;
	}
	bool getIsOnSquare() { return isOnSquare_; };

	QList<Square*> getPossibleMove() {
		return possibleMoves_;
	};
	virtual void setPossibleMoves();

	virtual void movePiece();
private:
	Square* square_;
	QString color_;
	bool isOnSquare_;
	QList<Square*> possibleMoves_;
};