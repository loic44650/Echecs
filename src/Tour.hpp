/**
 * @file Tour.hpp
 * @author MAHIER Loïc	&& COUILLEROT Carol
 * @since 24 sept. 2016
 * @brief Fichier header définissant une class 
**/


/**
 * @brief
 *
**/

class Tour : public Piece
{
	public:
		/**
 		 * @brief 
 		 *
 		 * @complexité
		**/
		Tour();

		/**
 		 * @brief 
 		 *
 		 * @complexité
		**/
		~Tour();

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
		void deplacement(Echiquier plateau);

	private:

};