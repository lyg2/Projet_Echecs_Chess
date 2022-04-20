#pragma once
/* Ce fichier est la classe abstraite Piece.
* @file: Piece.cpp
* @authors: Gia-Sherwin Ly
* @matricule: 2137375
* @date:12 avril 2022
*/
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
	int getPosX() const { return posX_; };
	int getPosY() const { return posY_; };
	void setPosX(int posX) { posX_ = posX; };
	void setPosY(int posY) { posY_ = posY; };
	int getSavedPosX() const { return savedPosX_; };
	int getSavedPosY() const { return savedPosY_; };
	void setSavedPosX(int savedPosX) {savedPosX_=savedPosX; };
	void setSavedPosY(int savedPosY) {savedPosY_ = savedPosY; };
	string getName() const { return namePiece_; }

	void setPieceColor(string color) { color_ = color; };
	string getPieceColor() const { return color_; };

	//virtual void movePiece(int i, int j) = 0;

protected:
	int posX_;
	int posY_;
	int savedPosX_;
	int savedPosY_;
	string namePiece_;
	string color_;
};