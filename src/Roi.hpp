/**
 * @file Roi.hpp
 * @author MAHIER Loïc	&& COUILLEROT Carol
 * @since 24 sept. 2016
 * @brief Fichier header définissant une class 
**/


/**
 * @brief
 *
**/

class Roi : public Piece
{
	public:
		/**
 		 * @brief 
 		 *
 		 * @complexité
		**/
		Roi();

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
		void deplacement(Echiquier plateau);

	private:
		bool echec_;
		bool echecEtMat_;
};