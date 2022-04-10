#pragma once
// Le Modèle pour calculatrice simple.
// Par Francois-R.Boyer@PolyMtl.ca

#pragma warning(push, 0) // Sinon Qt fait des avertissements à /W4.
#include <QObject>
#include <QGraphicsPixmapItem>
#include <QGraphicsSceneMouseEvent>
#include "Square.hpp"
#include "Piece.hpp"
#include "Square.hpp"
#include "King.hpp"
#include "Player.hpp"
#include "Game.hpp"
#pragma pop()
#include <functional>


bool Game::checkKing() {
	return true;
}

void Game::setPlayer() {
	player1_ = make_unique<Player>();
	player2_=make_unique<Player>();
	player1_.get()->setName("White Player");
	player2_.get()->setName("Black Player");
	player1_.get()->setIsYourTurn(true);
	player2_.get()->setIsYourTurn(false);
}
