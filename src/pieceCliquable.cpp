#include "pieceCliquable.hpp"
#include "Controleur.hpp"
#include "Fenetre.hpp"

PieceCliquable::PieceCliquable(QWidget* parent, Fenetre* fenetre)
    : QLabel(parent)
{
   fenetre_ = std::shared_ptr<Fenetre>(fenetre);
}

PieceCliquable::~PieceCliquable()
{
}

void PieceCliquable::mousePressEvent(QMouseEvent* event)
{
   std::cerr << "clique sur piece" << std::endl;
   fenetre_->cliqueSurPiece(std::shared_ptr<PieceCliquable>(this));
    emit clicked();
}
