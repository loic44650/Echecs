#pragma once

#include <QWidget>
#include <QLabel>
#include <memory>

class Controleur;

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
