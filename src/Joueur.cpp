#include "Joueur.hpp"


Joueur::Joueur(std::string nom, std::string prenom, char col) {
   nom_ = nom;
   prenom_ = prenom;
   col_ = col;
}

Joueur::~Joueur() {}

char Joueur::getCouleur() { return this->col_; }

//bool Joueur::colIsOk(Echiquier *e) { return e->getCouleur() == this->getCouleur(); }