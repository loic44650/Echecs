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
   //controleur_->gererClique(this);
   emit clicked();
}
