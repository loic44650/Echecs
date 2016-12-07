/**
 * @file Piece.hpp
 * @author MAHIER Loïc	&& COUILLEROT Carol
 * @since 24 sept. 2016
 * @brief Fichier header de la classe Pion héritant de la classe Piece
**/

#pragma once

#include "Piece.hpp"

class Pion: public Piece
{
	public:

		/**
 		 * @brief 		constructeur 
 		 * @entrées 	un booléen pour l'état de la pièce, un char pour sa couleur et un char pour sa direction soit 'N' soit 'S' (pour nord et sud)
 		 * @sorties 	aucunes
		**/
		Pion(bool, char, char);

		/**
  		 * @brief 		destructeur 
 		 * @entrées 	aucunes
 		 * @sorties 	aucunes
		**/
		~Pion();

		/**
 		 * @brief 		fonction affichant une pièce 
 		 * @entrées 	aucunes
 		 * @sorties 	retourne un caractère correspondant à la pièce, 'P' respectivement pour un pion
		**/
		char afficher();

		/**
 		 * @brief 		fonction virtuelle effectuant le mouvement d'un pion	
 		 * @entrées 	les coordonnées de départ et d'arrivée ainsi qu'un échuiquier
 		 * @sorties 	retourne un booléen indiquant si le déplacement a été effectué
		**/
		virtual bool moveTo(Coord, Coord, Echiquier*);

		/**
 		 * @brief 		fonction virtuelle effectuant le mouvement d'attaque d'un pion sur une autre pièce	
 		 * @entrées 	les coordonnées de départ et d'arrivée ainsi qu'un échuiquier
 		 * @sorties 	retourne un booléen indiquant si le mouvement d'attaque a été effectué
		**/
		virtual bool attaquer(Coord, Coord, Echiquier*);

		/**
 		 * @brief 		fonction virtuelle indiquant les mouvements réalisablent par un pion	
 		 * @entrées 	la coordonnée de départ de la pièce ainsi qu'un échuiquier
 		 * @sorties 	retourne un vector de coordonnées
		**/
		virtual std::vector<Coord> mouvementPossible(Coord, Echiquier*);
};