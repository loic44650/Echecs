#include "pieceCliquable.hpp"
#include "Controleur.hpp"

PieceCliquable::PieceCliquable(QWidget* parent, std::shared_ptr<Controleur> controleur)
    : QLabel(parent), controleur_(controleur)
{

}

PieceCliquable::~PieceCliquable()
{
}

void PieceCliquable::mousePressEvent(QMouseEvent* event)
{
<<<<<<< HEAD
   //controleur_->gererClique(this);
   emit clicked();
=======
   std::cerr << "clique sur piece" << std::endl;
   controleur_->gererClique(std::shared_ptr<PieceCliquable>(this), this->pos());
    std::cerr << "bob a cliqué" << std::endl;
    emit clicked();
>>>>>>> 58704a6ac962a5dd0a09d63b5a785b3d0892f755
}
