#include "Controleur.hpp"

Controleur::Controleur(std::shared_ptr<Partie> p)
{
	//std::unique_ptr<Partie> partie_(new Partie);
	partie_ = p;
}

void Controleur::setJoueur(Joueur j, int i)
{
	partie_->setJoueur(j,i);
}
