/* Ce fichier est la classe Controleur qui s'occupe du controleur.
* @file: ChessWindow.cpp
* @authors: Gia-Sherwin Ly
* @matricule: 2137375
* @date:12 avril 2022
*/
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
	if (modele_->getBoard()->isStalemate(modele_->getColorTurn())) {
		emit stalemate();
		return;
	}
	if (!modele_->getHasSelectedPiece())
	{
		if (modele_->getBoard()->getFieldSquare(posX, posY)->getPiece() != nullptr) 
		{
			if (modele_->getBoard()->getFieldSquare(posX, posY)
				->getPiece()->getPieceColor()==modele_->getColorTurn())
			{
				modele_->setHasSelectedPiece(true);
				modele_->setSelectedPiece(modele_->getBoard()
					->getFieldSquare(posX, posY)->getPiece());
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

void Controleur::newGameMenu(QString name) {
	if (!modele_->getIsNewGame()) {
		modele_->getBoard()->drawBoard();
		emit playerTurn(true);
		modele_->setIsNewGame(true);
		try{
			modele_->getBoard()->loadChessGame(name.toStdString());
			modele_->setIsYourTurn(true);
		}
		catch(logic_error& e) {
			cout << "It is impossible to have more than 2 Kings"<<endl;
			cout << e.what();
			emit moreThanTwoKings();
		}
		for (auto&& piece : modele_->getBoard()->getlistOfWhite()) {
			drawPiece(piece->getNamePiece(), piece->getPosX(), piece->getPosY());
		}
		for (auto&& piece : modele_->getBoard()->getlistOfBlack()) {
			drawPiece(piece->getNamePiece(), piece->getPosX(), piece->getPosY());
		}
	}
}

void Controleur::startAnotherGameClicker() {
	int nColumns = 8;
	int nRows = 8;
	modele_->setIsNewGame(false);
	modele_->getBoard()->resetBoard();
	for (int i = 0; i < nColumns; i++) {
		for (int j = 0; j < nRows; j++) {
			emit drawPiece("", i, j);
		}
	}
}