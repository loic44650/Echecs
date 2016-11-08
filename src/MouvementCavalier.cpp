
#include "MouvementCavalier.hpp"


MouvementCavalier::MouvementCavalier(int d) : Mouvement(d) {}

MouvementCavalier::~MouvementCavalier() {}

bool MouvementCavalier::peutAllerEn(Coord &dep, Coord &but, Echiquier *e) {
   bool isOk = false;

   if(dep.x+2 == but.x && dep.y+1 == but.y) isOk = true;
   else if(dep.x+2 == but.x && dep.y-1 == but.y) isOk = true;
   else if(dep.x-2 == but.x && dep.y+1 == but.y) isOk = true;
   else if(dep.x-2 == but.x && dep.y-1 == but.y) isOk = true;
   else if(dep.y+2 == but.y && dep.x+1 == but.x) isOk = true;
   else if(dep.y+2 == but.y && dep.x-1 == but.x) isOk = true;
   else if(dep.y-2 == but.y && dep.x+1 == but.x) isOk = true;
   else if(dep.y-2 == but.y && dep.x-1 == but.x) isOk = true;

   return isOk;
}

bool MouvementCavalier::isMoveOk(Coord &dep, Coord &but, Echiquier *e, bool posInit){
   if(peutAllerEn(dep,but,e)) {
      e->movePiece(dep,but);
      return true;
   }

   return false;
}

bool MouvementCavalier::isAttackOk(Coord &dep, Coord &but, Echiquier *e, bool posInit) {
   if(peutAllerEn(dep,but,e)) {
      e->mangerPiece(dep,but);
   }
}


std::vector<Coord> MouvementCavalier::mouvementPossible(Coord dep, Echiquier *e, char col, bool posInit) {
   std::vector<Coord> tousLesMouvements;
   Coord tmp(dep.x+2,dep.y+1);

   if(!e->estOccupee(tmp)) tousLesMouvements.push_back(tmp);
   tmp.y -= 2;
   if(!e->estOccupee(tmp)) tousLesMouvements.push_back(tmp);
   tmp.x -= 4;
   if(!e->estOccupee(tmp)) tousLesMouvements.push_back(tmp);
   tmp.y += 2;
   if(!e->estOccupee(tmp)) tousLesMouvements.push_back(tmp);
   ++tmp.y; ++tmp.x;
   if(!e->estOccupee(tmp)) tousLesMouvements.push_back(tmp);
   tmp.x += 2;
   if(!e->estOccupee(tmp)) tousLesMouvements.push_back(tmp);
   tmp.y -= 4;
   if(!e->estOccupee(tmp)) tousLesMouvements.push_back(tmp);
   tmp.x -= 2;
   if(!e->estOccupee(tmp)) tousLesMouvements.push_back(tmp);

   return tousLesMouvements;
}
