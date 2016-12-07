#pragma once

#include <iostream>
#include <memory>
#include <QtAlgorithms>
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
#include <QtGui>
#include "Controleur.hpp"
#include "pieceCliquable.hpp"


#define NB_CASES 8
#define NB_JOUEUR 5

class Fenetre : public QWidget
{
	Q_OBJECT

    public:
    	Fenetre(std::shared_ptr<Controleur> controleur);
		  ~Fenetre();
		  void cliqueSurPiece(QMouseEvent*, PieceCliquable* piece);


    public slots:
   		void ouvrirDialogueNewGameVSIA();
   		void ouvrirDialogueNewGameVSPlayer();
   		void ouvrirDialogueNewGameVSPlayerSuivant();
   		void ouvrirMessageAbout();

      void ecrireNom(QString);
      void ecrirePrenom(QString);
      void ecrireCol(QString);
      void ecrireNom2(QString);
      void ecrirePrenom2(QString);

      void startGameVSIA();
      void startGameVSPlayer();

      void affichageInitialEchiquier();
		  //void afficherEchiquier();


	protected:
		//void mouseReleaseEvent(QMouseEvent *qevent);

    private:
    	QPushButton *boutonNewGame_;
    	QPushButton *boutonNewGameBis_;
    	QPushButton *boutonAbout_;

      std::shared_ptr<Controleur> controleur_;
		  QString joueurs_[NB_JOUEUR];

      QLabel* plateau_;
		  PieceCliquable* cases[NB_CASES][NB_CASES];

      PieceCliquable *clicPrecedent_;
};
