#pragma once
/* Ce fichier est la classe Game qui s'occupe de la logique du jeu
* @file: Game.cpp
* @authors: Gia-Sherwin Ly
* @matricule: 2137375
* @date:12 avril 2022
*/
#pragma warning(push, 0) // Sinon Qt fait des avertissements à /W4.
#include <QObject>
#include <QGraphicsPixmapItem>
#include <QGraphicsSceneMouseEvent>
#include "Square.hpp"
#include "Piece.hpp"
#include "Square.hpp"
#include "King.hpp"
#include "Game.hpp"
#pragma pop()
#include <functional>

Modele::Game::~Game(){
	delete board_;
}