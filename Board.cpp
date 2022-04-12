#pragma once
// Le Modèle pour calculatrice simple.
// Par Francois-R.Boyer@PolyMtl.ca

#pragma warning(push, 0) // Sinon Qt fait des avertissements à /W4.
#include <QGraphicsRectItem>
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
	listOfWhite_.push_back(piece);
	piece = new Bishop;
	listOfWhite_.push_back(piece);
	piece = new Rook;
	listOfWhite_.push_back(piece);

	piece = new King;
	listOfBlack_.push_back(piece);
	piece = new Bishop;
	listOfBlack_.push_back(piece);
	piece = new Rook;
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
			if ((i + j) % 2 == 0)
			{
				square->setCaseColor("White");
			}
			else {
				square->setCaseColor("Black");
			}
			field_[i][j] = square;

		}
	}
}

void Board::addPieceOnBoard(Piece* piece, Square* square, int posX, int posY)
{
	square->putPieceOnSquare(piece);
	square->setHasPiece(true);
	square->setPositionX(posX);
	square->setPositionY(posY);
}

bool Board:: checkObstacle(Square* square, int movePosX, int movePosY) {
	//
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
	if (!square->getPiece()->validationMouvement(movePosX, movePosY)) {
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
			if (square->getPiece() != nullptr)
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
			if (square->getPiece() != nullptr)
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
			if (square->getPiece() != nullptr)
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
			if (square->getPiece() != nullptr)
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
			if (square->getPiece() != nullptr)
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
			if (square->getPiece() != nullptr)
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
			if (square->getPiece() != nullptr)
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
			if (square->getPiece() != nullptr)
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
	int posX=king->getPosX();
	int posY=king->getPosY();
	if (king->getPieceColor() == "White")
	{
		for (auto piece : listOfBlack_)
		{
			if (!dynamic_cast<King*>(king))
			{
				if (checkObstacle(field_[piece->getPosX()][piece->getPosY()], posX, posY))
				{
					return true;
				}
				
			}
		}
	}
	else {
		for (auto piece : listOfWhite_)
		{
			if (!dynamic_cast<King*>(king))
			{
				if (checkObstacle(field_[piece->getPosX()][piece->getPosY()], posX, posY))
				{
					return true;
				}
			}
		}
	}
	return false;

}
//int getField(int posX) {
//	return getField(posX);
//}



