/**
 * @file Mouvement.hpp
 * @author MAHIER Loïc	&& COUILLEROT Carol
 * @since 07 oct. 2016
 * @brief Fichier header définissant la classe Mouvement
**/


#ifndef Mouvement_HPP
#define Mouvement_HPP

/**
 * @brief
 *
**/

#include <vector>
#include "utils.hpp" // contient struct Coord
#include "Echiquier.hpp"

class Mouvement
{
	public:
		/**
 		 * @brief
 		 *
 		 * @complexité
		**/
		Mouvement(int d, bool saut);

		/**
 		 * @brief
 		 *
 		 * @complexité
		**/
		~Mouvement();

		/**
 		 * @brief
 		 *
 		 * @complexité
		**/


		/**
 		 * @brief
 		 *
 		 * @complexité
		**/
		virtual bool isMoveOk(Coord &dep, Coord &but, Echiquier *e) = 0;

   private:

      int distance_;
      bool saut_;


};

#endif
