#include "MouvementPion.hpp"


MouvementPion::MouvementPion(int d, char dir) : Mouvement(d), direction_(dir) {}

MouvementPion::~MouvementPion() {}


bool MouvementPion::isMoveOk(Coord &dep, Coord &but, Echiquier *e){
   if(direction_ == 'N' && but.x == (dep.x+1) ) return true;
   else if(direction_ == 'S' && but.x == (dep.x-1) ) return true;
   else return false;
}
