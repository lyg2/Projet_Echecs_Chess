#pragma once
#pragma warning(push, 0) // Sinon Qt fait des avertissements à /W4.
#include <QGraphicsRectItem>
#include "Piece.hpp"
#include "Square.hpp"
#include "King.hpp"
#include <list>
#include <QObject>
#include <fstream>
#pragma pop()
#include <functional>

using namespace std; // Dans ce cours on accepte le using namespace std dans le .hpp .

class Board {
public:
	Board()=default;
	~Board();
	void resetBoard();
	void drawBoard();
	shared_ptr<Square> getFieldSquare(int posX, int posY) const { return field_[posX][posY]; };
	Piece* readLinePosition(string color, string namePiece);
	void loadChessGame(string chessGame);
	void addPieceOnBoard(Piece* piece,int posX, int posY);
	bool simulateNextPosition(Piece* piece, int nextPosX, int nexPosY, King* king);
	bool isSquareAllyFree(Piece* piece, int movePosX, int movePosY);
	bool isObstacleFree(Piece* pieceToMove, int movePosX, int movePosY);
	bool isKingSafe(King* king);
	bool isValidMove(Piece* original, int movePosX, int movePosY);
	void movePieceOnBoard(Piece* original, int movePosX, int movePosY);
	bool isImpossibleToMoveKing(string side);
	bool isStalemate(string side);
	bool isCheckmate(string side);
	//bool movePiece(Piece* original, int movePosX, int movePosY);

	list<Piece*> getlistOfWhite() const { return listOfWhite_; };
	list<Piece*> getlistOfBlack() const { return listOfBlack_; };
	King* getWhiteKing_() const { return whiteKing_; };
	King* getBlackKing_() const { return blackKing_; };

private:
	shared_ptr<Square> field_[8][8];
	list <Piece*> listOfWhite_={};
	list <Piece*> listOfBlack_ = {};
	list <Piece*> listOfWhiteDead_ = {};
	list <Piece*> listOfBlackDead_ = {};
	King* whiteKing_;
	King* blackKing_;

};
