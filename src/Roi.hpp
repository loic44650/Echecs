/**
 * @file Roi.hpp
 * @author MAHIER Loïc	&& COUILLEROT Carol
 * @since 24 sept. 2016
 * @brief Fichier header définissant une class
**/

#ifndef ROI_HPP
#define ROI_HPP

/**
 * @brief
 *
**/

#include "Piece.hpp"
#include <iostream>

class Roi : public Piece
{
	public:
		/**
 		 * @brief
 		 *
 		 * @complexité
		**/
		Roi(int id, bool etat, char c);

		/**
 		 * @brief
 		 *
 		 * @complexité
		**/
		~Roi();

		/**
 		 * @brief
 		 *
 		 * @complexité
		**/
		void afficher();

		/**
 		 * @brief
 		 *
 		 * @complexité
		**/
		//void deplacement(Echiquier plateau);

	private:
		bool echec_;
		bool echecEtMat_;
};

#endif
