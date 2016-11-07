
#include "MouvementVertical.hpp"


MouvementVertical::MouvementVertical(int d) : Mouvement(d) {}

MouvementVertical::~MouvementVertical() {}

bool MouvementVertical::peutAllerEn(Coord &dep, Coord &but, Echiquier *e) {
   bool isOk = true;
   int x;


   if(dep.y != but.y) return false;

   if(dep.x < but.x) {
      x = dep.x+1;

      if(but.x-dep.x > distance_) isOk = false;
      while( x < but.x && isOk) {
         if(e->estOccupee(Coord(x,but.y))) isOk = false;
         ++x;
      }
   }
   else {
      x = dep.x-1;

      if(dep.x-but.x > distance_) isOk = false;
      while( x > but.x && isOk) {
         if(e->estOccupee(Coord(x, but.y))) isOk = false;
         --x;
      }
   }

   return isOk;
}


std::vector<Coord> MouvementVertical::mouvementPossible(Coord dep, Echiquier *e, char col, bool posInit) {
   std::vector<Coord> tousLesMouvements;

   Coord tmp(dep.x+1,dep.y);
   while( tmp.x < 8 && tmp.x-dep.x <= distance_ && (!e->estOccupee(tmp) || e->getCouleur(tmp)!=col) ) {
      tousLesMouvements.push_back(tmp);
      ++tmp.x;
   }

   tmp.x = dep.x-1;
   while( tmp.x >= 0 && dep.x-tmp.x > distance_ && (!e->estOccupee(tmp) || e->getCouleur(tmp)!=col) ) {
      tousLesMouvements.push_back(tmp);
      --tmp.x;
   }

   return tousLesMouvements;
}

bool MouvementVertical::isMoveOk(Coord &dep, Coord &but, Echiquier *e, bool posInit){

   if(peutAllerEn(dep,but,e)) {
      e->movePiece(dep,but);
      return true;
   }

   return false;
}

bool MouvementVertical::isAttackOk(Coord &dep, Coord &but, Echiquier *e, bool posInit) {

   if(peutAllerEn(dep,but,e)) {
      e->mangerPiece(dep,but);
      return true;
   }

   return false;
}
