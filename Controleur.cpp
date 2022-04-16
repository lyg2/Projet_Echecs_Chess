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
	if (!modele_->getHasSelectedPiece())
	{
		if (modele_->getBoard()->field_[posX][posY]->getPiece() != nullptr) {
			modele_->setHasSelectedPiece(true);
			modele_->setSelectedPiece(modele_->getBoard()->field_[posX][posY]->getPiece());
			emit colorSquare(posX, posY, true);
		}
	}
	else if (modele_->getHasSelectedPiece() 
		&& modele_->getSelectedPiece()->getPosX()==posX
		&& modele_->getSelectedPiece()->getPosY()==posY){
		modele_->setHasSelectedPiece(false);
		modele_->setSelectedPiece(nullptr);
		emit colorSquare(posX, posY, false);
	}
	else {
		int savedLocationX = modele_->getSelectedPiece()->getPosX();
		int savedLocationY = modele_->getSelectedPiece()->getPosY();
		if (modele_->getBoard()->movePiece(modele_->getSelectedPiece(), posX, posY)) {
			modele_->setHasSelectedPiece(false);
			emit drawPiece("", savedLocationX, savedLocationY);
			emit drawPiece(modele_->getSelectedPiece()->getNamePiece(), posX, posY);
			modele_->setSelectedPiece(nullptr);
			emit colorSquare(savedLocationX, savedLocationY, false);
		}
	}
}

void Controleur::newGameClicker() {
	
	if (!modele_->getIsNewGame())
	{
		
		modele_->getBoard()->drawBoard();
		modele_->getBoard()->setPieces();
		int i = 0;
		int j = 0;
		for (auto&& piece : modele_->getBoard()->getlistOfWhite())
		{
			modele_->getBoard()->addPieceOnBoard(piece, i, j);
			emit drawPiece(piece->getNamePiece(), i, j);
			i++;
			j++;
		}
		i = 7;
		j = 7;
		for (auto&& piece : modele_->getBoard()->getlistOfBlack()) {
			modele_->getBoard()->addPieceOnBoard(piece, i, j);
			emit drawPiece(piece->getNamePiece(), i, j);
			i--;
		}
	//	for (auto&& piece : modele_->getBoard()->getlistOfWhite())
	//{
	//	cout << typeid(*piece).name()<< " " <<piece->getPieceColor()<< " " 
	//		<< piece->getPosX() << ", " << piece->getPosY() << endl;
	//}

	//for (auto&& piece : modele_->getBoard()->getlistOfBlack())
	//{
	//	cout << typeid(*piece).name() << " " << piece->getPieceColor() << " "
	//		<< piece->getPosX() << ", " << piece->getPosY() << endl;
	//}
	//for (auto&& piece : modele_->getBoard()->getlistOfBlack())
	//{
	//	cout << typeid(*piece).name() << " " << piece->getPieceColor() << " "
	//		<< piece->getPosX() << ", " << piece->getPosY() << endl;
	//}
	////Only Rook should move
	//for (auto&& piece : modele_->getBoard()->getlistOfWhite())
	//{
	//	modele_->getBoard()->movePiece(piece,2,5);
	//}
	////No change because if King moves, the king is in check
	//for (auto&& piece : modele_->getBoard()->getlistOfWhite())
	//{
	//	modele_->getBoard()->movePiece(piece, 0, 1);
	//}
	//for (auto&& piece : modele_->getBoard()->getlistOfWhite())
	//{
	//	cout << typeid(*piece).name() << " " << piece->getPieceColor() << " "
	//		<< piece->getPosX() << ", " << piece->getPosY() << endl;
	//}
	modele_->setIsNewGame(true);
		
	}
	else {
		cout<<"Le nombre d'instance de roi est de "
			<< modele_->getBoard()->getWhiteKing_()->getCount()
			<<endl;
	}
}