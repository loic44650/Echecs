#include "Fou.hpp"

/**
 * @brief      constructeur
 * @entrées    un booléen pour l'état de la pièce et un char pour sa couleur
 * @sorties    aucunes
**/
Fou::Fou( bool etat, char c) : Piece(etat,c)
{
		mvmt_.push_back(new MouvementDiagonale(8));
}

/**
 * @brief      destructeur
 * @entrées    aucunes
 * @sorties    aucunes
**/
Fou::~Fou() {}

/**
 * @brief      fonction affichant une pièce
 * @entrées    aucunes
 * @sorties    retourne un caractère correspondant à la pièce, 'F' respectivement pour un fou
**/
char Fou::afficher()
{
		return 'F';
}

/**
 * @brief      fonction virtuelle effectuant le mouvement d'un fou
 * @entrées    les coordonnées de départ et d'arrivée ainsi qu'un échuiquier
 * @sorties    retourne un booléen indiquant si le déplacement a été effectué
**/
bool Fou::moveTo(Coord dep, Coord but, Echiquier *e)
{
		bool mvmtOk = false;
		unsigned int i = 0;

		while(i < mvmt_.size() && !mvmtOk)
		{
		mvmtOk = mvmt_[i]->makeMove(dep, but, e, posInitiale_, cheminMvmt_);
		++i;
		}

	return mvmtOk;
}

/**
 * @brief      fonction virtuelle effectuant le mouvement d'attaque d'un fou sur une autre piece
 * @entrées    les coordonnées de départ et d'arrivée ainsi qu'un échuiquier
 * @sorties    retourne un booléen indiquant si le mouvement d'attaque a été effectué
**/
bool Fou::attaquer(Coord dep, Coord but, Echiquier *e)
{
		bool mvmtOk = false;
		unsigned int i = 0;

		while(i < mvmt_.size() && !mvmtOk)
		{
		mvmtOk = mvmt_[i]->makeAttack(dep, but, e, posInitiale_, cheminMvmt_);
		++i;
		}

		return mvmtOk;
}

/**
 * @brief      fonction virtuelle indiquant les mouvements réalisablent par un fou
 * @entrées    la coordonnée de départ de la pièce ainsi qu'un échuiquier
 * @sorties    retourne un vector de coordonnées
**/
std::vector<Coord> Fou::mouvementPossible(Coord dep, Echiquier *e)
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