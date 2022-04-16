#pragma once
// Le Modèle pour calculatrice simple.
// Par Francois-R.Boyer@PolyMtl.ca

#pragma warning(push, 0) // Sinon Qt fait des avertissements à /W4.
#include <QObject>
#include <QGraphicsPixmapItem>
#include <QGraphicsSceneMouseEvent>
#include "Square.hpp"
#include "Piece.hpp"
#pragma pop()
#include <functional>

using namespace std; // Dans ce cours on accepte le using namespace std dans le .hpp .

class Square;

using namespace std; // Dans ce cours on accepte le using namespace std dans le .hpp .

class Rook : public Piece {
public:
	Rook() = default;
	virtual ~Rook() = default;
	bool validationMouvement(int posXApres, int posYApres) override;
	QString getNamePiece() override;

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
