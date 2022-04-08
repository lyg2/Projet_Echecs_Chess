#pragma once
// Le Mod�le pour calculatrice simple.
// Par Francois-R.Boyer@PolyMtl.ca

#pragma warning(push, 0) // Sinon Qt fait des avertissements � /W4.
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
void Board::setWhitePieces()
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
			square->setPositionRow(i);
			square->setPositionColumn(j);
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



