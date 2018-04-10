#include "dialog.h"
#include "ui_dialog.h"

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog),
    m_ball(Ball(Coordinate(20, 20, 600), 20, -9.8, 2.7, 7)),
    m_counter(0)
{
    ui->setupUi(this);
    this->resize(1000, 600);
    QTimer *timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(nextFrame()));
    timer->start(1);
}

void Dialog::paintEvent(QPaintEvent *event)
{
    this->setStyleSheet("background-color: #82CAFF;");
    QPainter painter(this);

    bool animation = true;
    if (animation) {
        // code for this exercise goes here
        m_ball.render(painter, m_counter);
        m_counter++;
    }
    else {
        // add after the creation of the painter object
        QPen pen;
        pen.setWidth(3);
        pen.setColor(Qt::black);
        QBrush brush(Qt::yellow);

        painter.setPen (pen);
        painter.setBrush(brush);
        // add before the painter draws the ellipse
        painter.drawEllipse(30, 30, 100, 100);
        brush.setColor("#C36241");
        painter.setBrush(brush);
        pen.setWidth(1);

        QPolygon roof;
        roof.putPoints(0, 3, 250, 260, 290, 220, 330, 260);
        painter.drawPolygon(roof);

        brush.setColor("#835C3B");
        painter.setBrush(brush);

        QPolygon house;
        house.putPoints(0, 4, 260, 260, 260, 299, 320, 299, 320, 260);
        painter.drawPolygon(house);
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
