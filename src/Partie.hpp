/**
 * @file Piece.hpp
 * @author MAHIER Loïc	&& COUILLEROT Carol
 * @since 24 sept. 2016
 * @brief Fichier header définissant une class piece gérant les différentes pieces de l'échiquier
**/

#pragma once

#include <iostream>
#include <vector>
#include "utils.hpp"
#include "Joueur.hpp"
#include "Echiquier.hpp"

#define NB_JOUEURS 2

class Partie
{
	public:

		/**
 		 * @brief 		 
 		 * @entrées 	
 		 * @sorties 	
		**/
		Partie();

		/**
 		 * @brief 		 
 		 * @entrées 	
 		 * @sorties 	
		**/
	    void setPartie(const std::string&);

		/**
 		 * @brief 		 
 		 * @entrées 	
 		 * @sorties 	
		**/
	    bool jouer(const Coord&, const Coord&);

		/**
 		 * @brief 		 
 		 * @entrées 	
 		 * @sorties 	
		**/
		Coord selectionnerPiece(std::string);

		/**
 		 * @brief 		 
 		 * @entrées 	
 		 * @sorties 	
		**/
      	void afficherMouvementPiece(const int);

		/**
 		 * @brief 		 
 		 * @entrées 	
 		 * @sorties 	
		**/
		int menu();

		/**
 		 * @brief 		 
 		 * @entrées 	
 		 * @sorties 	
		**/
		std::shared_ptr<Echiquier> getEchiquier();
		
		/**
 		 * @brief 		 
 		 * @entrées 	
 		 * @sorties 	
		**/
		void setJoueur(Joueur, int);

		/**
 		 * @brief 		 
 		 * @entrées 	
 		 * @sorties 	
		**/
		void init();

	private:
		int joueurActuel_;
      	Joueur joueur_[NB_JOUEURS];
      	std::shared_ptr<Echiquier> e_;
      	bool estEchec_;
      	Coord roiDe_[NB_JOUEURS];
};
