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


#define NB 5

class Fenetre : public QWidget
{

	Q_OBJECT

    public:
    	Fenetre(std::shared_ptr<Controleur> controleur);

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
		QLabel pionB_;
		QLabel tourB_;
		QLabel cavalierB_;
		QLabel fouB_;
		QLabel reineB_;
		QLabel roiB_;
		QLabel pionN_;
		QLabel tourN_;
		QLabel cavalierN_;
		QLabel fouN_;
		QLabel reineN_;
		QLabel roiN_;

};
