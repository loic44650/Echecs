#include "Controleur.hpp"
#include "utils.hpp"

Controleur::Controleur(std::shared_ptr<Partie> p) : cliquePrecedent_(Coord(-1,-1))
{
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
		partie_->init();
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



bool Controleur::gererClique(const Coord& coord, const char col) {
	bool moveDone = false;

	if(cliquePrecedent_.x < 0) {
		cliquePrecedent_ = coord;
		colDepart_ = col;
	}
	else {
		if(cliquePrecedent_.x != coord.x || cliquePrecedent_.y != coord.y){
			if(partie_->jouer(cliquePrecedent_, coord, colDepart_))
				moveDone = true;
			cliquePrecedent_.x = -1;
		}
	}
	return moveDone;
}
