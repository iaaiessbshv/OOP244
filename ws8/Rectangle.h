/* Citation and Sources...
-----------------------------------------------------------
Workshop 8
Module: Rectangle
Filename: Rectangle.h
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
#ifndef SENECA_RECTANGLE_H
#define SENECA_RECTANGLE_H
#include "LblShape.h"

namespace seneca {

class Rectangle : public LblShape {
  // Width of the rectangle
  int m_width = 0;
  // Height of the rectangle
  int m_height = 0;

public:
  // Default constructor
  Rectangle() = default;
  // Constructor that initializes label, width, and height
  Rectangle(const char *label, const int width, const int height);
  // Draws the rectangle using the label, width, and height
  void draw(std::ostream &os) const override;
  // Gets specifications of the rectangle (label, width, height) from input
  void getSpecs(std::istream &is) override;
};

} // namespace seneca

#endif // !SENECA_RECTANGLE_H
