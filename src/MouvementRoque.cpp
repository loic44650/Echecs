#include "MouvementRoque.hpp"

/**
 * @brief       
 * @entrées    
 * @sorties    
**/
MouvementRoque::MouvementRoque(int d) : Mouvement(d) {}

/**
 * @brief       
 * @entrées    
 * @sorties    
**/
MouvementRoque::~MouvementRoque() {}

/**
 * @brief       
 * @entrées    
 * @sorties    
**/
void MouvementRoque::setPositionsFinales(Coord &coordRoi, Coord &coordTour) 
{
	if (coordRoi.y < coordTour.y) 
	{
		coordRoi.y += 2;

		if ((coordTour.y - coordRoi.y) == 3) coordTour.y -= 2;
		else coordTour.y -= 3;
	}
	else 
	{
		coordRoi.y -= 2;

		if ((coordRoi.y - coordTour.y) == 3) coordTour.y += 3;
		else coordTour.y += 2;
	}
}

/**
 * @brief       
 * @entrées    
 * @sorties    
**/
bool MouvementRoque::isMoveOk(Coord &but, Coord& coordRoi, Coord& coordTour, Echiquier *e, bool posInit) 
{
	auto i = -1;

	if ((e->getType(but) == 'R' || e->getType(but) == 'T') && posInit && e->pieceEnPosInit(but.x,but.y)) 
	{
		if (!e->estEchec(coordRoi)) 
		{
			if (coordRoi.y < coordTour.y) 
			{
				i = coordRoi.y+1;

				while (i <= coordRoi.y+2 && !e->estEchec(Coord(coordRoi.x,i)) && !e->estOccupee(Coord(coordRoi.x,i))) { ++i; }
			
				if( i == coordRoi.y+3 ) 
				{
					++i;
					while((i < coordTour.y && !e->estOccupee(Coord(coordRoi.x,i)))) { ++i; }
				}
			}
			else 
			{
				i = coordRoi.y-1;
					
				while (i >= coordRoi.y-2 && !e->estEchec(Coord(coordRoi.x,i)) && !e->estOccupee(Coord(coordRoi.x,i))) { --i; }
			
				if( i == coordRoi.y-2 ) 
				{
					--i;
					while((i > coordTour.y && !e->estOccupee(Coord(coordRoi.x,i)))) { --i; }
				}
			}
		}
	}

	return i == coordTour.y;
}

/**
 * @brief       
 * @entrées    
 * @sorties    
**/
std::vector<Coord> MouvementRoque::mouvementPossible(Coord dep, Echiquier *e, char col, bool posInit) 
{
	std::vector<Coord> tousLesMouvements;
	Coord coordRoiFinale, coordTourFinale;

	if(posInit) 
	{
		if(e->getType(dep) == 'R') 
		{
			coordRoiFinale = dep;
			Coord tour1(dep.x,0);
			coordTourFinale = tour1;
				 
			if(isMoveOk(tour1, dep, tour1, e, posInit)) 
			{
				setPositionsFinales(coordRoiFinale,coordTourFinale);
				tousLesMouvements.push_back(coordRoiFinale);
			}
			 
			Coord tour2(dep.x,7);
			coordTourFinale = tour2;
				 
			if(isMoveOk(tour2, dep, tour2, e, posInit)) 
			{
				setPositionsFinales(coordRoiFinale,coordTourFinale);
				tousLesMouvements.push_back(coordRoiFinale);
			}
		}
		else 
		{
			coordTourFinale = dep;
			Coord coordRoiFinale = (dep.y == 0) ? Coord(dep.x,dep.y+3) : Coord(dep.x,dep.y-4);
			
			if(isMoveOk(coordRoiFinale,dep, coordRoiFinale, e, posInit)) 
			{
				setPositionsFinales(coordRoiFinale,coordTourFinale);
				tousLesMouvements.push_back(coordTourFinale);
			}
		}
	}

	return tousLesMouvements;
}

/**
 * @brief       
 * @entrées    
 * @sorties    
**/
bool MouvementRoque::makeMove(Coord &dep, Coord &but, Echiquier *e, bool posInit, std::vector<Coord>& chemin)
{
	Coord coordRoi = e->getType(dep) == 'R' ? dep : but;
	Coord coordTour = e->getType(dep) == 'T' ? dep : but;
	Coord coordRoiFinale = coordRoi, coordTourFinale = coordTour;

	if(isMoveOk(but, coordRoi, coordTour, e, posInit)) 
	{
		setPositionsFinales(coordRoiFinale, coordTourFinale);
		e->movePiece(coordRoi,coordRoiFinale);
		e->movePiece(coordTour,coordTourFinale);
	 
		return true;
	}

	return false;
}

/**
 * @brief       
 * @entrées    
 * @sorties    
**/
bool MouvementRoque::makeAttack(Coord &dep, Coord &but, Echiquier *e, bool posInit, std::vector<Coord>& chemin) 
{
	return false;
}