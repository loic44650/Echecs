#include "Cavalier.hpp"

/**
 * @brief      constructeur
 * @entrées    un booléen pour l'état de la pièce et un char pour sa couleur
 * @sorties    aucunes
**/
Cavalier::Cavalier(bool etat, char c) : Piece(etat,c)
{
   mvmt_.push_back(new MouvementCavalier(8));
}

/**
 * @brief      destructeur
 * @entrées    aucunes
 * @sorties    aucunes
**/
Cavalier::~Cavalier() {}

/**
 * @brief      fonction affichant une pièce
 * @entrées    aucunes
 * @sorties    retourne un caractère correspondant à la pièce, 'C' respectivement pour un cavalier
**/
char Cavalier::afficher()
{
   return 'C';
}

/**
 * @brief      fonction virtuelle effectuant le mouvement d'un cavalier
 * @entrées    les coordonnées de départ et d'arrivée ainsi qu'un échuiquier
 * @sorties    retourne un booléen indiquant si le déplacement a été effectué
**/
bool Cavalier::moveTo(Coord dep, Coord but, Echiquier *e)
{
   bool mvmtOk = false;
   int i = 0;

   while(i < mvmt_.size() && !mvmtOk)
   {
      mvmtOk = mvmt_[i]->makeMove(dep, but, e, posInitiale_);
      ++i;
   }

   return mvmtOk;
}

/**
 * @brief      fonction virtuelle effectuant le mouvement d'attaque d'un cavaier sur une autre piece
 * @entrées    les coordonnées de départ et d'arrivée ainsi qu'un échuiquier
 * @sorties    retourne un booléen indiquant si le mouvement d'attaque a été effectué
**/
bool Cavalier::attaquer(Coord dep, Coord but, Echiquier *e)
{
   bool mvmtOk = false;
   int i = 0;

   while(i < mvmt_.size() && !mvmtOk)
   {
      mvmtOk = mvmt_[i]->makeAttack(dep, but, e, posInitiale_);
      ++i;
   }

   return mvmtOk;
}

/**
 * @brief      fonction virtuelle indiquant les mouvements réalisablent par un cavalier
 * @entrées    la coordonnée de départ de la pièce ainsi qu'un échuiquier
 * @sorties    retourne un vector de coordonnées
**/
std::vector<Coord> Cavalier::mouvementPossible(Coord dep, Echiquier *e)
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
