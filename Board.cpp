#pragma once
/* Ce fichier est la classe Board qui s'occcupe du mouvement des pièces et de l'échéquier.
* @file: Bishop.cpp
* @authors: Gia-Sherwin Ly, Fatima Mellata, Maroua Ouhib
* @matricule: 2137375, 2147725, 2154712
* @date:12 avril 2022
*/

#pragma warning(push, 0) // Sinon Qt fait des avertissements à /W4.
#include <QGraphicsRectItem>
#include <iostream>
#include "Piece.hpp"
#include "Square.hpp"
#include "Board.hpp"
#include "King.hpp"
#include "Rook.hpp"
#include "Bishop.hpp"
#include "Simulator.h"
#include <QObject>
#pragma pop()
#include <functional>

using namespace std; // Dans ce cours on accepte le using namespace std dans le .hpp .
Board:: ~Board() {
	for (auto&& piece : listOfWhite_) {
		delete piece;
	}
	for (auto&& piece : listOfBlack_) {
		delete piece;
	}
	for (auto&& piece : listOfWhiteDead_) {
		delete piece;
	}
	for (auto&& piece : listOfBlackDead_) {
		delete piece;
	}
}
void Board::setPieces()
{
	//set color
	Piece* piece;
	piece = new King;
	piece->setPieceColor("White");
	listOfWhite_.push_back(piece);
	whiteKing_ = dynamic_cast<King*>(piece);
	piece = new Bishop;
	piece->setPieceColor("White");
	listOfWhite_.push_back(piece);
	piece = new Rook;
	piece->setPieceColor("White");
	listOfWhite_.push_back(piece);

	piece = new King;
	listOfBlack_.push_back(piece);
	piece->setPieceColor("Black");
	blackKing_ = dynamic_cast<King*>(piece);
	piece = new Bishop;
	listOfBlack_.push_back(piece);
	piece->setPieceColor("Black");
	piece = new Rook;
	piece->setPieceColor("Black");
	listOfBlack_.push_back(piece);
}

void Board::drawBoard()
{
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			Square* square = new Square;
			square->setPositionX(i);
			square->setPositionY(j);
			square->putPieceOnSquare(nullptr);
			if ((i + j) % 2 == 0)
			{
				square->setCaseColor("White");
			}
			else {
				square->setCaseColor("Black");
			}
			field_[i][j] = shared_ptr<Square>(square);

		}
	}
}

void Board::addPieceOnBoard(Piece* piece, int posX, int posY)
{
	piece->setPosX(posX);
	piece->setPosY(posY);
	field_[posX][posY]->setPositionX(posX);
	field_[posX][posY]->setPositionY(posY);
	field_[posX][posY]->putPieceOnSquare(piece);
	field_[posX][posY]->setHasPiece(true);
}

bool Board::simulateNextPosition(Piece* piece, int nextPosX, int nextPosY, King* king)
{
	Simulator simulator = Simulator(piece, field_, nextPosX, nextPosY);
	return checkKing(king);
}
void Board::undoNextPosition(Piece* piece)
{
	field_[piece->getSavedPosX()][piece->getSavedPosY()]->putPieceOnSquare(piece);
	field_[piece->getPosX()][piece->getPosY()]->putPieceOnSquare(nullptr);
	piece->setPosX(piece->getSavedPosX());
	piece->setPosY(piece->getSavedPosY());
}

bool Board::checkObstacle(Piece* pieceToMove, int movePosX, int movePosY) {
	//if checkObstacle==true, then no obstacle
	// Must correct bug use field_[ instead of square for the if.
	enum class Movement {
		GO_UP,
		GO_DOWN,
		GO_LEFT,
		GO_RIGHT,
		GO_UP_RIGHT,
		GO_UP_LEFT,
		GO_DOWN_RIGHT,
		GO_DOWN_LEFT
	};
	Movement movement = Movement::GO_UP;
	int posX = pieceToMove->getPosX();
	int posY = pieceToMove->getPosY();
	if (!(pieceToMove->validationMouvement(movePosX, movePosY))) {
		return false;
	}

	if ((movePosX - posX >= 1) && (movePosY == posY))
	{
		movement = Movement::GO_RIGHT;
	}
	else if ((movePosX - posX <= -1) && (movePosY == posY))
	{
		movement = Movement::GO_LEFT;
	}

	else if ((movePosX == posX) && (movePosY - posY >= 1)) {
		movement = Movement::GO_DOWN;
	}
	else if ((movePosX == posX) && (movePosY - posY >= -1)) {
		movement = Movement::GO_UP;
	}

	else if ((movePosX - posX >= 1) && (movePosY - posY >= 1))
	{
		movement = Movement::GO_DOWN_RIGHT;
	}
	else if ((movePosX - posX >= 1) && (movePosY - posY <= -1))
	{
		movement = Movement::GO_UP_RIGHT;
	}

	else if ((movePosX - posX <= -1) && (movePosY - posY >= 1))
	{
		movement = Movement::GO_DOWN_LEFT;
	}

	else if ((movePosX - posX <= -1) && (movePosY - posY <= -1))
	{
		movement = Movement::GO_UP_LEFT;
	}

	while (posX != movePosX || posY != movePosY)
	{
		if (field_[posX][posY]->getHasPiece() 
			&& pieceToMove->getPosX()!=posX
			&& pieceToMove->getPosY()!=posY)
		{
			return false;
		}
		switch (movement) {
		case Movement::GO_RIGHT:
			posX++;
			break;
		case Movement::GO_LEFT:
			posX--;
			break;
		case Movement::GO_DOWN:
			posY++;
			break;
		case Movement::GO_UP:
			posY--;
			break;
		case Movement::GO_DOWN_RIGHT:
			posX++;
			posY++;
			break;
		case Movement::GO_DOWN_LEFT:
			posX--;
			posY++;
			break;
		case Movement::GO_UP_RIGHT:
			posX++;
			posY--;
			break;
		case Movement::GO_UP_LEFT:
			posX--;
			posY--;
			break;

		}

	}
	if (field_[movePosX][movePosY]->getPiece() == nullptr)
	{
		return true;
	}
	else if (pieceToMove->getPieceColor()
		!= field_[movePosX][movePosY]->getPiece()->getPieceColor())
	{
		return true;
	}
	return false;
}
bool Board::checkKing(King* king) {
	//if checkKing==true, then there's no King in check.
	//change the function if the piece of who is moved is the king
	int posX = king->getPosX();
	int posY = king->getPosY();
	if (king->getPieceColor() == "White")
	{
		for (auto piece : listOfBlack_)
		{
			if (checkObstacle(piece, posX, posY))
			{
				return false;
			}

		}
	}
	else {
		for (auto piece : listOfWhite_)
		{
			if (checkObstacle(piece, posX, posY))
			{
				return false;
			}
		}
	}
	return true;

}

bool Board::isValidMove(Piece* original, int movePosX, int movePosY) {
	if (!(original->validationMouvement(movePosX, movePosY)))
	{
		cout << "Mouvement non valide" << endl;
		return false;
	}
	if (original->getPieceColor() == "White")
	{
		if (!(checkObstacle(original,
			movePosX,
			movePosY)))
		{
			return false;
		}
		if (!(simulateNextPosition(original, movePosX, movePosY, whiteKing_))) 
		{
			return false;
		}
	}
	else
	{
		if (!(checkObstacle(original,movePosX,movePosY)))
		{
			return false;
		}
		if (!(simulateNextPosition(original, movePosX, movePosY, blackKing_))) 
		{
			return false;
		}
	}
	return true;
}
void Board::movePieceOnBoard(Piece* original, int movePosX, int movePosY) {
	Piece* temp_piece = nullptr;
	if (field_[movePosX][movePosY].get()->getHasPiece())
	{
		temp_piece = field_[movePosX][movePosY].get()->getPiece();
	}
	if (temp_piece != nullptr) {
		if (temp_piece->getPieceColor() == "White") {
			listOfWhite_.remove(temp_piece);
			delete temp_piece;
		}
		else {
			listOfBlack_.remove(temp_piece);
			delete temp_piece;
		}
	}
	int originalPosX = original->getPosX();
	int originalPosY = original->getPosY();
	original->setPosX(movePosX);
	original->setPosY(movePosY);
	field_[movePosX][movePosY]->putPieceOnSquare(original);
	field_[movePosX][movePosY]->setHasPiece(true);
	field_[originalPosX][originalPosY]->putPieceOnSquare(nullptr);
	field_[originalPosX][originalPosY]->setHasPiece(false);
	for (auto&& piece : listOfWhite_)
	{
		cout << typeid(*piece).name() << " " << piece->getPieceColor() << " "
			<< piece->getPosX() << ", " << piece->getPosY() << endl;
	}

	for (auto&& piece : listOfBlack_)
	{
		cout << typeid(*piece).name() << " " << piece->getPieceColor() << " "
			<< piece->getPosX() << ", " << piece->getPosY() << endl;
	}
}
bool Board::movePiece(Piece* original, int movePosX, int movePosY) {
	Piece* temp_piece = nullptr;
	if (field_[movePosX][movePosY].get()->getHasPiece())
	{
		temp_piece = field_[movePosX][movePosY].get()->getPiece();
	}
	if (!(original->validationMouvement(movePosX, movePosY)))
	{
		cout << "Mouvement non valide" << endl;
		return false;
	}
	if (original->getPieceColor() == "White")
	{
		if (!(checkObstacle(original,movePosX,movePosY)))
		{
			return false;
		}
		if (!(simulateNextPosition(original, movePosX, movePosY, whiteKing_))) {
			return false;
		}
	}
	else
	{
		if (!(checkObstacle(original,movePosX,movePosY)))
		{
			return false;
		}
			if (!(simulateNextPosition(original, movePosX, movePosY, blackKing_))) {
				return false;
			}
	}

	//New Bug, check bypass obstacles
	if (temp_piece != nullptr) {
		if (temp_piece->getPieceColor() == "White" && original->getPieceColor()=="Black") {
			listOfWhiteDead_.push_back(temp_piece);
			listOfWhite_.remove(temp_piece);
		}
		else if (temp_piece->getPieceColor() == "Black" && original->getPieceColor() == "White") {
			listOfBlackDead_.push_back(temp_piece);
			listOfBlack_.remove(temp_piece);
		}
	}
	int originalPosX = original->getPosX();
	int originalPosY = original->getPosY();
	original->setPosX(movePosX);
	original->setPosY(movePosY);
	field_[movePosX][movePosY]->putPieceOnSquare(original);
	field_[movePosX][movePosY]->setHasPiece(true);
	field_[originalPosX][originalPosY]->putPieceOnSquare(nullptr);
	field_[originalPosX][originalPosY]->setHasPiece(false);
	for (auto&& piece :listOfWhite_)
	{
		cout << typeid(*piece).name()<< " " <<piece->getPieceColor()<< " " 
			<< piece->getPosX() << ", " << piece->getPosY() << endl;
	}

	for (auto&& piece :listOfBlack_)
	{
		cout << typeid(*piece).name() << " " << piece->getPieceColor() << " "
			<< piece->getPosX() << ", " << piece->getPosY() << endl;
	}

	return true;
}
//int getField(int posX) {
//	return getField(posX);
//}




