#include "Controleur.hpp"

Controleur::Controleur(std::shared_ptr<Partie> p)
{
	clique1_ = Coord(-1,-1);
	clique2_ = Coord(-1,-1);
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

std::shared_ptr<Echiquier> Controleur::getEchiquier() { return partie_->getEchiquier(); }

void Controleur::setPartie(const std::string& filename)
{
	partie_->setPartie(filename);
}

bool Controleur::gererClique(const Coord &c) {
	if(c.x < 8 && c.x >= 0 && c.y < 8 && c.y >= 0 ) {
		if(clique1_.x == -1) {
			std::cerr << "clique1 innoccupé" << std::endl;
			if(partie_->getEchiquier()->estOccupee(c)) {
				std::cerr << "clique1 attribué" << std::endl;
				clique1_ = c;
			}
		}
		else {
			std::cerr << "clique2 attribué" << std::endl;
				clique2_ = c;
				partie_->getEchiquier()->move(clique1_, clique2_);
				clique1_.x = -1;
				clique2_.x = -1;
				std::cerr << "Move appelé, cliqes reinitialisé" << std::endl;
				return true;
		}

	}
	return false;
}
