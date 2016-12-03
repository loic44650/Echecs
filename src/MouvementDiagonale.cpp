#include "MouvementDiagonale.hpp"
#include <cstdlib>

      /**
       * @brief
       *
       * @complexité
      **/
MouvementDiagonale::MouvementDiagonale(int d) : Mouvement(d) {}

      /**
       * @brief
       *
       * @complexité
      **/
MouvementDiagonale::~MouvementDiagonale() {}

      /**
       * @brief
       *
       * @complexité
      **/
bool MouvementDiagonale::peutAllerEn(Coord &dep, Coord &but, Echiquier *e) 
{
   bool isOk = true;
   int dx = abs(dep.x-but.x), dy = abs(dep.y-but.y);
   
   //Si la case d'arrivée et la case de départ ne sont pas sur la meme diagonale
   if(dx != dy || dx > distance_ || dy > distance_) return false;

   int x,y;
   
   if (but.x < dep.x && but.y < dep.y) 
   {
      x = dep.x-1;
      y = dep.y-1;
   
      while (x > but.x) 
      {
         if (e->estOccupee(Coord(x,y))) isOk = false;
         --x;
         --y;
      }
   }
   else if (but.x < dep.x && but.y > dep.y) 
   {
      x = dep.x-1;
      y = dep.y+1;
   
      while (x < but.x) 
      {
         if (e->estOccupee(Coord(x,y))) isOk = false;
         --x;
         ++y;
      }
   }
   else if (but.x > dep.x && but.y < dep.y) 
   {
      x = dep.x+1;
      y = dep.y-1;
   
      while (x > but.x) 
      {
         if (e->estOccupee(Coord(x,y))) isOk = false;
         ++x;
         --y;
      }
   }
   else if (but.x > dep.x && but.y > dep.y) 
   {
      x = dep.x+1;
      y = dep.y+1;
   
      while (x > but.x) 
      {
         if (e->estOccupee(Coord(x,y))) isOk = false;
         ++x;
         ++y;
      }
   }

   return isOk;
}

      /**
       * @brief
       *
       * @complexité
      **/
std::vector<Coord> MouvementDiagonale::mouvementPossible(Coord dep, Echiquier *e, char col, bool posInit) 
{
   std::vector<Coord> tousLesMouvements;
   Coord tmp(dep.x+1,dep.y+1);
   
   while (tmp.x < 8 && tmp.y < 8 && tmp.x-dep.x <= distance_ && (!e->estOccupee(tmp) || e->getCouleur(tmp)!=col)) 
   {
      tousLesMouvements.push_back(tmp);
      std::cout << "(" << tmp.x << "," << tmp.y <<")" << std::endl;
      ++tmp.x;
      ++tmp.y;
   }

   tmp.x = dep.x+1; tmp.y = dep.y-1;
   
   while (tmp.x < 8 && tmp.y >= 0 && tmp.x-dep.x > distance_ && (!e->estOccupee(tmp) || e->getCouleur(tmp)!=col)) 
   {
      tousLesMouvements.push_back(tmp);

      std::cout << "(" << tmp.x << "," << tmp.y <<")" << std::endl;
      ++tmp.x;
      --tmp.y;
   }

   tmp.x = dep.x-1; tmp.y = dep.y+1;
   
   while (tmp.x >= 0 && tmp.y < 8 && dep.x-tmp.x > distance_ && (!e->estOccupee(tmp) || e->getCouleur(tmp)!=col)) 
   {
      tousLesMouvements.push_back(tmp);
      std::cout << "(" << tmp.x << "," << tmp.y <<")" << std::endl;
      --tmp.x;
      ++tmp.y;
   }

   tmp.x = dep.x-1; tmp.y = dep.y-1;
   
   while (tmp.x >= 0 && tmp.y >= 0 && dep.x-tmp.x > distance_ && (!e->estOccupee(tmp) || e->getCouleur(tmp)!=col)) 
   {
      tousLesMouvements.push_back(tmp);
      std::cout << "(" << tmp.x << "," << tmp.y <<")" << std::endl;
      --tmp.x;
      --tmp.y;
   }

   return tousLesMouvements;
}

      /**
       * @brief
       *
       * @complexité
      **/
bool MouvementDiagonale::makeMove(Coord &dep, Coord &but, Echiquier *e, bool posInit)
{
   if (peutAllerEn(dep,but,e)) 
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
bool MouvementDiagonale::makeAttack(Coord &dep, Coord &but, Echiquier *e, bool posInit) 
{
   if (peutAllerEn(dep,but,e)) 
   {
      e->mangerPiece(dep,but);
      return true;
   }

   return false;
}