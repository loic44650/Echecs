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
    std::cerr << "bob a cliqué" << std::endl;
    emit clicked();
=======
   //controleur_->gererClique(this);
   emit clicked();
>>>>>>> 81e0d8aa11e69a3307d310fcdd13cfe9dc955398
}
