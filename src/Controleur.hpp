#pragma once

#include <memory>
#include "Partie.hpp"

class Controleur
{

    public:
    	Controleur(Partie *p);

    	Controler()
  
    private:
    	std::shared_ptr<Partie> partie_;

};
