#include "Piece.hpp"

/**
 * @brief 		constructeur 
 * @entrées 	un booléen pour l'état de la pièce, et un char pour sa couleur
 * @sorties 	aucunes
**/
Piece::Piece(bool etat, char c) : posInitiale_(etat), c_(c) {}

/**
 * @brief 		destructeur 
 * @entrées 	aucunes
 * @sorties 	aucunes
**/
Piece::~Piece() {}

/**
 * @brief 		(getter) fonction retournant la couleur d'une pièce 
 * @entrées 	aucunes
 * @sorties 	retourne un char correspondant à la couleur de la pièce, soit 'B' soit 'N'
**/
char Piece::getCouleur() { return c_; }

/**
 * @brief 		fonction indiquant si la pièce est en position initiale ou non 
 * @entrées 	aucunes
 * @sorties 	retourne un boolléen, soit 'true' soit 'false'
**/
bool Piece::pieceEnPosInit() { return posInitiale_; }

/**
 * @brief 		(setter) procédure modifiant le booléen posInit d'une pièce	
 * @entrées 	un booléen correspondant au nouvel état de la pièce
 * @sorties 	aucunes
**/
void Piece::setPosInitiale(bool posInit) { posInitiale_ = posInit; }

/**
 * @brief 		fonction virtuelle effectuant le mouvement roque	
 * @entrées 	les coordonnées de départ et d'arrivée ainsi qu'un échuiquier
 * @sorties 	retourne un booléen indiquant si le mouvement roque a été effectué
**/
bool Piece::roquer(Coord dep, Coord but, Echiquier *e) { return false; }

/**
 * @brief 		fonction qui retourne le chemin du dernier déplacement
 * @entrées 	les coordonnées de départ et d'arrivée ainsi qu'un échuiquier
 * @sorties 	retourne un vector de coord indiquant 
**/
std::vector<Coord> Piece::chemin() 
{ 
	return cheminMvmt_; 
}
