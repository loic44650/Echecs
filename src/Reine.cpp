#include "Reine.hpp"

/**
 * @brief      constructeur
 * @entrées    un booléen pour l'état de la pièce et un char pour sa couleur
 * @sorties    aucunes
**/
Reine::Reine( bool etat, char c) : Piece(etat,c)
{
	mvmt_.push_back(new MouvementDiagonale(8));
	mvmt_.push_back(new MouvementVertical(8));
	mvmt_.push_back(new MouvementHorizontal(8));
}

/**
 * @brief      destructeur
 * @entrées    aucunes
 * @sorties    aucunes
**/
Reine::~Reine() {}

/**
 * @brief      fonction affichant une pièce
 * @entrées    aucunes
 * @sorties    retourne un caractère correspondant à la pièce, 'D' respectivement pour une reine
**/
char Reine::afficher()
{
	return 'D';
}

/**
 * @brief      fonction virtuelle effectuant le mouvement d'une reine
 * @entrées    les coordonnées de départ et d'arrivée ainsi qu'un échuiquier
 * @sorties    retourne un booléen indiquant si le déplacement a été effectué
**/
bool Reine::moveTo(Coord dep, Coord but, Echiquier *e)
{
	bool mvmtOk = false;
	int i = 0;

	while(i < mvmt_.size() && !mvmtOk)
	{
		mvmtOk = mvmt_[i]->makeMove(dep, but, e, posInitiale_);
		++i;
	}

	return mvmtOk;
}

/**
 * @brief      fonction virtuelle effectuant le mouvement d'attaque d'une reine sur une autre pièce
 * @entrées    les coordonnées de départ et d'arrivée ainsi qu'un échuiquier
 * @sorties    retourne un booléen indiquant si le mouvement d'attaque a été effectué
**/
bool Reine::attaquer(Coord dep, Coord but, Echiquier *e)
{
	bool mvmtOk = false;
	int i = 0;

	while(i < mvmt_.size() && !mvmtOk)
	{
		mvmtOk = mvmt_[i]->makeAttack(dep, but, e, posInitiale_);
		++i;
	}

	return mvmtOk;
}

/**
 * @brief      fonction virtuelle indiquant les mouvements réalisablent par une reine
 * @entrées    la coordonnée de départ de la pièce ainsi qu'un échuiquier
 * @sorties    retourne un vector de coordonnées
**/
std::vector<Coord> Reine::mouvementPossible(Coord dep, Echiquier *e)
{
	std::vector<Coord> tousLesMouvements;
	std::vector<Coord> tmp;

	for(auto m : mvmt_)
	{
		tmp = m->mouvementPossible(dep, e, c_, posInitiale_);
		tousLesMouvements.insert(tousLesMouvements.end(), tmp.begin(), tmp.end());
	}

	return tousLesMouvements;
}