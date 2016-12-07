#include "pieceCliquable.hpp"
#include "Controleur.hpp"
#include "Fenetre.hpp"

PieceCliquable::PieceCliquable(QWidget* parent, Fenetre* fenetre, char col)
    : QLabel(parent), col_(col)
{
   fenetre_ = std::shared_ptr<Fenetre>(fenetre);
}

PieceCliquable::~PieceCliquable()
{
}

char PieceCliquable::col() { return col_; }

void PieceCliquable::mousePressEvent(QMouseEvent* event)
{
   std::cerr << "clique sur piece" << std::endl;
   fenetre_->cliqueSurPiece(event, this);
    emit clicked();
}
