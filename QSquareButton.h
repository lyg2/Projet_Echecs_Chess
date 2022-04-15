#pragma once
// Le Modèle pour calculatrice simple.
// Par Francois-R.Boyer@PolyMtl.ca

#pragma warning(push, 0) // Sinon Qt fait des avertissements à /W4.
#include <QObject>
#include <QGraphicsRectItem>
#include <QBrush>
#include <QGraphicsSceneMouseEvent>
#include <QPushButton>
#pragma pop()

class QSquareButton : public QPushButton {
	Q_OBJECT
public: 
	QSquareButton(int posX, int posY, QWidget* parent = 0);
	virtual int getPosX() {return posX_;};
	virtual int getPosY() { return posY_; };
	virtual void setPosX(int posX) { posX_ = posX; };
	virtual void setPosY(int posY) { posY_ = posY; };
private:
	int posX_;
	int posY_;
};
