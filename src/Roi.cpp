#include "Roi.hpp"

/**
 * @brief      constructeur
 * @entrées    un booléen pour l'état de la pièce et un char pour sa couleur
 * @sorties    aucunes
**/
Roi::Roi(bool etat, char c) : Piece(etat,c)
{
	mvmt_.push_back(new MouvementDiagonale(1));
	mvmt_.push_back(new MouvementVertical(1));
	mvmt_.push_back(new MouvementHorizontal(1));

	roque_ = std::unique_ptr<Mouvement>(new MouvementRoque(4));
}

/**
 * @brief      destructeur
 * @entrées    aucunes
 * @sorties    aucunes
**/
Roi::~Roi() {}

/**
 * @brief      fonction affichant une pièce
 * @entrées    aucunes
 * @sorties    retourne un caractère correspondant à la pièce, 'R' respectivement pour un roi
**/
char Roi::afficher()
{
	return 'R';
}

/**
 * @brief      fonction virtuelle effectuant le mouvement d'un roi
 * @entrées    les coordonnées de départ et d'arrivée ainsi qu'un échuiquier
 * @sorties    retourne un booléen indiquant si le déplacement a été effectué
**/
bool Roi::moveTo(Coord dep, Coord but, Echiquier *e)
{
	bool mvmtOk = false;
	unsigned int i = 0;

	while(i < mvmt_.size() && !mvmtOk)
	{
		std::cout << "Im Roi::moveTo\n";
		mvmtOk = mvmt_[i]->makeMove(dep, but, e, posInitiale_, cheminMvmt_);
		++i;
	}

   return mvmtOk;
}

/**
 * @brief      fonction virtuelle effectuant le mouvement d'attaque d'un roi sur une autre piece
 * @entrées    les coordonnées de départ et d'arrivée ainsi qu'un échuiquier
 * @sorties    retourne un booléen indiquant si le mouvement d'attaque a été effectué
**/
bool Roi::attaquer(Coord dep, Coord but, Echiquier *e)
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
 * @brief      fonction virtuelle effectuant le mouvement roque
 * @entrées    les coordonnées de départ et d'arrivée ainsi qu'un échuiquier
 * @sorties    retourne un booléen indiquant si le mouvement roque a été effectué
**/
bool Roi::roquer(Coord dep, Coord but, Echiquier *e)
{
	return roque_->makeMove(dep,but,e,posInitiale_, cheminMvmt_);
}

/**
 * @brief      fonction virtuelle indiquant les mouvements réalisablent par un roi
 * @entrées    la coordonnée de départ de la pièce ainsi qu'un échuiquier
 * @sorties    retourne un vector de coordonnées
**/
std::vector<Coord> Roi::mouvementPossible(Coord dep, Echiquier *e)
{
	std::vector<Coord> tousLesMouvements;
	std::vector<Coord> tmp;

	for(auto m : mvmt_)
	{
		tmp = m->mouvementPossible(dep, e, c_, posInitiale_);
		tousLesMouvements.insert(tousLesMouvements.end(), tmp.begin(), tmp.end());
	}

	tmp = roque_->mouvementPossible(dep, e, c_, posInitiale_);
	tousLesMouvements.insert(tousLesMouvements.end(), tmp.begin(), tmp.end());

	return tousLesMouvements;
}