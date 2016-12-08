#include "MouvementCavalier.hpp"

/**
 * @brief       
 * @entrées    
 * @sorties    
**/
MouvementCavalier::MouvementCavalier(int d) : Mouvement(d) {}

/**
 * @brief       
 * @entrées    
 * @sorties    
**/
MouvementCavalier::~MouvementCavalier() {}

/**
 * @brief       
 * @entrées    
 * @sorties    
**/
bool MouvementCavalier::peutAllerEn(Coord &dep, Coord &but, Echiquier *e) 
{
	bool isOk = false;

	if (dep.x+2 == but.x && dep.y+1 == but.y) isOk = true;
	else if (dep.x+2 == but.x && dep.y-1 == but.y) isOk = true;
	else if (dep.x-2 == but.x && dep.y+1 == but.y) isOk = true;
	else if (dep.x-2 == but.x && dep.y-1 == but.y) isOk = true;
	else if (dep.y+2 == but.y && dep.x+1 == but.x) isOk = true;
	else if (dep.y+2 == but.y && dep.x-1 == but.x) isOk = true;
	else if (dep.y-2 == but.y && dep.x+1 == but.x) isOk = true;
	else if (dep.y-2 == but.y && dep.x-1 == but.x) isOk = true;

	return isOk;
}

/**
 * @brief       
 * @entrées    
 * @sorties    
**/
bool MouvementCavalier::makeMove(Coord &dep, Coord &but, Echiquier *e, bool posInit, std::vector<Coord>& chemin)
{
	if(peutAllerEn(dep,but,e)) 
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
bool MouvementCavalier::makeAttack(Coord &dep, Coord &but, Echiquier *e, bool posInit, std::vector<Coord>& chemin) 
{
	if (peutAllerEn(dep,but,e)) 
	{
		e->mangerPiece(dep,but);

		return true;
	}

	return false;
}

/**
 * @brief       
 * @entrées    
 * @sorties    
**/
std::vector<Coord> MouvementCavalier::mouvementPossible(Coord dep, Echiquier *e, char col, bool posInit) 
{
	std::vector<Coord> tousLesMouvements;
	Coord tmp(dep.x+2,dep.y+1);

	if (!e->estOccupee(tmp)) tousLesMouvements.push_back(tmp);
	 
	tmp.y -= 2;
	 
	if (!e->estOccupee(tmp)) tousLesMouvements.push_back(tmp);
	 
	tmp.x -= 4;
	 
	if (!e->estOccupee(tmp)) tousLesMouvements.push_back(tmp);
	 
	tmp.y += 2;
	 
	if (!e->estOccupee(tmp)) tousLesMouvements.push_back(tmp);
	 
	++tmp.y; ++tmp.x;
	 
	if (!e->estOccupee(tmp)) tousLesMouvements.push_back(tmp);
	 
	tmp.x += 2;
	 
	if (!e->estOccupee(tmp)) tousLesMouvements.push_back(tmp);
	 
	tmp.y -= 4;
	 
	if (!e->estOccupee(tmp)) tousLesMouvements.push_back(tmp);
	 
	tmp.x -= 2;
	 
	if (!e->estOccupee(tmp)) tousLesMouvements.push_back(tmp);

	return tousLesMouvements;
}