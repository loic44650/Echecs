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
 		 *
 		 * @complexité
		**/
		Partie();

		/**
 		 * @brief
 		 *
 		 * @complexité
		**/
	    void setPartie(const std::string& filename);

		/**
 		 * @brief
 		 *
 		 * @complexité
		**/
	    void lancer();

		/**
 		 * @brief
 		 *
 		 * @complexité
		**/
	    void jouer(const int numJoueur);

		/**
 		 * @brief
 		 *
 		 * @complexité
		**/
		Coord selectionnerPiece(std::string msg);

		/**
 		 * @brief
 		 *
 		 * @complexité
		**/
      	void afficherMouvementPiece(const int numJoueur);

		/**
 		 * @brief
 		 *
 		 * @complexité
		**/
		int menu();

		/**
 		 * @brief
 		 *
 		 * @complexité
		**/
		std::shared_ptr<Echiquier> getEchiquier();

		/**
 		 * @brief
 		 *
 		 * @complexité
		**/
		void setJoueur(Joueur j, int i);

	private:
		
      	Joueur joueur_[NB_JOUEURS];
      	std::shared_ptr<Echiquier> e_;
      	bool estEchec_;
      	Coord roiDe_[NB_JOUEURS];
};