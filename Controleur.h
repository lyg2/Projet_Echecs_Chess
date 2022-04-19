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
signals:
    void drawPiece(QString name, int posX, int posY);
    void changeLocation(int posX, int posY);
    void colorSquare(int posX, int posY, bool isSelected);
    void playerTurn(bool);
    void invalidMovement();
    void checkmate(QString side);
    void moreThanTwoKings();
public slots:
    void squareClicker(QPushButton* squareButton, int posX, int posY);
    void newGameMenu(QString name);
    void startAnotherGameClicker();

private:
    Modele::Game* modele_;
    ChessWindow* vue_;

};
