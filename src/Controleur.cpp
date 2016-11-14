#include "Controleur.hpp"

Controleur::Controleur(std::shared_ptr<Partie> p) : cliquePrecedent_(nullptr)
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

bool Controleur::gererClique(const std::shared_ptr<PieceCliquable> piece, QPoint coord) {
	if(!cliquePrecedent_) {
		cliquePrecedent_ = piece;
		std::cerr << "selection piece" << std::endl;
	}
	else {
		std::cerr << "selection destination : ";
		QPoint dep = cliquePrecedent_->pos();
		Coord cdep((dep.y()) / 80, dep.x() / 80);
		Coord cbut();
		if(piece) {
			QPoint but = piece->pos();
			cbut = Coord((but.y()) / 80, but.x() / 80);
		}
		else {
			cbut = Coord(((coord.y - 34) / 80), coord.x / 80);
		}
		std::cerr << "de " << cdep.toString() << " en " << cbut.toString() << std::endl;
		if(partie_->getEchiquier()->move(cdep,cbut)) {
			std::cerr << "mouvement possible " << std::endl;
			cliquePrecedent_->setGeometry(cbut.x,cbut.y,64,64);
		}
		cliquePrecedent_ = nullptr;
	}

	return false;
}
