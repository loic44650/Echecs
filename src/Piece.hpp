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
		virtual void deplacement(Coord &c, Echiquier &e) = 0;



	protected:
		int identifiant_;								// distinction des pieces
		bool statut_;									// en jeu ou non
		char c_;									// couleur
		std::vector<Mouvement> mvmt_;

};

#endif
