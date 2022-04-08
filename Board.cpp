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
void Board::setWhitePieces()
{
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