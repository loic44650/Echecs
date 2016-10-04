/**
 * @file Reine.hpp
 * @author MAHIER Loïc	&& COUILLEROT Carol
 * @since 24 sept. 2016
 * @brief Fichier header définissant une class 
**/


/**
 * @brief
 *
**/

class Reine : public Piece
{
	public:
		/**
 		 * @brief 
 		 *
 		 * @complexité
		**/
		Reine();

		/**
 		 * @brief 
 		 *
 		 * @complexité
		**/
		~Reine();

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