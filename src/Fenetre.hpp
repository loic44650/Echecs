#ifndef DEF_FENETRE
#define DEF_FENETRE

#include <iostream>
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


class Fenetre : public QWidget
{

	Q_OBJECT

    public:
    	Fenetre();

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

};

#endif