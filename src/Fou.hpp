/**
 * @file Piece.hpp
 * @author MAHIER Loïc	&& COUILLEROT Carol
 * @since 24 sept. 2016
 * @brief Fichier header de la classe Fou héritant de la classe Piece
**/

#pragma once

#include "Piece.hpp"

class Fou : public Piece
{
	public:

		/**
 		 * @brief 		constructeur 
 		 * @entrées 	un booléen pour l'état de la pièce et un char pour sa couleur
 		 * @sorties 	aucunes
		**/
		Fou(bool, char);

		/**
  		 * @brief 		destructeur 
 		 * @entrées 	aucunes
 		 * @sorties 	aucunes
		**/
		~Fou();

		/**
 		 * @brief 		fonction affichant une pièce 
 		 * @entrées 	aucunes
 		 * @sorties 	retourne un caractère correspondant à la pièce, 'F' respectivement pour un fou
		**/
		char afficher();

		/**
 		 * @brief 		fonction virtuelle effectuant le mouvement d'un fou	
 		 * @entrées 	les coordonnées de départ et d'arrivée ainsi qu'un échuiquier
 		 * @sorties 	retourne un booléen indiquant si le déplacement a été effectué
		**/
		virtual bool moveTo(Coord, Coord, Echiquier*);

		/**
 		 * @brief 		fonction virtuelle effectuant le mouvement d'attaque d'un fou sur une autre piece	
 		 * @entrées 	les coordonnées de départ et d'arrivée ainsi qu'un échuiquier
 		 * @sorties 	retourne un booléen indiquant si le mouvement d'attaque a été effectué
		**/
		virtual bool attaquer(Coord, Coord, Echiquier*);

		/**
 		 * @brief 		fonction virtuelle indiquant les mouvements réalisablent par un fou	
 		 * @entrées 	la coordonnée de départ de la pièce ainsi qu'un échuiquier
 		 * @sorties 	retourne un vector de coordonnées
		**/
		virtual std::vector<Coord> mouvementPossible(Coord, Echiquier*);
};