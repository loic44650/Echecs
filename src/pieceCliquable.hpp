#pragma once

#include <QWidget>
#include <QLabel>
#include <iostream>
#include <memory>


class Controleur;
class Fenetre;

class PieceCliquable : public QLabel
{

Q_OBJECT

public:
    explicit PieceCliquable(QWidget* parent, Fenetre*, char col);
    ~PieceCliquable();
    char col();

signals:
    void clicked();

protected:
    void mousePressEvent(QMouseEvent* event);

private:
   std::shared_ptr<Fenetre> fenetre_;
   char col_;
};
