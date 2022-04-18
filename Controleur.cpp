#pragma once
#include "Controleur.h"
#include "Rook.hpp"
#include "Bishop.hpp"
#include "King.hpp"
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
	if (modele_->getIsYourTurn()) {
		modele_->setColorTurn("White");
	}
	else {
		modele_->setColorTurn("Black");
	}
	if (!modele_->getHasSelectedPiece())
	{
		if (modele_->getBoard()->field_[posX][posY]->getPiece() != nullptr) {
			if (modele_->getBoard()->field_[posX][posY]
				->getPiece()->getPieceColor()==modele_->getColorTurn()){
				modele_->setHasSelectedPiece(true);
				modele_->setSelectedPiece(modele_->getBoard()
					->field_[posX][posY]->getPiece());
				emit colorSquare(posX, posY, true);
			}
			
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
		if (modele_->getBoard()->isValidMove(modele_->getSelectedPiece(), posX, posY)) {
			modele_->getBoard()->movePieceOnBoard(modele_->getSelectedPiece(), posX, posY);
			modele_->setHasSelectedPiece(false);
			emit drawPiece("", savedLocationX, savedLocationY);
			emit drawPiece(modele_->getSelectedPiece()->getNamePiece(), posX, posY);
			modele_->setSelectedPiece(nullptr);
			emit colorSquare(savedLocationX, savedLocationY, false);

			if (modele_->getBoard()->isCheckmate(modele_->getColorTurn()))
			{
				cout << "Checkmate ! Victory for " << modele_->getColorTurn() << endl;
				emit checkmate(QString::fromStdString(modele_->getColorTurn()));
			}
			modele_->setIsYourTurn(!modele_->getIsYourTurn());
			emit playerTurn(modele_->getIsYourTurn());
		}
		else {
			emit invalidMovement();
		}
	}
}

void Controleur::newGameClicker() {
	
	if (!modele_->getIsNewGame())
	{
		
	modele_->setIsNewGame(true);
		
	}
	else {
		cout<<"The number of kings is "
			<< modele_->getBoard()->getWhiteKing_()->getCount()
			<<endl;
	}
}
void Controleur::newGameMenu(QString name) {
	if (!modele_->getIsNewGame()) {
		modele_->getBoard()->drawBoard();
		try{
			modele_->getBoard()->loadChessGame(name.toStdString());
			modele_->setIsYourTurn(true);
		}
		catch(logic_error& e) {
			cout << "It is impossible to have more than 2 Kings" << e.what() << endl;
		}
		for (auto&& piece : modele_->getBoard()->getlistOfWhite()) {
			drawPiece(piece->getNamePiece(), piece->getPosX(), piece->getPosY());
		}
		for (auto&& piece : modele_->getBoard()->getlistOfBlack()) {
			drawPiece(piece->getNamePiece(), piece->getPosX(), piece->getPosY());
		}
		emit playerTurn(true);
		modele_->setIsNewGame(true);
	}
}