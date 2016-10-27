
#include "MouvementRoque.hpp"


MouvementRoque::MouvementRoque(int d) : Mouvement(d) {}

MouvementRoque::~MouvementRoque() {}

void MouvementRoque::setPositionsFinales(Coord &coordRoi, Coord &coordTour) {
   if(coordRoi.y < coordTour.y) {
      coordRoi.y += 2;

      if((coordTour.y - coordRoi.y) == 3) coordTour.y -= 2;
      else coordTour.y -= 3;
   }
   else {
      coordRoi.y -= 2;

      if((coordRoi.y - coordTour.y) == 3) coordTour.y += 3;
      else coordTour.y += 2;
   }
}

bool MouvementRoque::isMoveOk(Coord &dep, Coord &but, Echiquier *e, bool posInit){
   auto i = -1;
   Coord coordRoi = e->getType(dep) == 'R' ? dep : but;
   Coord coordTour = e->getType(dep) == 'T' ? dep : but;
   std::cout << "MouvementRock::1" << coordRoi.y << " | " << coordTour.y << std::endl;
   if( (e->getType(but) == 'R' || e->getType(but) == 'T') && posInit && e->pieceEnPosInit(but.x,but.y) ) {
      std::cout << "pieces bon type, en pos init" << std::endl;
      if(!e->estEchec(coordRoi)) {
         std::cout << "roi pas en echec" << std::endl;
         if(coordRoi.y < coordTour.y) {
            std::cout << "if\n ";
            i = coordRoi.y+1;

            while (i <= coordRoi.y+2 && !e->estEchec(Coord(coordRoi.x,i)) && !e->estOccupee(Coord(coordRoi.x,i))) { ++i; }
            if( i == coordRoi.y+2 ) {
               ++i;
               while((i < coordTour.y && !e->estOccupee(Coord(coordRoi.x,i)))) { ++i; }
            }
         }
         else {
            i = coordRoi.y-1;
            while (i >= coordRoi.y-2 && !e->estEchec(Coord(coordRoi.x,i)) && !e->estOccupee(Coord(coordRoi.x,i))) { --i; }
            if( i == coordRoi.y-2 ) {
               --i;
               while((i > coordTour.y && !e->estOccupee(Coord(coordRoi.x,i)))) { --i; }
            }
         }
      }
   }

   Coord coordRoiFinale = coordRoi, coordTourFinale = coordTour;

   if(i == coordTour.y) {
      std::cout  << "possible MouvementRock2\n";
      setPositionsFinales(coordRoiFinale, coordTourFinale);
      std::cout << "Roi : (" << coordRoiFinale.x << "," << coordRoiFinale.y << ")" << std::endl;
      std::cout << "Tour : (" << coordTourFinale.x << "," << coordTourFinale.y << ")" << std::endl;
      e->movePiece(coordRoi,coordRoiFinale);
      std::cout << "deplacement Roi Ok" << std::endl;
      e->movePiece(coordTour,coordTourFinale);
      std::cout << "deplacement Tour Ok" << std::endl;
      return true;
   }
   std::cout << "y : " << i << "impossible MouvementRock3" << std::endl;
   return false;
}


bool MouvementRoque::isAttackOk(Coord &dep, Coord &but, Echiquier *e, bool posInit) {
   return false;
}
