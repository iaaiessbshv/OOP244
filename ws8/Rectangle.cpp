/* Citation and Sources...
-----------------------------------------------------------
Workshop 8
Module: Rectangle
Filename: Rectangle.cpp
-----------------------------------------------------------
Author: Issa Abishev
Student number: 175 980 234
Email: iabishev@myseneca.ca
Subject: OOP244NAA
-----------------------------------------------------------
Revision History
------- --------- ------------------------------------------
Version Date      Reason
V1.0    2025/3/25  Ready for submission
-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my work for function whatever.
-----------------------------------------------------------
*/
#include "Rectangle.h"
#include "LblShape.h"
#include "Utils.h"
#include <istream>
#include <ostream>
namespace seneca {
Rectangle::Rectangle(const char *label, const int width, const int height)
    : LblShape(label), m_width(width), m_height(height) {
  if (m_height < 3)
    m_height = 3;
  if (m_width < ut.strlen(label) + 2)
    m_width = ut.strlen(label) + 2;
}
void Rectangle::getSpecs(std::istream &is) {
  LblShape::getSpecs(is);
  is >> m_width;
  is.ignore(1000, ',');
  is >> m_height;
  is.ignore(1000, '\n');
}
void Rectangle::draw(std::ostream &os) const {
  if (m_width > 0 && m_height > 0 && label() != nullptr) {
    // First line: +----+
    os << '+';
    for (int i = 0; i < m_width - 2; i++)
      os << '-';
    os << '+' << '\n';

    // Second line: |label   |
    os << '|';
    os.fill(' ');
    os.width(m_width - 2);
    os << std::left << label();
    os << '|' << '\n';

    // Middle empty lines
    for (int i = 0; i < m_height - 3; i++) {
      os << '|';
      for (int j = 0; j < m_width - 2; j++)
        os << ' ';
      os << '|' << '\n';
    }

    // Last line: +----+
    os << '+';
    for (int i = 0; i < m_width - 2; i++)
      os << '-';
    os << '+';
  }
}
} // namespace seneca
