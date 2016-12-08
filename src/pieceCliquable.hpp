#pragma once

#include <QWidget>
#include <QLabel>
#include <iostream>
#include <memory>

class Controleur;
class Fenetre;

class PieceCliquable : public QLabel
{
	Q_OBJECT

		public:
    	
			/**
			 * @brief      
			 * @entrées   
			 * @sorties   
			**/   
    		explicit PieceCliquable(QWidget*, Fenetre*);
    	
			/**
			 * @brief      
			 * @entrées   
			 * @sorties   
			**/   
    		~PieceCliquable();

		signals:
    
			/**
			 * @brief      
			 * @entrées   
			 * @sorties   
			**/       
    		void clicked(PieceCliquable*);

		protected:

			/**
			 * @brief      
			 * @entrées   
			 * @sorties   
			**/       
    		void mousePressEvent(QMouseEvent*);

		private:
    
   			std::shared_ptr<Fenetre> fenetre_;
};