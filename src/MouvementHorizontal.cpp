
#include "MouvementHorizontal.hpp"


MouvementHorizontal::MouvementHorizontal(int d) : Mouvement(d) {}

MouvementHorizontal::~MouvementHorizontal() {}

bool MouvementHorizontal::peutAllerEn(Coord &dep, Coord &but, Echiquier *e) {
   bool isOk = true;
   int y;

   if(dep.x != but.x) return false;

   if(dep.y < but.y) {
      y = dep.y+1;

      if(but.y-dep.y > distance_) isOk = false;
      while( y < but.y && isOk) {
         if(e->estOccupee(Coord(but.x,y))) isOk = false;
         ++y;
      }
   }
   else {
      y = dep.y-1;

      if(dep.y-but.y > distance_) isOk = false;
      while( y > but.y && isOk) {
         if(e->estOccupee(Coord(but.x, y))) isOk = false;
         --y;
      }
   }

   return isOk;
}


std::vector<Coord> MouvementHorizontal::mouvementPossible(Coord dep, Echiquier *e, char col, bool posInit) {
   std::vector<Coord> tousLesMouvements;

   Coord tmp(dep.x,dep.y+1);
   while( tmp.y < 8 && tmp.y-dep.y <= distance_ && (!e->estOccupee(tmp) || e->getCouleur(tmp)!=col) ) {
      tousLesMouvements.push_back(tmp);
      ++tmp.y;
   }

   tmp.y = dep.y-1;
   while( tmp.y >= 0 && dep.y-tmp.y > distance_ && (!e->estOccupee(tmp) || e->getCouleur(tmp)!=col) ) {
      tousLesMouvements.push_back(tmp);
      --tmp.y;
   }

   return tousLesMouvements;
}

bool MouvementHorizontal::isMoveOk(Coord &dep, Coord &but, Echiquier *e, bool posInit){

   if(peutAllerEn(dep,but,e)) {
      e->movePiece(dep,but);
      return true;
   }

   return false;
}

bool MouvementHorizontal::isAttackOk(Coord &dep, Coord &but, Echiquier *e, bool posInit) {
   if(peutAllerEn(dep,but,e)) {
      e->mangerPiece(dep,but);
      return true;
   }

   return false;
}
