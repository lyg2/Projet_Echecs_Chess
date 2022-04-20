/* Ce fichier est la classe King qui hérite de Pièce.
* @file: King.hpp
* @authors: Gia-Sherwin Ly
* @matricule: 2137375
* @date:12 avril 2022
*/

#pragma once
#pragma warning(push, 0) // Sinon Qt fait des avertissements à /W4.
#include <QObject>
#include <QGraphicsPixmapItem>
#include <QGraphicsSceneMouseEvent>
#include "Square.hpp"
#include "Piece.hpp"
#pragma pop()
#include <functional>

using namespace std; // Dans ce cours on accepte le using namespace std dans le .hpp .

class Square;

using namespace std; // Dans ce cours on accepte le using namespace std dans le .hpp .

class King : public Piece
{
public:
	King();
	virtual ~King();
	static int getCount() { return count_; };
	bool validationMouvement(int posXApres, int posYApres) override;
	QString getNamePiece() override;
private:
	static int count_;

};

