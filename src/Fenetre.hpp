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
#include "Controleur.hpp"


class Fenetre : public QWidget
{

	Q_OBJECT

    public:
    	Fenetre(std::shared_ptr<Controleur> controleur);

    signals:
        void sendText(QString name, QString firstname, QString col);

    public slots:
        void ouvrirDialogueNewGameVSIA();
        void ouvrirDialogueNewGameVSPlayer();
        void ouvrirDialogueNewGameVSPlayerSuivant();
        void ouvrirMessageAbout();
        void startGame(QString name, QString firstname, QString col);

    private:
    	QPushButton *boutonNewGame_;
    	QPushButton *boutonNewGameBis_;
    	QPushButton *boutonAbout_;
        std::shared_ptr<Controleur> controleur_;

};
