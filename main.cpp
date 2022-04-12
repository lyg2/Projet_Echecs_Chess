#include "Game.hpp"
#include "ChessWindow.hpp"
#include<iostream>
#include <QApplication>

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
	Game* game = new Game;
	Board* board = new Board;
	game->setBoard(board);
	game->getBoard()->drawBoard();
	game->getBoard()->setPieces();
	int i = 0;
	int j = 0;
	for (auto&& piece : game->getBoard()->getlistOfWhite())
	{
		game->getBoard()->addPieceOnBoard(piece, i++, j++);
	}
	i = 7;
	j = 7;
	for (auto&& piece : game->getBoard()->getlistOfBlack()){
		game->getBoard()->addPieceOnBoard(piece,i--,j);
	}
	for (auto&& piece : game->getBoard()->getlistOfWhite())
	{
		cout << typeid(*piece).name()<< " " <<piece->getPieceColor()<< " " 
			<< piece->getPosX() << ", " << piece->getPosY() << endl;
	}

	for (auto&& piece : game->getBoard()->getlistOfBlack())
	{
		cout << typeid(*piece).name() << " " << piece->getPieceColor() << " "
			<< piece->getPosX() << ", " << piece->getPosY() << endl;
	}
	for (auto&& piece : game->getBoard()->getlistOfWhite())
	{
		game->getBoard()->movePiece(piece,2,5);
	}

	for (auto&& piece : game->getBoard()->getlistOfWhite())
	{
		game->getBoard()->movePiece(piece, 0, 1);
	}
	/*for (auto&& piece : game->getBoard()->getlistOfWhite())
	{
		game->getBoard()->movePiece(piece, 2, 2);
	}*/

	for (auto&& piece : game->getBoard()->getlistOfWhite())
	{
		cout << typeid(*piece).name() << " " << piece->getPieceColor() << " "
			<< piece->getPosX() << ", " << piece->getPosY() << endl;
	}

	
	for (auto&& piece : game->getBoard()->getlistOfWhite())
	{
		delete piece;
	}
	for (auto&& piece : game->getBoard()->getlistOfBlack())
	{
		delete piece;
	}
	//game->getBoard()->addPieceOnBoard();
	delete game;
	delete board;
	//QApplication app(argc, argv);
	//initialiserBibliothequeCours(argc, argv);

	//CalcWindow calcWindow;
	//calcWindow.show();
	//return app.exec();
	return 0;
}
