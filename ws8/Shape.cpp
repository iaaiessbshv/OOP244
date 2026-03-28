/* Citation and Sources...
-----------------------------------------------------------
Workshop 8
Module: Shape
Filename: Shape.cpp
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
#include "Shape.h"
#include <iostream>
using namespace std;
namespace seneca {
ostream &operator<<(std::ostream &os, const Shape &shape) {
  shape.draw(os);
  return os;
}

istream &operator>>(std::istream &is, Shape &shape) {
  shape.getSpecs(is);
  return is;
}
} // namespace seneca
