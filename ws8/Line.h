/* Citation and Sources...
-----------------------------------------------------------
Workshop 8
Module: Line
Filename: Line.h
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
#ifndef SENECA_LINE_H
#define SENECA_LINE_H

#include "LblShape.h"
#include <istream>
namespace seneca {

class Line : public LblShape {
  // Length of the line
  unsigned int m_length{0};

public:
  // Default constructor
  Line() = default;
  // Constructor that initializes label and length
  Line(const char *label, const unsigned int length);
  // Draws the line, using the label and length
  void draw(std::ostream &os) const override;
  // Gets specifications of the line (label and length) from input
  void getSpecs(std::istream &is) override;
};
} // namespace seneca

#endif // !SENECA_LINE_H
