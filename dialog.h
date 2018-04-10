#ifndef DIALOG_H
#define DIALOG_H

#include "ball.h"
#include <QDialog>
#include <QTimer>
#include <QPainter>
#include <iostream>

namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog(QWidget *parent = 0);
    ~Dialog();

protected:
    void paintEvent(QPaintEvent *);

private:
    Ui::Dialog *ui;
    Ball m_ball;
    int m_counter;

public slots:
    void nextFrame();
};

#endif // DIALOG_H

