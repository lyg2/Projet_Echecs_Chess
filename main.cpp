/* Ce programme permet de créer un jeu d'échec pour fin de partie.
* @file: main.cpp
* @authors: Gia-Sherwin Ly
* @matricule: 2137375
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
#include "debogage_memoire.hpp"  //NOTE: Incompatible avec le "placement new", ne pas utiliser cette entête si vous utilisez ce type de "new" dans les lignes qui suivent cette inclusion.
#endif

void initialiserBibliothequeCours([[maybe_unused]] int argc, [[maybe_unused]] char* argv[])
{
	#ifdef BIBLIOTHEQUE_COURS_INCLUS
	bibliotheque_cours::activerCouleursAnsi();  // Permet sous Windows les "ANSI escape code" pour changer de couleurs https://en.wikipedia.org/wiki/ANSI_escape_code ; les consoles Linux/Mac les supportent normalement par défaut.

	// cdbg.setTee(&clog);  // Décommenter cette ligne pour que cdbg affiche sur la console en plus de la "Sortie" du débogueur.
	
	bibliotheque_cours::executerGoogleTest(argc, argv); // Attention de ne rien afficher avant cette ligne, sinon l'Explorateur de tests va tenter de lire votre affichage comme un résultat de test.
	#endif
	//NOTE: C'est normal que la couverture de code dans l'Explorateur de tests de Visual Studio ne couvre pas la fin de cette fonction ni la fin du main après l'appel à cette fonction puisqu'il exécute uniquement les tests Google Test dans l'appel ci-dessus.
}

int main(int argc, char *argv[])
{
	bibliotheque_cours::VerifierFuitesAllocations verifierFuitesAllocations;
	Modele::Game* game = new Modele::Game;
	Board* board = new Board;
	game->setBoard(board);
	QApplication app(argc, argv);
	initialiserBibliothequeCours(argc, argv);
	ChessWindow* window= new ChessWindow;
	Controleur controleur(game, window);
	QObject::connect(window,
		SIGNAL(squareClicked(QPushButton*, int, int)),
		&controleur,
		SLOT(squareClicker(QPushButton*, int , int)));
	QObject::connect(&controleur, SIGNAL(drawPiece(QString, int, int)), window, SLOT(drawNewPiece(QString, int, int)));
	QObject::connect(&controleur, SIGNAL(colorSquare(int, int, bool)), window, SLOT(updateColorSquare(int, int, bool)));
	QObject::connect(&controleur, SIGNAL(playerTurn(bool)), window, SLOT(updatePlayerTurn(bool)));
	QObject::connect(&controleur, SIGNAL(invalidMovement()), window, SLOT(invalidMovementWarning()));
	QObject::connect(window, SIGNAL(nameOfTheGameTyped(QString)), &controleur, SLOT(newGameMenu(QString)));
	QObject::connect(&controleur, SIGNAL(checkmate(QString)), window, SLOT(showWinner(QString)));
	QObject::connect(&controleur, SIGNAL(moreThanTwoKings()), window, SLOT(warningKing()));
	QObject::connect(&controleur, SIGNAL(stalemate()), window, SLOT(showStalemate()));
	QObject::connect(window, SIGNAL(startAnotherGameClicked()), &controleur, SLOT(startAnotherGameClicker()));
	// operator '&': deprecated between enumerations of different types. 
	//controleur et window ne sont pas du même type, car controleur est passé en reférence et window en pointeur.
	//une conversion implicite se fait, ce qui déclenche un warning.
	window->show();
	return app.exec();
}
