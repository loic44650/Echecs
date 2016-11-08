#include "Controleur.hpp"

Controleur::Controleur(std::unique_ptr<Partie> p) {
	partie_ = p;
}

Controleur::~Controleur() {}

void Controleur::setJoueur(Joueur j, int i) {
	partie_->setJoueur(j,i);
}