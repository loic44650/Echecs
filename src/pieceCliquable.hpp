#pragma once

#include <QWidget>
#include <QLabel>
#include <iostream>

class PieceCliquable : public QLabel
{

Q_OBJECT

public:
    explicit PieceCliquable(QWidget* parent=0 );
    ~PieceCliquable();

signals:
    void clicked();

protected:
    void mousePressEvent(QMouseEvent* event);


};
