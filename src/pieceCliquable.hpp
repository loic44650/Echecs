#pragma once

#include <QWidget>
#include <QLabel>
<<<<<<< HEAD
#include <iostream>
=======
#include <memory>

class Controleur;
>>>>>>> 81e0d8aa11e69a3307d310fcdd13cfe9dc955398

class PieceCliquable : public QLabel
{

Q_OBJECT

public:
    explicit PieceCliquable(QWidget* parent, std::shared_ptr<Controleur> controleur);
    ~PieceCliquable();

signals:
    void clicked();

protected:
    void mousePressEvent(QMouseEvent* event);

private:
   std::shared_ptr<Controleur> controleur_;
};
