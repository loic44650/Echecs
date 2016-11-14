#include "pieceCliquable.hpp"

PieceCliquable::PieceCliquable(QWidget* parent)
    : QLabel(parent)
{

}

PieceCliquable::~PieceCliquable()
{
}

void PieceCliquable::mousePressEvent(QMouseEvent* event)
{
    std::cerr << "bob a cliqué" << std::endl;
    emit clicked();
}
