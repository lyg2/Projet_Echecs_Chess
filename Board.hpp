#pragma once
// Le Modèle pour calculatrice simple.
// Par Francois-R.Boyer@PolyMtl.ca

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
	shared_ptr<Square> field_[8][8];
	void resetBoard();
	void drawBoard();
	Piece* readLinePosition(string color, string namePiece);
	void loadChessGame(string chessGame);
	void addPieceOnBoard(Piece* piece,int posX, int posY);
	bool simulateNextPosition(Piece* piece, int nextPosX, int nexPosY, King* king);
	bool isSquareAllyFree(Piece* piece, int movePosX, int movePosY);
	bool checkObstacle(Piece* pieceToMove, int movePosX, int movePosY);
	bool checkKing(King* king);
	bool isValidMove(Piece* original, int movePosX, int movePosY);
	void movePieceOnBoard(Piece* original, int movePosX, int movePosY);
	bool isCheckmate(string side);
	//bool movePiece(Piece* original, int movePosX, int movePosY);

	list<Piece*> getlistOfWhite() { return listOfWhite_; };
	list<Piece*> getlistOfBlack() { return listOfBlack_; };
	King* getWhiteKing_() { return whiteKing_; };
	King* getBlackKing_() { return blackKing_; };

private:
	list <Piece*> listOfWhite_={};
	list <Piece*> listOfBlack_ = {};
	list <Piece*> listOfWhiteDead_ = {};
	list <Piece*> listOfBlackDead_ = {};
	King* whiteKing_;
	King* blackKing_;

};
