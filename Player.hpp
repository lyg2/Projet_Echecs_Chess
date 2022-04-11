#pragma once
// Le Modèle pour calculatrice simple.
// Par Francois-R.Boyer@PolyMtl.ca

#pragma warning(push, 0) // Sinon Qt fait des avertissements à /W4.
#include <QObject>
#include "Piece.hpp"
#include <list>
#pragma pop()
#include <functional>

using namespace std; // Dans ce cours on accepte le using namespace std dans le .hpp .
class Piece;
class Player {
public:
	Player() = default;
	bool getIsYourTurn() { return isYourTurn_; };
	void setIsYourTurn(bool turn) { isYourTurn_ = turn; };
	string getName() { return name_; };
	void setName(string name) { name_ = name; };

private:
	string name_;
	bool isYourTurn_;
};