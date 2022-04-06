#pragma once
// Le Modèle pour calculatrice simple.
// Par Francois-R.Boyer@PolyMtl.ca

#pragma warning(push, 0) // Sinon Qt fait des avertissements à /W4.
#include <QObject>
#include <QGraphicsView>
#include <QGraphicsScene>
#include "Board.hpp"
#include "Piece.hpp"
#pragma pop()
#include <functional>

using namespace std; // Dans ce cours on accepte le using namespace std dans le .hpp .
class Game : public QGraphicsView {
	Q_OBJECT
public:
	Game(QWidget* parent = 0);
	int** obtenirPosition() { return position_; };
public slots:

signals:
	void changerPosition(int** position);
	void changerPiece(string piece);
private:
	int** position_;
	int** positionPrecendente;
	bool IsCaseSelected;
	bool IsPieceSelected;
	string piece_;
};
