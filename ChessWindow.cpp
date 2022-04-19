/* Ce fichier est la classe ChessWindow qui s'occupe de la vue.
* @file: ChessWindow.cpp
* @authors: Gia-Sherwin Ly
* @matricule: 2137375
* @date:12 avril 2022
*/

#include "ChessWindow.hpp"
#pragma warning(push, 0) // Sinon Qt fait des avertissements à /W4.
#include <QHBoxLayout>
#include <QPushButton>
#include <QButtonGroup>
#include <QLabel>
#include <QString>
#include <QVariant>
#include <QPaintEvent>
#include <QMainWindow>
#include <QMessageBox>
#include <QInputDialog>
#include <Qt>
#pragma pop()
#include <iostream>
#include <type_traits>
#include "ChessWindow.hpp"
#include <cppitertools/range.hpp>
#include "ui_Vue.h"

using iter::range;

ChessWindow::ChessWindow(QWidget *parent) :
	QMainWindow(parent)
	, ui(new Ui::ChessWindow())
{
	ui->setupUi(this);
    for (int i = 0; i < ui->gridLayout->rowCount(); i++) {
        for (int j = 0; j < ui->gridLayout->columnCount(); j++) {
            QLayoutItem* item = ui->gridLayout->itemAtPosition(i, j);
            if (item->widget()) {
                QPushButton* square = qobject_cast<QPushButton*>(item->widget());
                //QSquareButton* squareButton = qobject_cast<QSquareButton*>(square);
                if ((i + j) % 2 == 0)
                {
                    square->setStyleSheet("background-color: white");
                }
                else {
                    square->setStyleSheet("background-color: gray");
                }
                square->move(j, i);
                //cout << square->x() << " " << square->y() << endl;
                QString texte = QString::number(square->x()) + " " + QString::number(square->y());
                square->setText(texte);
                square->setProperty("PosX", QVariant::fromValue<int>(j));
                square->setProperty("PosY", QVariant::fromValue<int>(i));
                
                connect(square, &QPushButton::clicked, this, &ChessWindow::checkSquare);
            }
        }
    }

   /* QPushButton* newGameButton= qobject_cast<QPushButton*>(ui->verticalLayout->itemAt(0)->widget());
    connect(newGameButton, &QPushButton::clicked, this, &ChessWindow::checkNewgame);*/
    
    //ui->gridLayout->itemAtPosition(1, 1);
}

ChessWindow:: ~ChessWindow() {
    delete ui;
}
void ChessWindow::checkSquare()
{   posX_=QObject::sender()->property("PosX").value<int>();
    posY_ = QObject::sender()->property("PosY").value<int>();
    button_ = qobject_cast<QPushButton*>(sender());
    emit squareClicked(button_, posX_, posY_);
}
//void ChessWindow::checkNewgame()
//{
//    emit newGameClicked();
//}
void ChessWindow::drawNewPiece(QString name, int posX, int posY) {
    QLayoutItem* item = ui->gridLayout->itemAtPosition(posY, posX);
    QPushButton* square = qobject_cast<QPushButton*>(item->widget());
    square->setText(name);

}
void ChessWindow::updateColorSquare(int posX, int posY, bool isSelected) {
    QLayoutItem* item = ui->gridLayout->itemAtPosition(posY, posX);
    QPushButton* square = qobject_cast<QPushButton*>(item->widget());
    if (isSelected){
        square->setStyleSheet("background-color: red");
    }
    else {
        if ((posX + posY) % 2 == 0)
        {
            square->setStyleSheet("background-color: white");
        }
        else {
            square->setStyleSheet("background-color: gray");
        }
    }
}
void ChessWindow::updatePlayerTurn(bool turn) {
    if (turn) {
        ui->playerTurnView->setText("It is the turn of White Player");
    }
    else {
        ui->playerTurnView->setText("It is the turn of Black Player");
    }
}

void ChessWindow::invalidMovementWarning() {
    QMessageBox::StandardButton msgBox;
    msgBox = QMessageBox::warning(this, "Illegal Move !",
        "Please try again");

}

void ChessWindow::on_actionPhilidor1777_triggered() {
    emit nameOfTheGameTyped("chessgame_files/philidor1777.txt");

}
void ChessWindow::on_actionTD6_Q2_3_Kings_triggered() {
    emit nameOfTheGameTyped("chessgame_files/TD6_Q2_Too_many_kings.txt");
}

void ChessWindow ::on_actionKnights_Of_The_Round_Table_triggered() {
    emit nameOfTheGameTyped("chessgame_files/Knights_Of_The_Round_Table.txt");
}

void ChessWindow::on_actiontest_stalemate_triggered() {
    emit nameOfTheGameTyped("chessgame_files/test_stalemate.txt");
}
void ChessWindow::showWinner(QString side) {
    QMessageBox::StandardButton msgBox;
    msgBox = QMessageBox::question(this, "Checkmate ! Winner is "+ side,
        "\nDo you want to start a new game or quit ?",
        QMessageBox::Yes | QMessageBox::No);
    if (msgBox == QMessageBox::Yes)
    {
        //reset board
        //board resetted
        emit startAnotherGameClicked();
    }
    else 
    {
        QApplication::quit();
    }
}

void ChessWindow::showStalemate() {
    QMessageBox::StandardButton msgBox;
    msgBox = QMessageBox::question(this, "Stalemate",
        "\nDo you want to start a new game or quit ?",
        QMessageBox::Yes | QMessageBox::No);
    if (msgBox == QMessageBox::Yes)
    {
        //reset board
        //board resetted
        emit startAnotherGameClicked();
    }
    else
    {
        QApplication::quit();
    }
}

void ChessWindow::warningKing() {
    QMessageBox::StandardButton msgBox;
    msgBox=QMessageBox::critical(this, "Instanciation of more than two kings",
        "The game may not have loaded properly.\n Do you still wish to continue ? ",
        QMessageBox::Yes | QMessageBox::No);
    if (msgBox == QMessageBox::Yes)
    {
        //reset board
        //board resetted
        return;
    }
    else
    {
        QApplication::quit();
    }
}