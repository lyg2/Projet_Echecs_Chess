#pragma once
// Le Modèle pour calculatrice simple.
// Par Francois-R.Boyer@PolyMtl.ca

#pragma warning(push, 0) // Sinon Qt fait des avertissements à /W4.
#include <QObject>
#include <QGraphicsView>
#include <QGraphicsScene>
#include "Board.hpp"
#include "Piece.hpp"
#include "Player.hpp"
#pragma pop()
#include <functional>

using namespace std; // Dans ce cours on accepte le using namespace std dans le .hpp .
class Game {
public:
	void isPieceDead();
	void setBoard(Board* board) { board_ = board; };
	Board* getBoard() { return board_; };
	bool isGameOver() {return gameOver_;};
private:
	Board* board_;
	Player* player1_;
	Player* player2_;
	bool gameOver_;
};
