
#include "MouvementDiagonale.hpp"
#include <cstdlib>

MouvementDiagonale::MouvementDiagonale(int d) : Mouvement(d) {}

MouvementDiagonale::~MouvementDiagonale() {}

bool MouvementDiagonale::peutAllerEn(Coord &dep, Coord &but, Echiquier *e) {
   bool isOk = true;
   int x, y;

   //Si la case d'arrivée et la case de départ ne sont pas sur la meme diagonale
   if(abs(dep.x-but.x) != abs(dep.y-but.y)) return false;

   if(but.x < dep.x && but.y < dep.y) {
      x = dep.x-1;
      y = dep.y-1;
      while( x > but.x && (dep.x-x) <= distance_) {
         if(e->estOccupee(Coord(x,y))) isOk = false;
         --x;
         --y;
      }
   }
   else if(but.x < dep.x && but.y > dep.y) {
      x = dep.x-1;
      y = dep.y+1;
      while( x < but.x && (dep.x-x) <= distance_) {
         if(e->estOccupee(Coord(x,y))) isOk = false;
         --x;
         ++y;
      }
   }
   else if(but.x > dep.x && but.y < dep.y) {
      x = dep.x+1;
      y = dep.y-1;
      while( x > but.x && (x-dep.x) <= distance_) {
         if(e->estOccupee(Coord(x,y))) isOk = false;
         ++x;
         --y;
      }
   }
   else if(but.x > dep.x && but.y > dep.y) {
      x = dep.x+1;
      y = dep.y+1;
      while( x > but.x && (x-dep.x) <= distance_) {
         if(e->estOccupee(Coord(x,y))) isOk = false;
         ++x;
         ++y;
      }
   }

   return isOk;
}

bool MouvementDiagonale::isMoveOk(Coord &dep, Coord &but, Echiquier *e, bool posInit){

   if(peutAllerEn(dep,but,e)) {
      e->movePiece(dep,but);
      return true;
   }

   return false;
}

bool MouvementDiagonale::isAttackOk(Coord &dep, Coord &but, Echiquier *e, bool posInit) {

   if(peutAllerEn(dep,but,e)) {
      e->mangerPiece(dep,but);
      return true;
   }

   return false;
}
