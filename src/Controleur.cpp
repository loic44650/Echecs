#include "Controleur.hpp"

Controleur::Controleur(std::unique_ptr<Partie> p) 
{
	//std::unique_ptr<Partie> partie_(new Partie);
	std::unique_ptr<Partie> partie_(std::move(p));
}

void Controleur::setJoueur(Joueur j, int i) 
{
	partie_->setJoueur(j,i);
}