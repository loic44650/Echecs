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
#include "Controleur.hpp"


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
   		void startGame();

    private:
    	QPushButton *boutonNewGame_;
    	QPushButton *boutonNewGameBis_;
    	QPushButton *boutonAbout_;
      std::shared_ptr<Controleur> controleur_;

};
