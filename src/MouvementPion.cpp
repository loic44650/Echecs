#include "MouvementPion.hpp"

/**
 * @brief       
 * @entrées    
 * @sorties    
**/
MouvementPion::MouvementPion(int d, char dir) : Mouvement(d), direction_(dir) {}

/**
 * @brief       
 * @entrées    
 * @sorties    
**/
MouvementPion::~MouvementPion() {}

/**
 * @brief       
 * @entrées    
 * @sorties    
**/
bool MouvementPion::peutAllerEn(Coord &dep, Coord &but, Echiquier *e, bool posInit) 
{
	bool isOk = false;

	if(dep.y != but.y || dep.x == but.x) return false;
	else if(posInit) 
	{
		if(direction_ == 'S' && but.x <= dep.x+2 ) isOk = true;
		else if(direction_ == 'N' && but.x >= dep.x-2) isOk = true;
		else isOk = false;
	}
	else 
	{
		if(direction_ == 'S' && but.x == (dep.x+1) ) isOk = true;
		else if(direction_ == 'N' && but.x == (dep.x-1) ) isOk = true;
		else isOk = false;
	}

	return isOk;
}

/**
 * @brief       
 * @entrées    
 * @sorties    
**/
std::vector<Coord> MouvementPion::mouvementPossible(Coord dep, Echiquier *e, char col, bool posInit) 
{
	std::vector<Coord> tousLesMouvements;
	Coord tmp = (direction_ == 'S') ? Coord(dep.x+2, dep.y) : Coord(dep.x-2, dep.y);

	if(posInit && !e->estOccupee(tmp)) tousLesMouvements.push_back(tmp);

	tmp.x = (direction_ == 'S') ? dep.x+1 : dep.x-1;

	if(!e->estOccupee(tmp)) tousLesMouvements.push_back(tmp);

	return tousLesMouvements;
}

/**
 * @brief       
 * @entrées    
 * @sorties    
**/
bool MouvementPion::makeMove(Coord &dep, Coord &but, Echiquier *e, bool posInit, std::vector<Coord>& chemin)
{
	if(peutAllerEn(dep,but,e,posInit)) 
	{
		e->movePiece(dep,but);
		return true;
	}

	return false;
}

/**
 * @brief       
 * @entrées    
 * @sorties    
**/
bool MouvementPion::makeAttack(Coord &dep, Coord &but, Echiquier *e, bool posInit, std::vector<Coord>& chemin) 
{
	bool peutAttaquer = false;
	bool colonneOk = (but.y - dep.y == 1 || dep.y - but.y == 1) ? true : false;

	//std::cout << "colonne ok ? " << colonneOk << std::endl;

	if(direction_ == 'S' && but.x == (dep.x+1) && colonneOk) peutAttaquer = true;
	else if(direction_ == 'N' && but.x == (dep.x-1) && colonneOk) peutAttaquer = true;

	if(peutAttaquer)
		e->mangerPiece(dep,but);

	return peutAttaquer;
}