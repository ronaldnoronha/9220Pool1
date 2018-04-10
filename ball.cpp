#include "ball.h"

Ball::Ball()
    :m_coordinate(),
      m_radius(0),
      m_gravity(0),
      m_xVelocity(0),
      m_yVelocity(0)
{}

Ball::Ball(Coordinate coordinate) : m_coordinate(coordinate),
    m_radius(0),
    m_gravity(0),
    m_xVelocity(0),
    m_yVelocity(0)
{}

Ball::Ball(Coordinate coordinate, unsigned int radius)
    : m_coordinate(coordinate),
      m_radius(radius),
        m_gravity(0),
        m_xVelocity(0),
        m_yVelocity(0)
{}

Ball::Ball(Coordinate coordinate, unsigned int radius, double gravity, double xVelocity, double yVelocity)
    :m_coordinate(coordinate),
      m_radius(radius),
      m_gravity(gravity),
      m_xVelocity(xVelocity),
      m_yVelocity(yVelocity)
{}

void Ball::render(QPainter &painter, unsigned int time)
{
    if (isXCollision()){
        m_xVelocity *= -1;
    }
    if (isYCollision()){
        m_yVelocity *= -1;
    }
    painter.setPen ( Qt::black );
    painter.setBrush( QBrush( Qt::white ) );
    painter.drawEllipse(m_coordinate.getQtRenderingXCoordinate() - (int) m_radius,
        m_coordinate.getQtRenderingYCoordinate() -(int) m_radius,
        m_radius * 2,
        m_radius * 2);
    m_yVelocity *= (1+m_gravity/100);
    m_xVelocity *= (1+m_gravity/100);
    m_coordinate.changeInXCoordinate(m_xVelocity);
    m_coordinate.changeInYCoordinate(m_yVelocity);
}

bool Ball::isXCollision(){
    return m_coordinate.getQtRenderingXCoordinate()<=0 ||
            (m_coordinate.getQtRenderingXCoordinate() >
            (signed int) 600 -
            (signed int) m_radius);
}


bool Ball::isYCollision(){
    return m_coordinate.getQtRenderingYCoordinate()<=0 ||
            (m_coordinate.getQtRenderingYCoordinate() >
            (signed int) m_coordinate.getFrameHeight() -
            (signed int) m_radius);
}

unsigned int Ball::getRadius()
{
    return m_radius;
}

Ball::~Ball()
{
}
