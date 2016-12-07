/**
 * @file Piece.hpp
 * @author MAHIER Loïc	&& COUILLEROT Carol
 * @since 24 sept. 2016
 * @brief Fichier header définissant une classe Joueur gérant les caractéristiques des joueurs
**/

#pragma once

#include <string>

class Piece;

class Joueur
{
	public:

		/**
 		 * @brief 		constructeur vide
 		 * @entrées 	aucunes
 		 * @sorties 	aucunes
		**/
		Joueur();

		/**
 		 * @brief 		constructeur	
 		 * @entrées 	deux string pour le nom et le prenom ainsi qu'un char pour la couleur
 		 * @sorties 	aucunes
		**/
		Joueur(std::string, std::string, char);

		/**
 		 * @brief 		destructeur
 		 * @entrées 	aucunes
 		 * @sorties 	aucunes
		**/
		~Joueur();

		/**
 		 * @brief 		fonction affichant le nom, le prenom et la couleur d'un joueur	
 		 * @entrées 	aucunes
 		 * @sorties 	retourne une chaine de caractère comprenant le nom, le prenom et la couleur d'un joueur
		**/
		std::string sePresenter();

		/**
 		 * @brief 		(getter) fonction retournant la couleur d'un joueur	
 		 * @entrées 	aucunes
 		 * @sorties 	retourne un char correspondant à la couleur d'un joueur
		**/
		char getCouleur();

		/**
 		 * @brief 		(setter) procédure modifiant un joueur	
 		 * @entrées 	un joueur
 		 * @sorties 	aucunes
		**/
		void setJoueur(Joueur);

	private:

		std::string nom_;			// nom du joueur
		std::string prenom_;		// prenom du joueur
		char col_;					// couleur du joueur (soit 'N' soit 'B')
};