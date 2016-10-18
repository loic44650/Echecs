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

#ifndef PIECE_HPP
#define PIECE_HPP

#include "MouvementHorizontal.hpp"
#include "MouvementVertical.hpp"
#include "MouvementDiagonale.hpp"
#include "MouvementCavalier.hpp"
#include "MouvementPion.hpp"
#include "MouvementRock.hpp"

class Piece
{
	public:
		/**
 		 * @brief
 		 *
 		 * @complexité
		**/
		Piece(int, bool, char);

		/**
 		 * @brief
 		 *
 		 * @complexité
		**/
		~Piece();

		/**
 		 * @brief
 		 *
 		 * @complexité
		**/
		virtual char afficher() = 0;

		/**
		 * @brief
		 *
		 * @complexité
		**/
		char getCouleur();

		bool pieceEnPosInit();

		void setPosInitiale(bool posInit);

		/**
 		 * @brief
 		 *
 		 * @complexité
		**/
		virtual bool moveTo(Coord dep, Coord but, Echiquier *e) = 0;

		virtual bool attaquer(Coord dep, Coord but, Echiquier *e) = 0;

		virtual bool roque(Coord dep, Coord but, Echiquier *e); 


	protected:
		int identifiant_;						// distinction des pieces
		bool posInitiale_;					// est sur position initiale (pours coups spéciaux)
		char c_;									// couleur
		std::vector<Mouvement*> mvmt_;

};

#endif
