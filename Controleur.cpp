#include "Controleur.h"
#include <iostream>

Controleur::Controleur(Modele::Game* modele, ChessWindow* vue)
	:modele_(modele)
	, vue_ (vue){}
Controleur:: ~Controleur()
{
	delete modele_;
	delete vue_;
}

void Controleur::squareClicker(QPushButton* squareButton, int posX, int posY) {
	cout << posX << " " << posY<<endl;
}

void Controleur::newGameClicker() {
	cout << "lol" << endl;
	if (!modele_->getIsNewGame())
	{
		/*Board* board = new Board;
		modele_->setBoard(board);
		modele_->setPlayer();
		modele_->getBoard()->drawBoard();
		modele_->getBoard()->setPieces();
		int i = 0;
		int j = 0;*/
		/*for (auto&& piece : modele_->getBoard()->getlistOfWhite())
		{
			modele_->getBoard()->addPieceOnBoard(piece, i++, j++);
		}
		i = 7;
		j = 7;
		for (auto&& piece : modele_->getBoard()->getlistOfBlack()) {
			modele_->getBoard()->addPieceOnBoard(piece, i--, j);
		}
		for (auto&& piece : modele_->getBoard()->getlistOfWhite())
	{
		cout << typeid(*piece).name()<< " " <<piece->getPieceColor()<< " " 
			<< piece->getPosX() << ", " << piece->getPosY() << endl;
	}

	for (auto&& piece : modele_->getBoard()->getlistOfBlack())
	{
		cout << typeid(*piece).name() << " " << piece->getPieceColor() << " "
			<< piece->getPosX() << ", " << piece->getPosY() << endl;
	}*/
	modele_->setIsNewGame(true);
		
	}
}