#ifndef TABLE_H
#define TABLE_H

#include "coordinate.h"
#include <QPainter>

class Table
{
public:
    Table(unsigned int length,
          unsigned int width,
          std::string color,
          double friction);

    ~Table();

private:
    unsigned int m_length;
    unsigned int m_width;
    std::string m_color;
    double m_friction;
    Coordinate m_cornerTopLeft;
    Coordinate m_cornerTopRight;
    Coordinate m_cornerBottomLeft;
    Coordinate m_cornerBottomRight;
};

#endif // TABLE_H
