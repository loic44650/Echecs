#pragma once

#include <memory>
#include "Partie.hpp"
#include "Piece.hpp"
#include "pieceCliquable.hpp"
#include <QPoint>


class Controleur
{

  public:

    /**
     * @brief      
     * @entrées   
     * @sorties   
    **/    
   	Controleur(std::shared_ptr<Partie> p);

    /**
     * @brief      
     * @entrées   
     * @sorties   
    **/
    void jouerContreIA(std::string, std::string, std::string);

    /**
     * @brief      
     * @entrées   
     * @sorties   
    **/
    void jouerContrePlayer(std::string, std::string, std::string, std::string, std::string);

    /**
     * @brief      
     * @entrées   
     * @sorties   
    **/
    void setJoueur(Joueur, int );

    /**
     * @brief      
     * @entrées   
     * @sorties   
    **/
    std::shared_ptr<Echiquier> getEchiquier();

    /**
     * @brief      
     * @entrées   
     * @sorties   
    **/
    void setPartie(const std::string& filename);

    /**
     * @brief      
     * @entrées   
     * @sorties   
    **/
    bool gererClique(const Coord& coord);

  private:
  	std::shared_ptr<Partie> partie_;
    Coord cliquePrecedent_;
    char colDepart_;
};
