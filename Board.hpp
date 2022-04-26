/* Ce fichier est la classe Board qui s'occupe du mouvement des pièces.
* @file: Board.hpp
* @authors: Gia-Sherwin Ly
* @matricule: 2137375
* @date:12 avril 2022
*/
#pragma once
#pragma warning(push, 0) // Sinon Qt fait des avertissements à /W4.
#include <QGraphicsRectItem>
#include "Piece.hpp"
#include "Square.hpp"
#include "King.hpp"
#include "Movement.h"
#include <list>
#include <QObject>
#include <fstream>
#pragma pop()
#include <functional>

using namespace std; // Dans ce cours on accepte le using namespace std dans le .hpp .

class Board {
public:
	Board() = default;
	~Board();
	void resetBoard();
	void drawBoard();
	shared_ptr<Square> getFieldSquare(int posX, int posY) const { return field_[posX][posY]; };
	Piece* readLinePosition(string color, string namePiece);
	void loadChessGame(string chessGame);
	void addPieceOnBoard(Piece* piece, int posX, int posY);
	bool isSimulationSucessful(Piece* piece, int nextPosX, int nexPosY, King* king);
	Movement getMovement(int posX, int posY, int movePosX, int movePosY);
	void treatMovement(int& posX, int& posY, Movement& movement);
	bool isSquareAllyFree(Piece* piece, int movePosX, int movePosY);
	bool isObstacleFree(Piece* pieceToMove, int movePosX, int movePosY);
	bool isKingSafeByEating(King* king, int movePosX, int movePosY);
	bool isKingSafe(King* king);
	bool isValidMove(Piece* original, int movePosX, int movePosY);
	void movePieceOnBoard(Piece* original, int movePosX, int movePosY);
	bool HasNoLegalMove(string side);
	bool isStalemate(string side);
	bool isCheckmate(string side);

	list <unique_ptr<Piece>>::iterator listOfWhiteBegin()  { return listOfWhite_.begin(); };
	list <unique_ptr<Piece>>::iterator listOfWhiteEnd() { return listOfWhite_.end(); };
	list <unique_ptr<Piece>>::iterator listOfBlackBegin() { return listOfBlack_.begin(); };
	list <unique_ptr<Piece>>::iterator listOfBlackEnd() { return listOfBlack_.end(); };

private:
	shared_ptr<Square> field_[8][8];
	list <unique_ptr<Piece>> listOfWhite_;
	list <unique_ptr<Piece>> listOfBlack_;
	King* whiteKing_;
	King* blackKing_;

};
