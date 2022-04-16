/* Ce programme teste des mouvements de pi�ces
* @file: main,cpp
* @authors: Gia-Sherwin Ly, Fatima Mellata, Maroua Ouhib
* @matricule: 2137375, 2147725, 2154712
* @date:12 avril 2022
*/ 
#include "Game.hpp"
#include "ui_Vue.h"
#include "ChessWindow.hpp"
#include "Controleur.h"
#include<iostream>
#include <QApplication>
#include <QLayoutItem>
#include <QPushButton>
#include <QObject>

#if __has_include("bibliotheque_cours.hpp")
#include "bibliotheque_cours.hpp"
#define BIBLIOTHEQUE_COURS_INCLUS
using bibliotheque_cours::cdbg;
#else
auto& cdbg = clog;
#endif

#if __has_include("verification_allocation.hpp")
#include "verification_allocation.hpp"
#include "debogage_memoire.hpp"  //NOTE: Incompatible avec le "placement new", ne pas utiliser cette ent�te si vous utilisez ce type de "new" dans les lignes qui suivent cette inclusion.
#endif

void initialiserBibliothequeCours([[maybe_unused]] int argc, [[maybe_unused]] char* argv[])
{
	#ifdef BIBLIOTHEQUE_COURS_INCLUS
	bibliotheque_cours::activerCouleursAnsi();  // Permet sous Windows les "ANSI escape code" pour changer de couleurs https://en.wikipedia.org/wiki/ANSI_escape_code ; les consoles Linux/Mac les supportent normalement par d�faut.

	// cdbg.setTee(&clog);  // D�commenter cette ligne pour que cdbg affiche sur la console en plus de la "Sortie" du d�bogueur.
	
	bibliotheque_cours::executerGoogleTest(argc, argv); // Attention de ne rien afficher avant cette ligne, sinon l'Explorateur de tests va tenter de lire votre affichage comme un r�sultat de test.
	#endif
	//NOTE: C'est normal que la couverture de code dans l'Explorateur de tests de Visual Studio ne couvre pas la fin de cette fonction ni la fin du main apr�s l'appel � cette fonction puisqu'il ex�cute uniquement les tests Google Test dans l'appel ci-dessus.
}

int main(int argc, char *argv[])
{
	bibliotheque_cours::VerifierFuitesAllocations verifierFuitesAllocations;
	Modele::Game* game = new Modele::Game;
	Board* board = new Board;
	game->setBoard(board);
	//
	//for (auto&& piece : game->getBoard()->getlistOfWhite())
	//{
	//	cout << typeid(*piece).name()<< " " <<piece->getPieceColor()<< " " 
	//		<< piece->getPosX() << ", " << piece->getPosY() << endl;
	//}

	//for (auto&& piece : game->getBoard()->getlistOfBlack())
	//{
	//	cout << typeid(*piece).name() << " " << piece->getPieceColor() << " "
	//		<< piece->getPosX() << ", " << piece->getPosY() << endl;
	//}
	////Only Rook should move
	//for (auto&& piece : game->getBoard()->getlistOfWhite())
	//{
	//	game->getBoard()->movePiece(piece,2,5);
	//}

	////No change because if King moves, the king is in check
	//for (auto&& piece : game->getBoard()->getlistOfWhite())
	//{
	//	game->getBoard()->movePiece(piece, 0, 1);
	//}
	////Only King should move
	//for (auto&& piece : game->getBoard()->getlistOfWhite())
	//{
	//	game->getBoard()->movePiece(piece, 1, 0);
	//}

	//for (auto&& piece : game->getBoard()->getlistOfWhite())
	//{
	//	cout << typeid(*piece).name() << " " << piece->getPieceColor() << " "
	//		<< piece->getPosX() << ", " << piece->getPosY() << endl;
	//}
	
	/*for (auto&& piece : game->getBoard()->getlistOfWhite())
	{
		delete piece;
	}
	for (auto&& piece : game->getBoard()->getlistOfBlack())
	{
		delete piece;
	}*/
	//delete board;
	//game->getBoard()->addPieceOnBoard();
	QApplication app(argc, argv);
	initialiserBibliothequeCours(argc, argv);
	ChessWindow* window= new ChessWindow;
	Controleur controleur(game, window);
	QObject::connect(window,
		SIGNAL(squareClicked(QPushButton*, int, int)),
		&controleur,
		SLOT(squareClicker(QPushButton*, int , int)));
	QObject::connect(window, SIGNAL(newGameClicked()), &controleur, SLOT(newGameClicker()));
	QObject::connect(&controleur, SIGNAL(drawPiece(QString, int, int)), window, SLOT(drawNewPiece(QString, int, int)));
	QObject::connect(&controleur, SIGNAL(colorSquare(int, int, bool)), window, SLOT(updateColorSquare(int, int, bool)));
	QObject::connect(&controleur, SIGNAL(playerTurn(bool)), window, SLOT(updatePlayerTurn(bool)));
	window->show();
	return app.exec();
}
