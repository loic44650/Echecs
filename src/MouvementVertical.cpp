#include "MouvementVertical.hpp"

/**
 * @brief       
 * @entrées    
 * @sorties    
**/
MouvementVertical::MouvementVertical(int d) : Mouvement(d) {}

/**
 * @brief       
 * @entrées    
 * @sorties    
**/
MouvementVertical::~MouvementVertical() {}

/**
 * @brief       
 * @entrées    
 * @sorties    
**/
bool MouvementVertical::peutAllerEn(Coord &dep, Coord &but, Echiquier *e, std::vector<Coord>& chemin) 
{
	bool isOk = true;
	int x;

	if(dep.y != but.y) return false;

	if(dep.x < but.x) 
	{
		x = dep.x+1;

		if (but.x-dep.x > distance_) isOk = false;
		while (x < but.x && isOk) 
		{
			chemin.push_back(Coord(x,but.y));
			if (e->estOccupee(Coord(x,but.y))) isOk = false;
			++x;
		}
	}
	else 
	{
		x = dep.x-1;

		if (dep.x-but.x > distance_) isOk = false;
		
		while (x > but.x && isOk) 
		{
			chemin.push_back(Coord(x,but.y));
			if (e->estOccupee(Coord(x, but.y))) isOk = false;
			--x;
		}
	}

	return isOk;
}

/**
 * @brief       
 * @entrées    
 * @sorties    
**/
std::vector<Coord> MouvementVertical::mouvementPossible(Coord dep, Echiquier *e, char col, bool posInit) 
{
	std::vector<Coord> tousLesMouvements;

	Coord tmp(dep.x+1,dep.y);
	
	while (tmp.x < 8 && tmp.x-dep.x <= distance_ && (!e->estOccupee(tmp) || e->getCouleur(tmp)!=col)) 
	{
		tousLesMouvements.push_back(tmp);
		++tmp.x;
	}

	tmp.x = dep.x-1;
	
	while (tmp.x >= 0 && dep.x-tmp.x > distance_ && (!e->estOccupee(tmp) || e->getCouleur(tmp)!=col)) 
	{
		tousLesMouvements.push_back(tmp);
		--tmp.x;
	}
	 
	return tousLesMouvements;
}

/**
 * @brief       
 * @entrées    
 * @sorties    
**/
bool MouvementVertical::makeMove(Coord &dep, Coord &but, Echiquier *e, bool posInit, std::vector<Coord>& chemin)
{
	if (peutAllerEn(dep,but,e,chemin)) 
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
bool MouvementVertical::makeAttack(Coord &dep, Coord &but, Echiquier *e, bool posInit, std::vector<Coord>& chemin) 
{
	if (peutAllerEn(dep,but,e,chemin)) 
	{
		e->mangerPiece(dep,but);
		return true;
	}

	return false;
}