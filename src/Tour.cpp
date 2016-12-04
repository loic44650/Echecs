#include "Tour.hpp"

/**
 * @brief      constructeur
 * @entrées    un booléen pour l'état de la pièce et un char pour sa couleur
 * @sorties    aucunes
**/
Tour::Tour(bool etat, char c) : Piece(etat,c)
{
   mvmt_.push_back(new MouvementHorizontal(8));
   mvmt_.push_back(new MouvementVertical(8));

   roque_ = std::unique_ptr<Mouvement>(new MouvementRoque(4));
}

/**
 * @brief      destructeur
 * @entrées    aucunes
 * @sorties    aucunes
**/
Tour::~Tour() {}

/**
 * @brief      fonction affichant une pièce
 * @entrées    aucunes
 * @sorties    retourne un caractère correspondant à la pièce, 'T' respectivement pour une tour
**/
char Tour::afficher()
{
   return 'T';
}

/**
  * @brief      fonction virtuelle effectuant le mouvement d'un tour
  * @entrées    les coordonnées de départ et d'arrivée ainsi qu'un échuiquier
  * @sorties    retourne un booléen indiquant si le déplacement a été effectué
 **/
bool Tour::moveTo(Coord dep, Coord but, Echiquier *e)
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
 * @brief      fonction virtuelle effectuant le mouvement d'attaque d'une tour sur une autre piece
 * @entrées    les coordonnées de départ et d'arrivée ainsi qu'un échuiquier
 * @sorties    retourne un booléen indiquant si le mouvement d'attaque a été effectué
**/
bool Tour::attaquer(Coord dep, Coord but, Echiquier *e)
{
   return moveTo(dep,but,e);
}

/**
 * @brief      fonction virtuelle effectuant le mouvement roque
 * @entrées    les coordonnées de départ et d'arrivée ainsi qu'un échuiquier
 * @sorties    retourne un booléen indiquant si le mouvement roque a été effectué
**/
bool Tour::roquer(Coord dep, Coord but, Echiquier *e)
{
   return roque_->makeMove(dep,but,e,posInitiale_);
}

/**
 * @brief      fonction virtuelle indiquant les mouvements réalisablent par une tour
 * @entrées    la coordonnée de départ de la pièce ainsi qu'un échuiquier
 * @sorties    retourne un vector de coordonnées
**/
std::vector<Coord> Tour::mouvementPossible(Coord dep, Echiquier *e)
{
   std::vector<Coord> tousLesMouvements;
   std::vector<Coord> tmp;

   for(auto m : mvmt_)
   {
      tmp = m->mouvementPossible(dep, e, c_, posInitiale_);
      tousLesMouvements.insert(tousLesMouvements.end(), tmp.begin(), tmp.end());
   }

   tmp = roque_->mouvementPossible(dep, e, c_, posInitiale_);
   tousLesMouvements.insert(tousLesMouvements.end(), tmp.begin(), tmp.end());

   return tousLesMouvements;
}
