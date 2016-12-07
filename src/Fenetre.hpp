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

#define NB_CASES 8
#define NB_JOUEUR 5

class Fenetre : public QWidget
{
	Q_OBJECT

		public:

			/**
			 * @brief      
			 * @entrées   
			 * @sorties   
			**/      
			Fenetre(std::shared_ptr<Controleur>);
			/**
			 * @brief      
			 * @entrées   
			 * @sorties   
			**/          
			~Fenetre();
			/**
			 * @brief      
			 * @entrées   
			 * @sorties   
			**/          
			void cliqueSurPiece(PieceCliquable*);


		public slots:

			/**
			 * @brief      
			 * @entrées   
			 * @sorties   
			**/        
			void ouvrirDialogueNewGameVSIA();

			/**
			 * @brief      
			 * @entrées   
			 * @sorties   
			**/          
			void ouvrirDialogueNewGameVSPlayer();
			/**
			 * @brief      
			 * @entrées   
			 * @sorties   
			**/          
			void ouvrirDialogueNewGameVSPlayerSuivant();

			/**
			 * @brief      
			 * @entrées   
			 * @sorties   
			**/       		
			void ouvrirMessageAbout();

			/**
			 * @brief      
			 * @entrées   
			 * @sorties   
			**/    
			void ecrireNom(QString);

			/**
			 * @brief      
			 * @entrées   
			 * @sorties   
			**/    
			void ecrirePrenom(QString);

			/**
			 * @brief      
			 * @entrées   
			 * @sorties   
			**/          
			void ecrireCol(QString);

			/**
			 * @brief      
			 * @entrées   
			 * @sorties   
			**/          
			void ecrireNom2(QString);

			/**
			 * @brief      
			 * @entrées   
			 * @sorties   
			**/          
			void ecrirePrenom2(QString);

			/**
			 * @brief      
			 * @entrées   
			 * @sorties   
			**/    
			void startGameVSIA();

			/**
			 * @brief      
			 * @entrées   
			 * @sorties   
			**/          
			void startGameVSPlayer();

			/**
			 * @brief      
			 * @entrées   
			 * @sorties   
			**/    
			void affichageInitialEchiquier();

		private:

			QPushButton *boutonNewGame_;
			QPushButton *boutonNewGameBis_;
			QPushButton *boutonAbout_;
			QLabel* plateau_;
			std::shared_ptr<Controleur> controleur_;
			QString joueurs_[NB_JOUEUR];
			PieceCliquable* cases[NB_CASES][NB_CASES];
			PieceCliquable *clicPrecedent_;
};
