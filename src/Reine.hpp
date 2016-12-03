/**
 * @file Piece.hpp
 * @author MAHIER Loïc	&& COUILLEROT Carol
 * @since 24 sept. 2016
 * @brief Fichier header de la classe Reine héritant de la classe Piece
**/

#pragma once

#include "Piece.hpp"

class Reine : public Piece
{
	public:

		/**
 		 * @brief 		constructeur 
 		 * @entrées 	un booléen pour l'état de la pièce et un char pour sa couleur
 		 * @sorties 	aucunes
		**/
		Reine(bool etat, char c);

		/**
  		 * @brief 		destructeur 
 		 * @entrées 	aucunes
 		 * @sorties 	aucunes
		**/
		~Reine();


		/**
 		 * @brief 		fonction affichant une pièce 
 		 * @entrées 	aucunes
 		 * @sorties 	retourne un caractère correspondant à la pièce, 'D respectivement pour une reine
		**/
		char afficher();

		/**
 		 * @brief 		fonction virtuelle effectuant le mouvement d'une reine	
 		 * @entrées 	les coordonnées de départ et d'arrivée ainsi qu'un échuiquier
 		 * @sorties 	retourne un booléen indiquant si le déplacement a été effectué
		**/
		virtual bool moveTo(Coord dep, Coord but, Echiquier *e);

		/**
 		 * @brief 		fonction virtuelle effectuant le mouvement d'attaque d'une reine sur une autre piece	
 		 * @entrées 	les coordonnées de départ et d'arrivée ainsi qu'un échuiquier
 		 * @sorties 	retourne un booléen indiquant si le mouvement d'attaque a été effectué
		**/
		virtual bool attaquer(Coord dep, Coord but, Echiquier *e);

		/**
 		 * @brief 		fonction virtuelle indiquant les mouvements réalisablent par une reine	
 		 * @entrées 	la coordonnée de départ de la pièce ainsi qu'un échuiquier
 		 * @sorties 	retourne un vector de coordonnées
		**/
		virtual std::vector<Coord> mouvementPossible(Coord dep, Echiquier *e);
};