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

class Roi : public Piece
{
	public:
		/**
 		 * @brief
 		 *
 		 * @complexité
		**/
		Roi(bool etat, char c);

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
		char afficher();

		/**
 		 * @brief
 		 *
 		 * @complexité
		**/

		virtual bool moveTo(Coord dep, Coord but, Echiquier *e);

		virtual bool attaquer(Coord dep, Coord but, Echiquier *e);

		bool roquer(Coord dep, Coord but, Echiquier *e);

	private:
		std::unique_ptr<Mouvement> roque_;
};

#endif
