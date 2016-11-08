/**
 * @file Piece.hpp
 * @author MAHIER Loïc	&& COUILLEROT Carol
 * @since 24 sept. 2016
 * @brief Fichier header définissant une class piece gérant les différentes pieces de l'échiquier
**/


/**
 * @brief
 *
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

      Partie(const std::string& filename, const Joueur& j1, const Joueur& j2);

      void lancer();

      void jouer(const int numJoueur);

		Coord selectionnerPiece(std::string msg);

		void afficherMouvementPiece(const int numJoueur);

		int menu();

	private:
      Joueur joueur_[NB_JOUEURS];
      Echiquier e_;
      bool estEchec_;
      Coord roiDe_[NB_JOUEURS];


};