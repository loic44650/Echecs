#include "MouvementPion.hpp"

      /**
       * @brief
       *
       * @complexité
      **/
MouvementPion::MouvementPion(int d, char dir) : Mouvement(d), direction_(dir) {}

      /**
       * @brief
       *
       * @complexité
      **/
MouvementPion::~MouvementPion() {}

      /**
       * @brief
       *
       * @complexité
      **/
bool MouvementPion::peutAllerEn(Coord &dep, Coord &but, Echiquier *e, bool posInit) 
{
   bool isOk = false;

   if(dep.y != but.y || dep.x == but.x) return false;
   else if(posInit) 
   {
      if(direction_ == 'S' && but.x <= dep.x+2 ) isOk = true;
      else if(direction_ == 'N' && dep.x <= but.x+2) isOk = true;
      else isOk = false;
   }
   else 
   {
      if(direction_ == 'S' && but.x == (dep.x+1) ) isOk = true;
      else if(direction_ == 'N' && but.x == (dep.x-1) ) isOk = true;
      else isOk = false;
   }

   return isOk;
}

      /**
       * @brief
       *
       * @complexité
      **/
std::vector<Coord> MouvementPion::mouvementPossible(Coord dep, Echiquier *e, char col, bool posInit) 
{
   std::vector<Coord> tousLesMouvements;
   Coord tmp = (direction_ == 'S') ? Coord(dep.x+2, dep.y) : Coord(dep.x-2, dep.y);

   if(posInit && !e->estOccupee(tmp)) tousLesMouvements.push_back(tmp);

   tmp.x = (direction_ == 'S') ? dep.x+1 : dep.x-1;

   if(!e->estOccupee(tmp)) tousLesMouvements.push_back(tmp);

   return tousLesMouvements;
}

      /**
       * @brief
       *
       * @complexité
      **/
bool MouvementPion::makeMove(Coord &dep, Coord &but, Echiquier *e, bool posInit)
{
   if(peutAllerEn(dep,but,e,posInit)) 
   {
      e->movePiece(dep,but);
      return true;
   }

   return false;
}

      /**
       * @brief
       *
       * @complexité
      **/
bool MouvementPion::makeAttack(Coord &dep, Coord &but, Echiquier *e, bool posInit) 
{
   bool peutAttaquer = false;
   bool colonneOk = (but.y - dep.y == 1 || dep.y-but.y) ? true : false;

   if(direction_ == 'S' && but.x == (dep.x+1) && colonneOk) peutAttaquer = true;
   else if(direction_ == 'N' && but.x == (dep.x-1) && colonneOk) peutAttaquer = true;

   if(peutAttaquer)
      e->mangerPiece(dep,but);

   return peutAttaquer;
}