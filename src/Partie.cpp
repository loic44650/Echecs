#include "Partie.hpp"

/**
 * @brief       
 * @entrées    
 * @sorties    
**/
Partie::Partie() 
{
      e_ = std::shared_ptr<Echiquier>(new Echiquier());
}

/**
 * @brief       
 * @entrées    
 * @sorties    
**/
void Partie::setPartie(const std::string& filename)
{
   e_->setEchiquier(filename);
   estEchec_ = false;
   roiDe_[0] = e_->findPiece('R', joueur_[0].getCouleur());
   roiDe_[1] = e_->findPiece('R', joueur_[1].getCouleur());
}

/**
 * @brief       
 * @entrées    
 * @sorties    
**/
bool Partie::jouer(const Coord& dep, const Coord& arrivee) 
{
  bool moveDone = false;
   
  if(e_->getCouleur(dep) == joueur_[joueurActuel_].getCouleur()) 
  {
    if(e_->move(dep, arrivee)) 
    {
      if (!e_->estEchec(roiDe_[joueurActuel_]))
      {
        joueurActuel_ = (joueurActuel_ + 1) % NB_JOUEURS;
        moveDone = true;
        roiDe_[joueurActuel_] = e_->findPiece('R', joueur_[joueurActuel_].getCouleur());
      }
      else
      {
        e_->annulerCoup(dep, arrivee);
      }
    }
  }

  return moveDone;
}

/**
 * @brief       
 * @entrées    
 * @sorties    
**/
Coord Partie::selectionnerPiece(std::string msg) 
{
  std::string strDep;
  std::cout << msg;
  std::cin >> strDep;
  return Coord(strDep);
}

/**
 * @brief       
 * @entrées    
 * @sorties    
**/
int Partie::menu() 
{
  int choix = 0;

  std::cout << "1. Donner les mouvements possibles d'une pièce \n";
  std::cout << "2. Déplacer une pièce\n";
  std::cin >> choix;

  if(choix != 1 && choix != 2) menu();

  return choix;
}

/**
 * @brief       
 * @entrées    
 * @sorties    
**/
void Partie::afficherMouvementPiece(int numJoueur) 
{
  Coord dep;

  do {
    dep = selectionnerPiece("Selectionne la pièce dont vous souhaitez voir les mouvements possibles : ");
  } while(!e_->estOccupee(dep) || (e_->getCouleur(dep) != joueur_[numJoueur].getCouleur()) );

  std::vector<Coord> tousLesMouvements = e_->mouvementPossible(dep);
  if(!tousLesMouvements.empty())
    for(auto c : tousLesMouvements) std::cout << c.toString() << " ";
  else
    std::cout << "Aucun mouvement possible pour cette pièce.";
  std::cout << std::endl;
}

/**
 * @brief       
 * @entrées    
 * @sorties    
**/
void Partie::setJoueur(Joueur j, int i) 
{
   joueur_[i].setJoueur(j);
}

/**
 * @brief       
 * @entrées    
 * @sorties    
**/
void Partie::init() 
{
  if (joueur_[0].getCouleur() == 'B')
    joueurActuel_ = 0;
  else
    joueurActuel_ = 1;
}

/**
 * @brief       
 * @entrées    
 * @sorties    
**/
std::shared_ptr<Echiquier> Partie::getEchiquier() { return e_; }