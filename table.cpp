#include "table.h"

Table::Table(unsigned int length,
             unsigned int width,
             std::string color,
             double friction)
            : m_length(length),
              m_width(width),
              m_color(color),
              m_friction(friction)
{
    //m_cornerTopLeft(0,wi)
}

Table::~Table()
{}
