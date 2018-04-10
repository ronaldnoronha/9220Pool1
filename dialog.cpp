#include "dialog.h"
#include "ui_dialog.h"
#include <QColor>

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog),
    m_ball(Ball(Coordinate(50, 50, 300), 10, -0.1, 10, 1)),
    m_counter(0)
{
    ui->setupUi(this);
    this->resize(600, 300);
    QTimer *timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(nextFrame()));
    timer->start(100000);
}

void Dialog::paintEvent(QPaintEvent *event)
{

    //this->setStyleSheet("background-color: yellow");
    QPainter painter(this);
    this->setStyleSheet("background-color: green;");

    bool animation = true;
    if (animation) {
        // code for this exercise goes here
        m_ball.render(painter, m_counter);
        m_counter++;
    }

}

void Dialog::nextFrame()
{
    update();
}


Dialog::~Dialog()
{
    delete ui;
}
