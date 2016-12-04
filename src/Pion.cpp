#include "Pion.hpp"

/**
 * @brief      constructeur
 * @entrées    un booléen pour l'état de la pièce, un char pour sa couleur et un char pour sa direction soit 'N' soit 'S' (pour nord et sud)
 * @sorties    aucunes
**/
Pion::Pion(bool etat, char c, char dir) : Piece(etat,c)
{
   mvmt_.push_back(new MouvementPion(1,dir));
}

/**
 * @brief      destructeur
 * @entrées    aucunes
 * @sorties    aucunes
**/
Pion::~Pion() {}

/**
 * @brief      fonction affichant une pièce
 * @entrées    aucunes
 * @sorties    retourne un caractère correspondant à la pièce, 'P' respectivement pour un pion
**/
char Pion::afficher()
{
   return 'P';
}

/**
 * @brief      fonction virtuelle effectuant le mouvement d'un pion
 * @entrées    les coordonnées de départ et d'arrivée ainsi qu'un échuiquier
 * @sorties    retourne un booléen indiquant si le déplacement a été effectué
**/
bool Pion::moveTo(Coord dep, Coord but, Echiquier *e)
{
   bool mvmtOk = false;
   int i = 0;

   while(i < mvmt_.size() && !mvmtOk)
   {
      mvmtOk = mvmt_[i]->makeMove(dep, but, e, posInitiale_);
      ++i;
   }

   if(mvmtOk) posInitiale_ = false;

   return mvmtOk;
}

/**
 * @brief      fonction virtuelle effectuant le mouvement d'attaque d'un pion sur une autre pièce
 * @entrées    les coordonnées de départ et d'arrivée ainsi qu'un échuiquier
 * @sorties    retourne un booléen indiquant si le mouvement d'attaque a été effectué
**/
bool Pion::attaquer(Coord dep, Coord but, Echiquier *e)
{
   bool mvmtOk = false;
   int i = 0;

   while(i < mvmt_.size() && !mvmtOk)
   {
      mvmtOk = mvmt_[i]->makeAttack(dep, but, e,posInitiale_);
      ++i;
   }

   if(mvmtOk) posInitiale_ = false;

   return mvmtOk;
}

/**
 * @brief      fonction virtuelle indiquant les mouvements réalisablent par un pion
 * @entrées    la coordonnée de départ de la pièce ainsi qu'un échuiquier
 * @sorties    retourne un vector de coordonnées
**/
std::vector<Coord> Pion::mouvementPossible(Coord dep, Echiquier *e)
{
   std::vector<Coord> tousLesMouvements;
   std::vector<Coord> tmp;

   for(auto m : mvmt_)
   {
      tmp = m->mouvementPossible(dep, e, c_, posInitiale_);
      tousLesMouvements.insert(tousLesMouvements.end(), tmp.begin(), tmp.end());
   }

   return tousLesMouvements;
}
