#include "Controleur.hpp"

Controleur::Controleur(std::shared_ptr<Partie> p)
{
	//std::unique_ptr<Partie> partie_(new Partie);
	partie_ = p;
}

void Controleur::jouerContreIA(std::string nom, std::string prenom, std::string coul)
{
	if(!nom.empty() && !prenom.empty()) 
	{
		std::cerr << "Controleur : ca marche" << std::endl;
		char col = coul[0];
		
		partie_->setJoueur(Joueur(nom,prenom,col), 0);
		
		col = (coul == "Blanc") ? 'N' : 'B';
		partie_->setJoueur(Joueur("Artificial","Intelligence",col), 1);

		std::cerr << "Joueur créé" << std::endl;
	}
	else
		std::cerr << "Ca ne marche pas!!!!!!!!!!F**$!" << std::endl;
}

void Controleur::jouerContrePlayer(std::string nom, std::string prenom, std::string coul, std::string nom2, std::string prenom2) 
{
	if(!nom.empty() && !prenom.empty()) 
	{
		std::cerr << "Controleur : ca marche" << std::endl;
		char col = coul[0];

		partie_->setJoueur(Joueur(nom,prenom,col), 0);
		
		col = (coul == "Blanc") ? 'N' : 'B';
		partie_->setJoueur(Joueur(nom2, prenom2, col), 1);

		std::cerr << "Joueurs créés" << std::endl;
	}
	else
		std::cerr << "Ca ne marche pas!!!!!!!!!!F**$!" << std::endl;
}

void Controleur::setJoueur(Joueur j, int i)
{
	partie_->setJoueur(j,i);
}
