#include "pieceCliquable.hpp"
#include "Controleur.hpp"
#include "Fenetre.hpp"

/**
 * @brief       
 * @entrées    
 * @sorties    
**/
PieceCliquable::PieceCliquable(QWidget* parent, Fenetre* fenetre) : QLabel(parent)
{
   	fenetre_ = std::shared_ptr<Fenetre>(fenetre);
}

/**
 * @brief       
 * @entrées    
 * @sorties    
**/
PieceCliquable::~PieceCliquable() {}

/**
 * @brief       
 * @entrées    
 * @sorties    
**/
void PieceCliquable::mousePressEvent(QMouseEvent* event)
{
   	//fenetre_->cliqueSurPiece(this);
    emit clicked(this);
}