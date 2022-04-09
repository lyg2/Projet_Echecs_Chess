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
class Piece
{
public:
	Piece(QString colorPlayer = "", QGraphicsItem* parent = 0);
	void mouseSelectEvent(QGraphicsSceneMouseEvent* event);
	Piece() = default;
	virtual ~Piece() = default;
	virtual bool ifMoved(int newPosX, int newPosY) const = 0;
	virtual bool eatPiece(int newPosX, int newPosY) const = 0;
	int getPosX() const { return posX; }
	int getPosY() const { return posY; }
	string getName() const { return namePiece; }
	void setPieceOnSquare(Square* square) {
		square = square;
	};
	Square* getSquare() {
		return square;
	};

	void setPieceColor(QString color) { color = color; };
	QString getPieceColor() { return color; };

	void setIsOnSquare(bool isOnSquare) {
		isOnSquare = isOnSquare;
	}
	bool getIsOnSquare() { return isOnSquare; };

	QList<Square*> getPossibleMove() {
		return possibleMoves;
	};
	virtual void setPossibleMoves()=0;

	virtual void movePiece()=0;
private:
	int posX;
	int posY;
	string namePiece;
	Square* square;
	QString color;
	bool isOnSquare;
	QList<Square*> possibleMoves;
};