/**
 * @file Piece.hpp
 * @author MAHIER Loïc	&& COUILLEROT Carol
 * @since 24 sept. 2016
 * @brief Fichier header de la classe Tour héritant de la classe Piece
**/

#pragma once

#include "Piece.hpp"

class Tour : public Piece
{
	public:

		/**
 		 * @brief 		constructeur 
 		 * @entrées 	un booléen pour l'état de la pièce et un char pour sa couleur
 		 * @sorties 	aucunes
		**/
		Tour(bool etat, char c);

		/**
  		 * @brief 		destructeur 
 		 * @entrées 	aucunes
 		 * @sorties 	aucunes
		**/
		~Tour();

		/**
 		 * @brief 		fonction affichant une pièce 
 		 * @entrées 	aucunes
 		 * @sorties 	retourne un caractère correspondant à la pièce, 'T' respectivement pour une tour
		**/
		char afficher();

		/**
 		 * @brief 		fonction virtuelle effectuant le mouvement d'un tour	
 		 * @entrées 	les coordonnées de départ et d'arrivée ainsi qu'un échuiquier
 		 * @sorties 	retourne un booléen indiquant si le déplacement a été effectué
		**/
		virtual bool moveTo(Coord dep, Coord but, Echiquier *e);

		/**
 		 * @brief 		fonction virtuelle effectuant le mouvement d'attaque d'une tour sur une autre piece	
 		 * @entrées 	les coordonnées de départ et d'arrivée ainsi qu'un échuiquier
 		 * @sorties 	retourne un booléen indiquant si le mouvement d'attaque a été effectué
		**/
		virtual bool attaquer(Coord dep, Coord but, Echiquier *e);

		/**
 		 * @brief 		fonction virtuelle effectuant le mouvement roque	
 		 * @entrées 	les coordonnées de départ et d'arrivée ainsi qu'un échuiquier
 		 * @sorties 	retourne un booléen indiquant si le mouvement roque a été effectué
		**/
		bool roquer(Coord dep, Coord but, Echiquier *e);

		/**
 		 * @brief 		fonction virtuelle indiquant les mouvements réalisablent par une tour
 		 * @entrées 	la coordonnée de départ de la pièce ainsi qu'un échuiquier
 		 * @sorties 	retourne un vector de coordonnées
		**/
		virtual std::vector<Coord> mouvementPossible(Coord dep, Echiquier *e);

	private:

		std::unique_ptr<Mouvement> roque_;		// définit le mouvement roque pour le roi
};