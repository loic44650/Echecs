#pragma once

#include <memory>
#include "Partie.hpp"

class Controleur
{

    public:
    	Controleur(Partie *p);

      	void setJoueur(Joueur, int );
  
    private:
    	std::shared_ptr<Partie> partie_;

};
