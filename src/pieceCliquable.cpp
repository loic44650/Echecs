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
    emit clicked();
}
