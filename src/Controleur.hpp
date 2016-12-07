#pragma once

#include <memory>
#include "Partie.hpp"
#include "Piece.hpp"
#include "pieceCliquable.hpp"
#include <QPoint>


class Controleur
{

    public:
    	Controleur(std::shared_ptr<Partie> p);

      	void jouerContreIA(std::string, std::string, std::string);

      	void jouerContrePlayer(std::string, std::string, std::string, std::string, std::string);

      	void setJoueur(Joueur, int );

      	std::shared_ptr<Echiquier> getEchiquier();

      	void setPartie(const std::string& filename);

         bool gererClique(const Coord& coord);

    private:
    	std::shared_ptr<Partie> partie_;
      Coord cliquePrecedent_;
      char colDepart_;
};
