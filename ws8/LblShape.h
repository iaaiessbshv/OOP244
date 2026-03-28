/* Citation and Sources...
-----------------------------------------------------------
Workshop 8
Module: LblShape
Filename: LblShape.h
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
#ifndef SENECA_LABELEDSHAPE_H
#define SENECA_LABELEDSHAPE_H

#include "Shape.h"
#include <istream>
namespace seneca {

class LblShape : public Shape {
  // Dynamically allocated label for the shape
  char *m_label = nullptr;

protected:
  // Returns the label string for derived classes to access
  const char *label() const;

public:
  // Default constructor
  LblShape();
  // Constructor with label initialization
  LblShape(const char *label);
  // Copy constructor and assignment operator are deleted to prevent copying
  LblShape(const LblShape &) = delete;
  LblShape &operator=(const LblShape &) = delete;
  // Reads label specifications from input stream
  void getSpecs(std::istream &is) override;
  // Destructor to release dynamically allocated memory
  virtual ~LblShape();
};
} // namespace seneca

#endif // !SENECA_LABELEDSHAPE_H
