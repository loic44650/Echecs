/**
 * @file Joueur.hpp
 * @author MAHIER Loïc	&& COUILLEROT Carol
 * @since 24 sept. 2016
 * @brief Fichier header définissant une class
**/

#pragma once

#include <string>

class Piece;

class Joueur
{
	public:

		Joueur();
		/**
 		 * @brief
 		 *
 		 * @complexité
		**/
		Joueur(std::string nom, std::string prenom, char col);

		/**
 		 * @brief
 		 *
 		 * @complexité
		**/
		~Joueur();

		std::string sePresenter();

		char getCouleur();

		//bool colIsOk(Piece p);

	private:
		std::string nom_;
		std::string prenom_;
		char col_;

};
