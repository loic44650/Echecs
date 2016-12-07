#include "Mouvement.hpp"

Mouvement::Mouvement(int d) : distance_(d) {}

Mouvement::~Mouvement() {}

std::vector<Coord> Mouvement::mouvementPossible(Coord dep, Echiquier *e, char col, bool posInit) 
{
	std::cerr << "bob est dans mouvementPossible" << std::endl;
}