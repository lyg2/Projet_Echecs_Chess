#pragma once
// Le Modèle pour calculatrice simple.
// Par Francois-R.Boyer@PolyMtl.ca

#pragma warning(push, 0) // Sinon Qt fait des avertissements à /W4.
#include <QObject>
#include <QGraphicsView>
#include <QGraphicsScene>
#include "Board.hpp"
#include "Piece.hpp"
#include "Square.hpp"
#include <memory>
#include <list>
#include <functional>
#pragma pop()

using namespace std; // Dans ce cours on accepte le using namespace std dans le .hpp .
namespace Modele {
	class Game {
	public:
		Game ()= default;
		~Game();
		void setBoard(Board* board) { board_ = board; };
		Board* getBoard() { return board_; };
		bool getIsNewGame() { return isNewGame_; };
		void setIsNewGame(bool isNewGame) { isNewGame_ = isNewGame; };
		bool getHasSelectedPiece(){ return hasSelectedPiece_; };
		void setHasSelectedPiece(bool hasSelectedPiece) { hasSelectedPiece_ = hasSelectedPiece; };
		Piece* getSelectedPiece() { return selectedPiece_; };
		void setSelectedPiece(Piece* selectedPiece) { selectedPiece_=selectedPiece; };
		void setIsYourTurn(bool isYourTurn) { isYourTurn_ = isYourTurn; };
		bool getIsYourTurn() { return isYourTurn_; };
		void setColorTurn(string colorTurn) { colorTurn_ = colorTurn; };
		string getColorTurn() { return colorTurn_; };
		/*Player* getPlayer1() { return player1_; };
		Player* getPlayer2() { return player2_; };
		void setPlayer1(Player* player) { player1_=player; };
		void setPlayer2(Player* player) { player2_ = player; };*/
	private:
		string colorTurn_;
		bool isYourTurn_;
		bool isNewGame_ = false;
		bool hasSelectedPiece_ = false;
		Piece* selectedPiece_;
		Board* board_;
		list<Piece*> whiteDead;
		list<Piece*> blackDead;
	};
}

