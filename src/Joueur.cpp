#include "Joueur.hpp"

Joueur::Joueur() {}

Joueur::Joueur(std::string nom, std::string prenom, char col) : nom_(nom), prenom_(prenom), col_(col) {}

Joueur::~Joueur() {}

std::string Joueur::sePresenter() {
   return nom_+" "+prenom_+", joue les "+col_;
}

char Joueur::getCouleur() { return col_; }
