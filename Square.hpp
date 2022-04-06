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
class Square:public QGraphicsRectItem {

public:
	//Attribute to remember old color
	Square(QGraphicsItem* parent=0);
	~Square();
	void mouseSelectEvent(QGraphicsSceneMouseEvent* event);
	void setColor(QColor color) {
		caseColor_ = color;
	}; //??
	
	void setCaseColor(QColor caseColor) {
		caseColor_ = caseColor;
	}; //??
	bool getHasPiece() { return hasPiece_; };
	void setHasPiece(bool possession, Piece* piece = 0)
	{
		hasPiece_ = possession;
		piece_ = piece;
	};

	QString getPieceColor() { return pieceColor_; };
	void setPieceColor(QString pieceColor) {
		pieceColor_ = pieceColor;
	};
	
	Piece* getPiece() {
		return piece_;
	};
	void putPieceOnSquare(Piece* piece) {
		piece_=piece;
	};

	void setPositionRow(int positionRow) {
		positionRow_ = positionRow; };
	void setPositionColumn(int positionColumn) {
		positionColumn_ = positionColumn;};

	int getPositionRow() { return positionRow_; };
	int getPositionColumn() { return positionColumn_; };

private:
	bool hasPiece_;
	QBrush brush;
	QString pieceColor_;
	QColor caseColor_;
	Piece* piece_;
	int positionRow_;
	int positionColumn_;

};
