#pragma once
#include <QObject>
#include <QPushButton>
#include "ChessWindow.hpp"
#include "Game.hpp"
class Controleur : public QObject {

    Q_OBJECT

public:
    Controleur(Modele::Game* modele, ChessWindow* vue);
    ~Controleur();

public slots:
    void squareClicker(QPushButton* squareButton, int posX, int posY);
    void newGameClicker();
private:
    Modele::Game* modele_;
    ChessWindow* vue_;

};
