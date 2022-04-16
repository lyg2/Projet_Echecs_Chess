#pragma once
// Le Modèle pour calculatrice simple.
// Par Francois-R.Boyer@PolyMtl.ca

#pragma warning(push, 0) // Sinon Qt fait des avertissements à /W4.
#include <QObject>
#include <QGraphicsRectItem>
#include <QBrush>
#include <QGraphicsSceneMouseEvent>
#include "Piece.hpp"
#pragma pop()
#include <functional>

using namespace std; // Dans ce cours on accepte le using namespace std dans le .hpp .

class Piece;
class Square{

public:
	//Attribute to remember old color
	Square() = default;
	
	void setCaseColor(string caseColor) {
		caseColor_ = caseColor;
	};
	bool getHasPiece() { return hasPiece_; };
	void setHasPiece(bool possession)
	{
		hasPiece_ = possession;
	};
	
	Piece* getPiece() {
		return piece_;
	};
	void putPieceOnSquare(Piece* piece) {
		piece_=piece;
	};

	void setPositionX(int positionX) {
		positionX_ = positionX; };
	void setPositionY(int positionY) {
		positionY_ = positionY;};

	int getPositionX() { return positionX_; };
	int getPositionY() { return positionY_; };

private:
	bool hasPiece_;
	QBrush brush;
	string caseColor_;
	Piece* piece_=nullptr;
	int positionX_;
	int positionY_;

};
