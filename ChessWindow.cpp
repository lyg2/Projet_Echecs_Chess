// La Vue-Controlleur pour calculatrice simple.
// Par Francois-R.Boyer@PolyMtl.ca

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
#pragma pop()
#include <iostream>
#include <type_traits>
#include <cppitertools/range.hpp>
#include "QSquareButton.h"
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

    QPushButton* newGameButton= qobject_cast<QPushButton*>(ui->verticalLayout->itemAt(0)->widget());
    connect(newGameButton, &QPushButton::clicked, this, &ChessWindow::checkNewgame);
    
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
void ChessWindow::checkNewgame()
{
    emit newGameClicked();
}
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
        ui->playerTurnView->setText("Is is the turn of White Player");
    }
    else {
        ui->playerTurnView->setText("Is is the turn of Black Player");
    }
}
//template <typename T>
//QPushButton* CalcWindow::nouveauBouton(const QString& text, const T& slot)
//{
//	auto bouton = new QPushButton(this);
//	bouton->setText(text);
//	bouton->setFixedSize(40, 40);
//	if constexpr (!is_same_v<T, decltype(nullptr)>)
//		QObject::connect(bouton, &QPushButton::clicked, &calc_, slot);
//	return bouton;
//}
//
//CalcWindow::CalcWindow(QWidget* parent) :
//	QMainWindow(parent)
//{
//	// Si on objet n'a pas encore de parent on lui met "this" comme parent en attendant, si possible, pour s'assurer que tous les pointeurs sont gérés par un delete automatique en tout temps sans utiliser de unique_ptr.
//	auto widgetPrincipal = new QWidget(this);
//	auto layoutPrincipal = new QVBoxLayout(widgetPrincipal);  // Donner un parent à un layout est comme un setLayout.
//
//	// Pour faire la série de 10 boutons qui doivent tous appeler la même fonction du modèle mais avec des valeurs différentes d'argument, voici trois manières de le faire:
//	
//	// ------------------------------------------------------------
//	// Version avec lambdas:
//	{
//		auto layout = new QHBoxLayout(); // Pas possible de donner directement le parent au layout (le constructeur prend un QWidget* et un layout n'en est pas un; on ne peut pas mettre un parent qui a déjà un layout; si on met on parent temporaire, addLayout n'accepte pas de changer le parent).
//		layoutPrincipal->addLayout(layout);
//
//		layout->setSpacing(0);
//		for (int i : range(10))
//			layout->addWidget(nouveauBouton(QString::number(i), [this,i]() { calc_.ajouterChiffre(i); }));
//
//		layout->addSpacing(10);
//		layout->addWidget(nouveauBouton("+", &Calc::operationPlus));
//		layout->addWidget(nouveauBouton("-", &Calc::operationMoins));
//		layout->addWidget(nouveauBouton("=", &Calc::operationEgal));
//
//		layout->addSpacing(10);
//		auto label = new QLabel(this);
//		label->setMinimumWidth(100);
//		// On pourrait connecter un slot (on en a un pour l'autre exemple) mais ici c'était simple comme ça et c'est la version avec lambdas.
//		QObject::connect(&calc_, &Calc::valeurChangee, this, [label](int valeur) {
//			label->setText(QString::number(valeur));
//		});
//		layout->addWidget(label);
//	}
//
//	// ------------------------------------------------------------
//	// Version avec QButtonGroup:
//	{
//		auto layout = new QHBoxLayout();
//		layoutPrincipal->addLayout(layout);
//
//		layout->setSpacing(0);
//		auto groupeBoutons = new QButtonGroup(this);
//		for (int i : range(10)) {
//			auto bouton = nouveauBouton(QString::number(i));
//			groupeBoutons->addButton(bouton, i); // L'ID du bouton est i (doit être un entier).
//			layout->addWidget(bouton);
//		}
//		#if QT_VERSION >= QT_VERSION_CHECK(5,15,0)  // Le nom du signal idClicked existe depuis Qt 5.15
//		QObject::connect(groupeBoutons, &QButtonGroup::idClicked, &calc_, &Calc::ajouterChiffre); // ajouterChiffre prend un int, donc le ID du bouton est bon directement.
//		#else
//		QObject::connect(groupeBoutons, SIGNAL(buttonClicked(int)), &calc_, SLOT(ajouterChiffre(int)));
//		#endif
//
//		layout->addSpacing(10);
//		layout->addWidget(nouveauBouton("+", &Calc::operationPlus));
//		layout->addWidget(nouveauBouton("-", &Calc::operationMoins));
//		layout->addWidget(nouveauBouton("=", &Calc::operationEgal));
//
//		layout->addSpacing(10);
//		auto label = new QLabel(this);
//		affichage_ = label;
//		label->setMinimumWidth(100);
//		QObject::connect(&calc_, &Calc::valeurChangee, this, &CalcWindow::changerValeurAffichee);
//		layout->addWidget(label);
//	}
//
//	// ------------------------------------------------------------
//	// Version avec setProperty:
//	{
//		auto layout = new QHBoxLayout();
//		layoutPrincipal->addLayout(layout);
//
//		layout->setSpacing(0);
//		for (int i : range(10)) {
//			auto bouton = nouveauBouton(QString::number(i));
//			// On donne un nom à la propriété, et on lui donne une valeur QVariant (comme dans les notes de cours) d'un type quelconque (doit enregistrer le type avec Q_DECLARE_METATYPE(LeType) si ce n'est pas un type déjà connu de Qt).
//			bouton->setProperty("chiffre", QVariant::fromValue<int>(i));
//			QObject::connect(bouton, &QPushButton::clicked, this, &CalcWindow::chiffreAppuye);
//			layout->addWidget(bouton);
//		}
//
//		layout->addSpacing(10);
//		layout->addWidget(nouveauBouton("+", &Calc::operationPlus));
//		layout->addWidget(nouveauBouton("-", &Calc::operationMoins));
//		layout->addWidget(nouveauBouton("=", &Calc::operationEgal));
//
//		// On ne met pas un autre affichage, on en a déjà deux versions différentes.
//		layout->addSpacing(110);
//	}
//
//	setCentralWidget(widgetPrincipal);
//	setWindowTitle("Calculatrice simple");
//}
//
//
//// Pour la version QButtonGroup.
//// Pourrait aussi être sans paramètre et faire calc_.obtenirValeur()
//void CalcWindow::changerValeurAffichee(int valeur)
//{
//	affichage_->setText(QString::number(valeur));
//}
//
//
//// Pour la version setProperty.
//void CalcWindow::chiffreAppuye()
//{
//	// QObject::sender() est l'objet d'où vient le signal connecté à ce slot; attention qu'il sera nullptr si le slot est appelé directement au lieu de passer par un signal.
//	calc_.ajouterChiffre(QObject::sender()->property("chiffre").value<int>());
//}
