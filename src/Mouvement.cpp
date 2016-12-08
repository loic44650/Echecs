#include "Mouvement.hpp"

/**
 * @brief       
 * @entrées    
 * @sorties    
**/
Mouvement::Mouvement(int d) : distance_(d) {}

/**
 * @brief       
 * @entrées    
 * @sorties    
**/
Mouvement::~Mouvement() {}

/**
 * @brief       
 * @entrées    
 * @sorties    
**/
std::vector<Coord> Mouvement::mouvementPossible(Coord dep, Echiquier *e, char col, bool posInit) 
{
	std::cerr << "bob est dans mouvementPossible" << std::endl;
}