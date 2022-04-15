#pragma once
// La Vue-Controlleur pour calculatrice simple.
// Par Francois-R.Boyer@PolyMtl.ca

#include "Game.hpp"
#pragma warning(push, 0) // Sinon Qt fait des avertissements à /W4.
#include <QMainWindow>
#include <QPushButton>
#include <QString>
#include <QLabel>
#include <QMessageBox>
#include <QInputDialog>
#include <Qt>
#pragma pop()

QT_BEGIN_NAMESPACE
namespace Ui { class ChessWindow; }
QT_END_NAMESPACE

class ChessWindow : public QMainWindow {
	Q_OBJECT
public:
	ChessWindow(QWidget* parent = nullptr);
	~ChessWindow();

signals:
	void squareClicked(QPushButton* button, int posX, int posY);
	void newGameClicked();

private slots:
	void checkSquare();
	void checkNewgame();

private:
	Ui::ChessWindow* ui;
	QPushButton* button_;
	int posX_;
	int posY_;

};