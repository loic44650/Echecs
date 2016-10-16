#include "MouvementPion.hpp"


MouvementPion::MouvementPion(int d, char dir) : Mouvement(d), direction_(dir) {}

MouvementPion::~MouvementPion() {}


bool MouvementPion::isMoveOk(Coord &dep, Coord &but, Echiquier *e){
   if(e->estOccupee(but.x, but.y) || dep.y != but.y) return false;
   if(direction_ == 'S' && but.x == (dep.x+1) ) return true;
   else if(direction_ == 'N' && but.x == (dep.x-1) ) return true;
   else return false;
}

bool MouvementPion::isAttackOk(Coord &dep, Coord &but, Echiquier *e) {
   if(direction_ == 'S' && but.x == (dep.x+1) && abs(but.y-dep.y) == 1) return true;
   else if(direction_ == 'N' && but.x == (dep.x-1) && abs(but.y-dep.y) == 1) return true;
   else return false;
}
