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
#include <QtGui>
#include "Controleur.hpp"
#include "pieceCliquable.hpp"


#define NB 5
#define NB_PIONS 8
#define NB_ATOUTS 2

class Fenetre : public QWidget
{
	Q_OBJECT

    public:
    	Fenetre(std::shared_ptr<Controleur> controleur);
		~Fenetre();
		void cliqueSurPiece(PieceCliquable* piece);

	signals:
		void mouvementEffectue();

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
		  void afficherEchiquier();


	protected:
		void mouseReleaseEvent(QMouseEvent *qevent);

    private:
    	QPushButton *boutonNewGame_;
    	QPushButton *boutonNewGameBis_;
    	QPushButton *boutonAbout_;
      	std::shared_ptr<Controleur> controleur_;
		QString joueurs_[NB];

     	 QPixmap plateau_;
		PieceCliquable* pionB_[NB_PIONS];
		PieceCliquable* tourB_[NB_ATOUTS];
		PieceCliquable* cavalierB_[NB_ATOUTS];
		PieceCliquable* fouB_[NB_ATOUTS];
		PieceCliquable* reineB_;
		PieceCliquable* roiB_;
		PieceCliquable* pionN_[NB_PIONS];
		PieceCliquable* tourN_[NB_ATOUTS];
		PieceCliquable* cavalierN_[NB_ATOUTS];
		PieceCliquable* fouN_[NB_ATOUTS];
		PieceCliquable* reineN_;
		PieceCliquable* roiN_;

		PieceCliquable* clicDepart_;
		PieceCliquable* clicArrivee_;
};
