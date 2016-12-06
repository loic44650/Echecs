#include "Controleur.hpp"
#include "utils.hpp"

Controleur::Controleur(std::shared_ptr<Partie> p) : cliquePrecedent_(Coord(-1,-1))
{
	partie_ = p;
}

void Controleur::jouerContreIA(std::string nom, std::string prenom, std::string coul)
{
	char col;
	if(nom.empty()) nom = "Lenon";
	if(prenom.empty()) prenom = "Bob";

	if(coul.empty()) col = 'N';
	else char col = coul[0];

	int numJoueur = (col == 'B') ? 0 : 1;
	partie_->setJoueur(Joueur(nom,prenom,col), numJoueur);

	col = (col == 'B') ? 'N' : 'B';
	partie_->setJoueur(Joueur("Artificial","Intelligence",col), (numJoueur+1)%2 );
	partie_->init();
	std::cerr << "Joueur créé" << std::endl;
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



bool Controleur::gererClique(const Coord& coord) {
	bool moveDone = false;
	std::cerr << "Controleur::gererClique\n";
	if(cliquePrecedent_.x < 0) {
		std::cerr << "clic prec init\n";
		cliquePrecedent_ = coord;
	}
	else if(cliquePrecedent_.x != coord.x || cliquePrecedent_.y != coord.y){
			std::cerr << "pas meme piece donc lance partie->jouer\n";
			if(partie_->jouer(cliquePrecedent_, coord)) {
				moveDone = true;
				std::cerr << "mouvement correct \n";
			}
			cliquePrecedent_.x = -1;
	}
	else {
		cliquePrecedent_.x = -1;
	}

	return moveDone;
}
