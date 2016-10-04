/**
 * @file Fou.hpp
 * @author MAHIER Loïc	&& COUILLEROT Carol
 * @since 24 sept. 2016
 * @brief Fichier header définissant une class 
**/


/**
 * @brief
 *
**/

class Fou : public Piece
{
	public:
		/**
 		 * @brief 
 		 *
 		 * @complexité
		**/
		Fou();

		/**
 		 * @brief 
 		 *
 		 * @complexité
		**/
		~Fou();

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