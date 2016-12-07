/**
 * @file Piece.hpp
 * @author MAHIER Loïc	&& COUILLEROT Carol
 * @since 24 sept. 2016
 * @brief Fichier header définissant une classe pièce gérant les différentes pièces de l'échiquier
**/

#pragma once

#include "Mouvement.hpp"
#include "MouvementHorizontal.hpp"
#include "MouvementVertical.hpp"
#include "MouvementDiagonale.hpp"
#include "MouvementCavalier.hpp"
#include "MouvementPion.hpp"
#include "MouvementRoque.hpp"

class Piece
{
	public:

		/**
 		 * @brief 		constructeur 
 		 * @entrées 	un booléen pour l'état de la pièce, et un char pour sa couleur
 		 * @sorties 	aucunes
		**/
		Piece(bool, char);

		/**
  		 * @brief 		destructeur 
 		 * @entrées 	aucunes
 		 * @sorties 	aucunes
		**/
		~Piece();

		/**
 		 * @brief 		fonction virtuelle affichant une pièce 
 		 * @entrées 	aucunes
 		 * @sorties 	retourne un caractère correspondant à la pièce, 'P' par exemple pour un pion
		**/
		virtual char afficher() = 0;

		/**
 		 * @brief 		(getter) fonction retournant la couleur d'une pièce 
 		 * @entrées 	aucunes
 		 * @sorties 	retourne un char correspondant à la couleur de la pièce, soit 'B' soit 'N'
		**/
		char getCouleur();

		/**
 		 * @brief 		fonction indiquant si la pièce est en position initiale ou non 
 		 * @entrées 	aucunes
 		 * @sorties 	retourne un boolléen, soit 'true' soit 'false'
		**/
		bool pieceEnPosInit();

		/**
 		 * @brief 		(setter) procédure modifiant le booléen posInit d'une pièce	
 		 * @entrées 	un booléen correspondant au nouvel état de la pièce
 		 * @sorties 	aucunes
		**/
		void setPosInitiale(bool);

		/**
 		 * @brief 		fonction virtuelle effectuant le mouvement d'une pièce	
 		 * @entrées 	les coordonnées de départ et d'arrivée ainsi qu'un échuiquier
 		 * @sorties 	retourne un booléen indiquant si le déplacement a été effectué
		**/
		virtual bool moveTo(Coord, Coord, Echiquier*) = 0;

		/**
 		 * @brief 		fonction virtuelle effectuant le mouvement d'attaque d'une pièce sur une autres	
 		 * @entrées 	les coordonnées de départ et d'arrivée ainsi qu'un échuiquier
 		 * @sorties 	retourne un booléen indiquant si le mouvement d'attaque a été effectué
		**/
		virtual bool attaquer(Coord, Coord, Echiquier*) = 0;

		/**
 		 * @brief 		fonction virtuelle effectuant le mouvement roque	
 		 * @entrées 	les coordonnées de départ et d'arrivée ainsi qu'un échuiquier
 		 * @sorties 	retourne un booléen indiquant si le mouvement roque a été effectué
		**/
		virtual bool roquer(Coord, Coord, Echiquier*);

		/**
 		 * @brief 		fonction virtuelle indiquant les mouvements réalisablent par une pièce	
 		 * @entrées 	la coordonnée de départ de la pièce ainsi qu'un échuiquier
 		 * @sorties 	retourne un vector de coordonnées
		**/
		virtual std::vector<Coord> mouvementPossible(Coord, Echiquier*) = 0;

	protected:

		bool posInitiale_;					// pièce sur sa position initiale ou non (pour coups spéciaux)
		char c_;							// couleur de la pièce
		std::vector<Mouvement*> mvmt_;		// contient les types de mouvement que peut effectuer une pièce
};