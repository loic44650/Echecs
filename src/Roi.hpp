/**
 * @file Piece.hpp
 * @author MAHIER Loïc	&& COUILLEROT Carol
 * @since 24 sept. 2016
 * @brief Fichier header de la classe Roi héritant de la classe Piece
**/

#pragma once

#include "Piece.hpp"

class Roi : public Piece
{
	public:

		/**
 		 * @brief 		constructeur 
 		 * @entrées 	un booléen pour l'état de la pièce et un char pour sa couleur
 		 * @sorties 	aucunes
		**/
		Roi(bool, char);

		/**
  		 * @brief 		destructeur 
 		 * @entrées 	aucunes
 		 * @sorties 	aucunes
		**/
		~Roi();

		/**
 		 * @brief 		fonction affichant une pièce 
 		 * @entrées 	aucunes
 		 * @sorties 	retourne un caractère correspondant à la pièce, 'R' respectivement pour un roi
		**/
		char afficher();

		/**
 		 * @brief 		fonction virtuelle effectuant le mouvement d'un roi	
 		 * @entrées 	les coordonnées de départ et d'arrivée ainsi qu'un échuiquier
 		 * @sorties 	retourne un booléen indiquant si le déplacement a été effectué
		**/
		virtual bool moveTo(Coord, Coord, Echiquier*);

		/**
 		 * @brief 		fonction virtuelle effectuant le mouvement d'attaque d'un roi sur une autre piece	
 		 * @entrées 	les coordonnées de départ et d'arrivée ainsi qu'un échuiquier
 		 * @sorties 	retourne un booléen indiquant si le mouvement d'attaque a été effectué
		**/
		virtual bool attaquer(Coord, Coord, Echiquier*);

		/**
 		 * @brief 		fonction virtuelle effectuant le mouvement roque	
 		 * @entrées 	les coordonnées de départ et d'arrivée ainsi qu'un échuiquier
 		 * @sorties 	retourne un booléen indiquant si le mouvement roque a été effectué
		**/
		bool roquer(Coord, Coord, Echiquier*);

		/**
 		 * @brief 		fonction virtuelle indiquant les mouvements réalisablent par un roi	
 		 * @entrées 	la coordonnée de départ de la pièce ainsi qu'un échuiquier
 		 * @sorties 	retourne un vector de coordonnées
		**/
		virtual std::vector<Coord> mouvementPossible(Coord, Echiquier*);

	private:

		std::unique_ptr<Mouvement> roque_;		// définit le mouvement roque pour le roi
};