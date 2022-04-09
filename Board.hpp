#pragma once
// Le Modèle pour calculatrice simple.
// Par Francois-R.Boyer@PolyMtl.ca

#pragma warning(push, 0) // Sinon Qt fait des avertissements à /W4.
#include <QGraphicsRectItem>
#include "Piece.hpp"
#include "Square.hpp"
#include <list>
#include <QObject>
#pragma pop()
#include <functional>

using namespace std; // Dans ce cours on accepte le using namespace std dans le .hpp .

class Board {
public:
	Board()=default;
	void drawBoard();
	void setWhitePieces();
	void setBlackPieces();
	void addPieceOnBoard(Piece* piece, Square* square);

private:
	list <Piece*> listOfWhite_;
	list <Piece*> listOfBlack_;
	Square* field_ [8][8];

};
//class Calc : public QObject {
//	Q_OBJECT
//public:
//	Calc() = default;
//
//	int obtenirValeur() { return valeur_; }
//
//public slots:
//	void changerValeur(int valeur);
//	void effacer();
//	void ajouterChiffre(int chiffre);
//	void changerOperation(const function<int(int,int)>& operation);
//	void operationPlus();
//	void operationMoins();
//	void operationEgal();
//	void effectuerOperation();
//
//signals:
//	void valeurChangee(int valeur);
//
//private:
//	static int plus (int x, int y);
//	static int moins(int x, int y);
//	static int egal (int  , int y);
//
//	bool estResultat_ = true;
//	int valeur_ = 0;
//	int resultatPrecedent_ = 0;
//	function<int(int,int)> operation_ = egal;
//};
