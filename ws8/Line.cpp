/* Citation and Sources...
-----------------------------------------------------------
Workshop 8
Module: Line
Filename: Line.cpp
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
#include "Line.h"
#include "Utils.h"
#include <iostream>
using namespace std;
namespace seneca {
Line::Line(const char *label, const unsigned int length)
    : LblShape(label), m_length(length) {
  if (m_length < (unsigned int)ut.strlen(label)) {
    m_length = (unsigned int)ut.strlen(label);
  }
}
void Line::getSpecs(istream &is) {
  LblShape::getSpecs(is);
  is >> m_length;
  is.ignore(1000, '\n');
}
void Line::draw(ostream &os) const {
  if (m_length > 0 && label() != nullptr) {
    os << label() << "\n";
    for (unsigned int i = 0; i < m_length; i++) {
      os << "=";
    }
  }
}
} // namespace seneca
