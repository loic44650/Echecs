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
   std::cerr << "clique sur piece" << std::endl;
   controleur_->cliqueSurPiece(std::shared_ptr<PieceCliquable>(this));
    emit clicked();
}
