﻿#pragma once
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
	virtual bool validationMouvement(int posXApres, int posYApres) = 0;
	virtual QString getNamePiece() = 0;
	/*bool ifMoved(int newPosX, int newPosY);
	bool eatPiece(int newPosX, int newPosY);*/
	int getPosX() const { return posX_; };
	int getPosY() const { return posY_; };
	void setPosX(int posX) { posX_ = posX; };
	void setPosY(int posY) { posY_ = posY; };
	int getSavedPosX() { return savedPosX_; };
	int getSavedPosY() { return savedPosY_; };
	void setSavedPosX(int savedPosX) {savedPosX_=savedPosX; };
	void setSavedPosY(int savedPosY) {savedPosY_ = savedPosY; };
	string getName() const { return namePiece_; }
	void setPieceOnSquare(Square* square) {
		square = square;
	};
	Square* getSquare() {
		return square_;
	};

	void setPieceColor(string color) { color_ = color; };
	string getPieceColor() { return color_; };
	void setIsOnSquare(bool isOnSquare) {
		isOnSquare = isOnSquare;
	}
	bool getIsOnSquare() { return isOnSquare_; };

	list<Square*> getPossibleMove() {
		return possibleMoves_;
	};


	virtual void setPossibleMoves() = 0;

	//virtual void movePiece(int i, int j) = 0;

private:
	int posX_;
	int posY_;
	int savedPosX_;
	int savedPosY_;
	string namePiece_;
	Square* square_;
	string color_;
	bool isOnSquare_;
	list<Square*> possibleMoves_;
};