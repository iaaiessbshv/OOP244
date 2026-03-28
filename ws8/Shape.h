/* Citation and Sources...
-----------------------------------------------------------
Workshop 8
Module: Shape
Filename: Shape.h
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
#ifndef SENECA_SHAPE_H
#define SENECA_SHAPE_H
#include <iostream>
namespace seneca {
class Shape {
public:
  // Pure virtual function to draw the shape, implemented in derived classes
  virtual void draw(std::ostream &os) const = 0;
  // Pure virtual function to get specifications of the shape, implemented in
  // derived classes
  virtual void getSpecs(std::istream &is) = 0;
  // Virtual destructor to ensure proper cleanup of derived class objects
  virtual ~Shape() {}
};
// Operator overload to handle output stream, relies on draw function
std::ostream &operator<<(std::ostream &os, const Shape &shape);
// Operator overload to handle input stream, relies on getSpecs function
std::istream &operator>>(std::istream &is, Shape &shape);
} // namespace seneca

#endif // !SENECA_SHAPE_H
