#pragma once

#include <iostream>
#include <memory>
#include <QApplication>
#include <QWidget>
#include <QPushButton>
#include <QMessageBox>
#include <QLineEdit>
#include <QFormLayout>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QComboBox>
#include <QLabel>
#include <QImage>
#include <QString>
#include <QObject>
#include "Controleur.hpp"

#define NB 3

class Fenetre : public QWidget
{

	Q_OBJECT

    public:
    	Fenetre(std::shared_ptr<Controleur> controleur);

    public slots:
   		void ouvrirDialogueNewGameVSIA();
   		void ouvrirDialogueNewGameVSPlayer();
   		void ouvrirDialogueNewGameVSPlayerSuivant();
   		void ouvrirMessageAbout();
		void ecrireNom(QString);
        void ecrirePrenom(QString);
        void ecrireCol(QString);
   		void startGame();

    private:
    	QPushButton *boutonNewGame_;
    	QPushButton *boutonNewGameBis_;
    	QPushButton *boutonAbout_;
        std::shared_ptr<Controleur> controleur_;
		QString joueurs_[NB];
};
