#include "Controleur.hpp"

Controleur::Controleur(std::shared_ptr<Partie> p)
{
	//std::unique_ptr<Partie> partie_(new Partie);
	partie_ = p;
}

void Controleur::jouerContreIA(std::string nom, std::string prenom, std::string coul) {
	if(!nom.empty() && !prenom.empty()) {
		std::cerr << "ca marche" << std::endl;
		char col = coul[0];
		partie_->setJoueur(Joueur(nom,prenom,col), 0);
		col = (coul == "Blanc") ? 'N' : 'B';
		partie_->setJoueur(Joueur("Artificial","Intelligence",col), 1);
	}
	else
		std::cerr << "Ca ne marche pas!!!!!!!!!!F**$!" << std::endl;
}

void Controleur::setJoueur(Joueur j, int i)
{
	partie_->setJoueur(j,i);
}
