/* Citation and Sources...
-----------------------------------------------------------
Workshop 8
Module: LblShape
Filename: LblShape.cpp
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
#include "LblShape.h"
#include "Utils.h"
namespace seneca {
LblShape::LblShape() : m_label(nullptr) {}

const char *LblShape::label() const { return m_label; }

LblShape::LblShape(const char *label) { ut.alocpy(m_label, label); }

LblShape::~LblShape() { delete[] m_label; }

void LblShape::getSpecs(std::istream &is) {
  char buf[81];
  is.getline(buf, 81, ',');
  ut.alocpy(m_label, buf);
}
} // namespace seneca
