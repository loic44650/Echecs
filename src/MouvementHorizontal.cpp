#include "MouvementHorizontal.hpp"

/**
 * @brief       
 * @entrées    
 * @sorties    
**/
MouvementHorizontal::MouvementHorizontal(int d) : Mouvement(d) {}

/**
 * @brief       
 * @entrées    
 * @sorties    
**/
MouvementHorizontal::~MouvementHorizontal() {}

/**
 * @brief       
 * @entrées    
 * @sorties    
**/
bool MouvementHorizontal::peutAllerEn(Coord &dep, Coord &but, Echiquier *e, std::vector<Coord>& chemin) 
{
	bool isOk = true;
	int y;

	if(dep.x != but.x) return false;

	if(dep.y < but.y) 
	{
		y = dep.y+1;

		if(but.y-dep.y > distance_) isOk = false;
		while( y < but.y && isOk) 
		{
			chemin.push_back(Coord(but.x,y));
			if(e->estOccupee(Coord(but.x,y))) isOk = false;
			++y;
		}
	}
	else 
	{
		y = dep.y-1;

		if(dep.y-but.y > distance_) isOk = false;
		while( y > but.y && isOk) 
		{
			chemin.push_back(Coord(but.x,y));
			if(e->estOccupee(Coord(but.x, y))) isOk = false;
			--y;
		}
	}

	return isOk;
}

/**
 * @brief       
 * @entrées    
 * @sorties    
**/
std::vector<Coord> MouvementHorizontal::mouvementPossible(Coord dep, Echiquier *e, char col, bool posInit) 
{
	std::vector<Coord> tousLesMouvements;
	Coord tmp(dep.x,dep.y+1);
	 
	while (tmp.y < 8 && tmp.y-dep.y <= distance_ && (!e->estOccupee(tmp) || e->getCouleur(tmp)!=col)) 
	{
		tousLesMouvements.push_back(tmp);
		++tmp.y;
	}

	tmp.y = dep.y-1;

	while (tmp.y >= 0 && dep.y-tmp.y > distance_ && (!e->estOccupee(tmp) || e->getCouleur(tmp)!=col)) 
	{
		tousLesMouvements.push_back(tmp);
		--tmp.y;
	}

	return tousLesMouvements;
}

/**
 * @brief       
 * @entrées    
 * @sorties    
**/
bool MouvementHorizontal::makeMove(Coord &dep, Coord &but, Echiquier *e, bool posInit, std::vector<Coord>& chemin)
{
	if(peutAllerEn(dep,but,e,chemin)) 
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
bool MouvementHorizontal::makeAttack(Coord &dep, Coord &but, Echiquier *e, bool posInit, std::vector<Coord>& chemin) 
{
	if(peutAllerEn(dep,but,e,chemin)) 
	{
		e->mangerPiece(dep,but);
		return true;
	}

	return false;
}