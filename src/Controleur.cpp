#include "Controleur.hpp"
#include "utils.hpp"

/**
 * @brief       
 * @entrées    
 * @sorties    
**/
Controleur::Controleur(std::shared_ptr<Partie> p) : cliquePrecedent_(Coord(-1,-1))
{
	partie_ = p;
}

/**
 * @brief       
 * @entrées    
 * @sorties    
**/
void Controleur::jouerContreIA(std::string nom, std::string prenom, std::string coul)
{
	char col;
	if(nom.empty()) nom = "Lenon";
	if(prenom.empty()) prenom = "Bob";

	if(coul.empty()) col = 'N';
	else col = coul[0];

	int numJoueur = (col == 'B') ? 0 : 1;
	partie_->setJoueur(Joueur(nom,prenom,col), numJoueur);

	col = (col == 'B') ? 'N' : 'B';
	partie_->setJoueur(Joueur("Artificial","Intelligence",col), (numJoueur+1)%2 );
	partie_->init();
}

/**
 * @brief       
 * @entrées    
 * @sorties    
**/
void Controleur::jouerContrePlayer(std::string nom, std::string prenom, std::string coul, std::string nom2, std::string prenom2)
{
	if(nom.empty()) nom = "Lenon";
	if(prenom.empty()) prenom = "Bob";
	if(nom2.empty()) nom = "Lenon";
	if(prenom2.empty()) prenom = "John";

	char col;
	if(coul.empty()) col = 'N';
	else col = coul[0];


	int numJoueur = (col == 'B') ? 0 : 1;
	partie_->setJoueur(Joueur(nom,prenom,col), numJoueur);

	col = (coul == "Blanc") ? 'N' : 'B';
	partie_->setJoueur(Joueur(nom2, prenom2, col), (numJoueur+1)%2 );

	partie_->init();
	
}

/**
 * @brief       
 * @entrées    
 * @sorties    
**/
void Controleur::setJoueur(Joueur j, int i)
{
	partie_->setJoueur(j,i);
}

/**
 * @brief       
 * @entrées    
 * @sorties    
**/
std::shared_ptr<Echiquier> Controleur::getEchiquier() { return partie_->getEchiquier(); }

/**
 * @brief       
 * @entrées    
 * @sorties    
**/
void Controleur::setPartie(const std::string& filename)
{
	partie_->setPartie(filename);
}

/**
 * @brief       
 * @entrées    
 * @sorties    
**/
bool Controleur::gererClique(const Coord& coord) {
	bool moveDone = false;
	
	if(cliquePrecedent_.x < 0) 
	{
		cliquePrecedent_ = coord;
	}
	else if(cliquePrecedent_.x != coord.x || cliquePrecedent_.y != coord.y)
	{
		if(partie_->jouer(cliquePrecedent_, coord)) 
		{
			moveDone = true;
		}
			
		cliquePrecedent_.x = -1;
	}
	else 
	{
		cliquePrecedent_.x = -1;
	}

	return moveDone;
}