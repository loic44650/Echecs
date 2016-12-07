#include "Joueur.hpp"

/**
 * @brief 		constructeur vide
 * @entrées 	aucunes
 * @sorties 	aucunes
**/
Joueur::Joueur() {}

/**
 * @brief 		constructeur	
 * @entrées 	deux string pour le nom et le prenom ainsi qu'un char pour la couleur
 * @sorties 	aucunes
**/
Joueur::Joueur(std::string nom, std::string prenom, char col) : nom_(nom), prenom_(prenom), col_(col) {}

/**
 * @brief 		destructeur
 * @entrées 	aucunes
 * @sorties 	aucunes
**/
Joueur::~Joueur() {}

/**
 * @brief 		fonction affichant le nom, le prenom et la couleur d'un joueur	
 * @entrées 	aucunes
 * @sorties 	retourne une chaine de caractère comprenant le nom, le prenom et la couleur d'un joueur
**/
std::string Joueur::sePresenter() 
{
   	return nom_+" "+prenom_+", joue les "+col_;
}

/**
 * @brief 		(getter) fonction retournant la couleur d'un joueur	
 * @entrées 	aucunes
 * @sorties 	retourne un char correspondant à la couleur d'un joueur
**/
char Joueur::getCouleur() { return col_; }

/**
 * @brief 		(setter) procédure modifiant un joueur	
 * @entrées 	un joueur
 * @sorties 	aucunes
**/
void Joueur::setJoueur(Joueur j) 
{ 
	nom_ = j.nom_;
	prenom_ = j.prenom_;
	col_ = j.col_;
}