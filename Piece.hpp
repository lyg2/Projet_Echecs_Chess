#pragma once
// Le Modèle pour calculatrice simple.
// Par Francois-R.Boyer@PolyMtl.ca

#pragma warning(push, 0) // Sinon Qt fait des avertissements à /W4.
#include <QObject>
#include <QGraphicsPixmapItem>
#include <QGraphicsSceneMouseEvent>
#include "Square.hpp"
#include <list>
#pragma pop()
#include <functional>

using namespace std; // Dans ce cours on accepte le using namespace std dans le .hpp .

class Square;
class Piece
{
public:
	Piece() = default;
	virtual ~Piece() = default;
	virtual bool validationMouvement() = 0;
	/*bool ifMoved(int newPosX, int newPosY);
	bool eatPiece(int newPosX, int newPosY);*/
	int getPosX() const { return posX_; };
	int getPosY() const { return posY_; };
	void setPosX(int posX) { posX_ = posX; };
	void setPosY(int posY) { posY_ = posY; };
	string getName() const { return namePiece_; }
	void setPieceOnSquare(Square* square) {
		square = square;
	};
	Square* getSquare() {
		return square_;
	};

	void setPieceColor(string color) { color = color; };
	string getPieceColor() { return color_; };

	void setIsOnSquare(bool isOnSquare) {
		isOnSquare = isOnSquare;
	}
	bool getIsOnSquare() { return isOnSquare_; };

	list<Square*> getPossibleMove() {
		return possibleMoves_;
	};


	virtual void setPossibleMoves() = 0;

	virtual void movePiece(int i, int j) = 0;

private:
	int posX_;
	int posY_;
	string namePiece_;
	Square* square_;
	string color_;
	bool isOnSquare_;
	list<Square*> possibleMoves_;
};