
#include "MouvementRock.hpp"


MouvementRock::MouvementRock(int d) : Mouvement(d) {}

MouvementRock::~MouvementRock() {}


bool MouvementRock::isMoveOk(Coord &dep, Coord &but, Echiquier *e, bool posInit){
   bool isOk = true;

   if( !posInit || !(e->pieceEnPosInit(but.x,but.y)) || dep.x != but.x )
      isOk = false;
   else {
      if(dep.y < but.y) {
         for(auto i = dep.y+1; i < but.y; ++i)
            if(e->estOccupee(dep.x,i)) isOk = false;
      }
      else {
         for(auto i = dep.y-1; i > but.y; --i)
            if(e->estOccupee(dep.x,i)) isOk = false;
      }
   }

   return isOk;
}

bool MouvementRock::isAttackOk(Coord &dep, Coord &but, Echiquier *e, bool posInit) {
   return false;
}
