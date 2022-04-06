#pragma once
// La Vue-Controlleur pour calculatrice simple.
// Par Francois-R.Boyer@PolyMtl.ca

#include "Game.hpp"
#pragma warning(push, 0) // Sinon Qt fait des avertissements à /W4.
#include <QMainWindow>
#include <QPushButton>
#include <QString>
#include <QLabel>
#pragma pop()

class ChessWindow : public QMainWindow {
	Q_OBJECT
public:
	ChessWindow(QWidget* parent = nullptr);
	~ChessWindow() override = default;
};