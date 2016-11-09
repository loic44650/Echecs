#pragma once

#include <memory>
#include "Partie.hpp"

class Controleur
{

    public:
    	Controleur(std::unique_ptr<Partie> p);

      	void setJoueur(Joueur, int );
  
    private:
    	std::unique_ptr<Partie> partie_;

};
