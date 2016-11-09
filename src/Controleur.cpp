#include "Controleur.hpp"

Controleur::Controleur(Partie* p) 
{
	//std::unique_ptr<Partie> partie_(new Partie);
	partie_ = std::shared_ptr<Partie>(p);
}
