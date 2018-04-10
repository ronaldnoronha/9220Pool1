#include "coordinate.h"


Coordinate::Coordinate()
    :m_xCoordinate(0),
      m_yCoordinate(0),
      m_frameHeight(0)
{}

Coordinate::Coordinate(unsigned
                       int xCoordinate,
                       unsigned int yCoordinate,
                       unsigned int frameHeight):
    m_xCoordinate(xCoordinate),
    m_yCoordinate(yCoordinate),
    m_frameHeight(frameHeight)
{
}


void Coordinate::changeInXCoordinate(int change){
    m_xCoordinate += change;
    return;
}

void Coordinate::changeInYCoordinate(int change){
    m_yCoordinate += change;
    return;
}

void Coordinate::setYCoordinateToZero(int offset){
    m_yCoordinate = offset;
}

unsigned int Coordinate::getFrameHeight(){
    return m_frameHeight;
}

int Coordinate::getQtRenderingXCoordinate(){
    return m_xCoordinate;
}

int Coordinate::getQtRenderingYCoordinate()
{
    return m_frameHeight - m_yCoordinate;
}


