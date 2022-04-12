#pragma once
// Le Modèle pour calculatrice simple.
// Par Francois-R.Boyer@PolyMtl.ca

#pragma warning(push, 0) // Sinon Qt fait des avertissements à /W4.
#include <QGraphicsRectItem>
#include <iostream>
#include "Piece.hpp"
#include "Square.hpp"
#include "Board.hpp"
#include "King.hpp"
#include "Rook.hpp"
#include "Bishop.hpp"
#include <QObject>
#pragma pop()
#include <functional>

using namespace std; // Dans ce cours on accepte le using namespace std dans le .hpp .
void Board::setPieces()
{
	//set color
	Piece* piece;
	piece = new King;
	piece->setPieceColor("White");
	listOfWhite_.push_back(piece);
	whiteKing_ = piece;
	piece = new Bishop;
	piece->setPieceColor("White");
	listOfWhite_.push_back(piece);
	piece = new Rook;
	piece->setPieceColor("White");
	listOfWhite_.push_back(piece);

	piece = new King;
	listOfBlack_.push_back(piece);
	piece->setPieceColor("Black");
	blackKing_ = piece;
	piece = new Bishop;
	listOfBlack_.push_back(piece);
	piece->setPieceColor("Black");
	piece = new Rook;
	piece->setPieceColor("Black");
	listOfBlack_.push_back(piece);
}

void Board::drawBoard()
{
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			Square* square = new Square;
			square->setPositionX(i);
			square->setPositionY(j);
			square->putPieceOnSquare(nullptr);
			if ((i + j) % 2 == 0)
			{
				square->setCaseColor("White");
			}
			else {
				square->setCaseColor("Black");
			}
			field_[i][j] = unique_ptr<Square>(square);

		}
	}
}

void Board::addPieceOnBoard(Piece* piece,int posX, int posY)
{
	piece->setPosX(posX);
	piece->setPosY(posY);
	field_[posX][posY]->setPositionX(posX);
	field_[posX][posY]->setPositionY(posY);
	field_[posX][posY]->putPieceOnSquare(piece);
	field_[posX][posY]->setHasPiece(true);
}

bool Board:: checkObstacle(Square* square, int movePosX, int movePosY) {
	//if checkObstacle==true, then no obstacle
	// Must correct bug use field_[ instead of square for the if.
	bool goUp = false;
	bool goDown = false;
	bool goLeft = false;
	bool goRight = false;
	bool goUpRight = false;
	bool goUpLeft = false;
	bool goDownRight = false;
	bool goDownLeft = false;
	int posX = square->getPositionX();
	int posY = square->getPositionY();
	if (!(square->getPiece()->validationMouvement(movePosX, movePosY))) {
		return false;
	}

	if ((movePosX - posX >= 1) && (movePosY == posY))
	{
		goRight = true;
	}
	else if ((movePosX - posX <= -1) && (movePosY == posY))
	{
		goLeft = true;
	}

	else if ((movePosX == posX) && (movePosY- posY>=1)) {
		goDown = true;
	}
	else if ((movePosX == posX) && (movePosY - posY >= -1)) {
		goUp = true;
	}

	else if ((movePosX-posX>=1) && (movePosY - posY>=1)) 
	{
		goDownRight = true;
	}
	else if ((movePosX - posX >= 1) && (movePosY - posY <= -1))
	{
		goUpRight = true;
	}

	else if ((movePosX - posX >= -1) && (movePosY - posY >= 1))
	{
		goDownLeft = true;
	}

	else if ((movePosX - posX <= -1) && (movePosY - posY <= -1))
	{
		goUpLeft = true;
	}
	if (goRight) 
	{
		for (posX; posX < movePosX; posX++)
		{
			if (field_[posX][posY]->getPiece() != nullptr
				&& square != field_[posX][posY].get())
			{
				return false;
			}
		}
		if (field_[movePosX][movePosY]->getPiece()==nullptr)
		{
			return true;
		}
		else if (square->getPieceColor() != field_[movePosX][movePosY]->getPieceColor())
		{
			return true;
		}
		//check if Piece is Black or White and Player
	}
	else if (goLeft)
	{
		for (posX; posX > movePosX; posX--)
		{
			if (field_[posX][posY]->getPiece() != nullptr
				&& square != field_[posX][posY].get())
			{
				return false;
			}
		}
		if (field_[movePosX][movePosY]->getPiece() == nullptr)
		{
			return true;
		}
		else if (square->getPieceColor() != field_[movePosX][movePosY]->getPieceColor())
		{
			return true;
		}
	}
	else if (goDown)
	{
		for (posY; posY < movePosY; posY++)
		{
			if (field_[posX][posY]->getPiece() != nullptr 
				&& square != field_[posX][posY].get())
			{
				return false;
			}
		}
		if (field_[movePosX][movePosY]->getPiece() == nullptr)
		{
			return true;
		}
		else if (square->getPieceColor() != field_[movePosX][movePosY]->getPieceColor())
		{
			return true;
		}
	}

	else if (goUp) 
	{
		for (posY; posY > movePosY; posY--) 
		{
			if (field_[posX][posY]->getPiece() != nullptr
				&& square != field_[posX][posY].get())
			{
				return false;
			}
		}
		if (field_[movePosX][movePosY]->getPiece() == nullptr)
		{
			return true;
		}
		else if (square->getPieceColor() != field_[movePosX][movePosY]->getPieceColor())
		{
			return true;
		}
	}

	else if (goDownRight)
	{
		while (posX != movePosX && posY != movePosY)
		{
			if (field_[posX][posY]->getPiece() != nullptr
				&& square != field_[posX][posY].get())
			{
				return false;
			}
			posX++;
			posY++;
		}
		if (field_[movePosX][movePosY]->getPiece() == nullptr)
		{
			return true;
		}
		else if (square->getPieceColor() != field_[movePosX][movePosY]->getPieceColor())
		{
			return true;
		}
	}
	else if (goDownLeft)
	{
		while (posX != movePosX && posY != movePosY)
		{
			if (field_[posX][posY]->getPiece() != nullptr
				&& square != field_[posX][posY].get())
			{
				return false;
			}
			posX--;
			posY++;
		}
		if (field_[movePosX][movePosY]->getPiece() == nullptr)
		{
			return true;
		}
		else if (square->getPieceColor() != field_[movePosX][movePosY]->getPieceColor())
		{
			return true;
		}
	}

	else if (goUpRight)
	{
		while (posX != movePosX && posY != movePosY)
		{
			if (field_[posX][posY]->getPiece() != nullptr
				&& square != field_[posX][posY].get())
			{
				return false;
			}
			posX++;
			posY--;
		}
		if (field_[movePosX][movePosY]->getPiece() == nullptr)
		{
			return true;
		}
		else if (square->getPieceColor() != field_[movePosX][movePosY]->getPieceColor())
		{
			return true;
		}
		//check if Piece is Black or White and Player
	}
	else if (goUpLeft) 
	{
		while (posX != movePosX && posY != movePosY)
		{
			if (field_[posX][posY]->getPiece() != nullptr
				&& square != field_[posX][posY].get())
			{
				return false;
			}
			posX--;
			posY--;
		}
		if (field_[movePosX][movePosY]->getPiece() == nullptr)
		{
			return true;
		}
		else if (square->getPieceColor() != field_[movePosX][movePosY]->getPieceColor())
		{
			return true;
		}
	}
	return false;
}
bool Board::checkKing(King* king) {
	//if checkKing==true, then there's no King in check.
	int posX=king->getPosX();
	int posY=king->getPosY();
	if (king->getPieceColor() == "White")
	{
		for (auto piece : listOfBlack_)
		{
			if (dynamic_cast<King*>(piece)!=nullptr)
			{
				if (checkObstacle(field_[piece->getPosX()][piece->getPosY()].get(), posX, posY))
				{
					return false;
				}
				
			}
		}
	}
	else {
		for (auto piece : listOfWhite_)
		{
			if (dynamic_cast<King*>(piece) != nullptr)
			{
				if (checkObstacle(field_[piece->getPosX()][piece->getPosY()].get(), posX, posY))
				{
					return false;
				}
			}
		}
	}
	return true;

}
void Board::movePiece(Piece* original, int movePosX, int movePosY) {
	if (original->getPieceColor() == "White")
	{
		if (!checkKing(dynamic_cast<King*>(whiteKing_))
			|| !checkObstacle(
				field_[original->getPosX()][original->getPosY()].get(),
				movePosX,
				movePosY))
		{
			cout << "Illegal movement" << endl;
			return;
		}
	}
	else
	{
		if (!checkKing(dynamic_cast<King*>(whiteKing_))
			|| !checkObstacle(
				field_[original->getPosX()][original->getPosY()].get(),
				movePosX,
				movePosY))
		{
			cout << "Illegal movement" << endl;
			return;
		}
	}
	int originalPosX = original->getPosX();
	int originalPosY = original->getPosY();
	original->setPosX(movePosX);
	original->setPosY(movePosY);
	field_[movePosX][movePosY]->putPieceOnSquare(original);
	field_[originalPosX][originalPosY] = nullptr;
}
//int getField(int posX) {
//	return getField(posX);
//}



