/**
 * @file Cavalier.hpp
 * @author MAHIER Loïc	&& COUILLEROT Carol
 * @since 24 sept. 2016
 * @brief Fichier header définissant une class 
**/


/**
 * @brief
 *
**/

class CAvalier : public Piece
{
	public:
		/**
 		 * @brief 
 		 *
 		 * @complexité
		**/
		Cavalier();

		/**
 		 * @brief 
 		 *
 		 * @complexité
		**/
		~Cavalier();

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