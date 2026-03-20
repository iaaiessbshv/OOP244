/* Citation and Sources...
-----------------------------------------------------------
Workshop 7
Module: Professor
Filename: Professor.h
-----------------------------------------------------------
Author: Issa Abishev
Student number: 175 980 234
Email: iabishev@myseneca.ca
Subject: OOP244NAA
-----------------------------------------------------------
Revision History
------- --------- ------------------------------------------
Version Date      Reason
V1.0    2025/3/19  Ready for submission
-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my work for function whatever.
-----------------------------------------------------------
*/
#ifndef SENECA_PROFESSOR_H
#define SENECA_PROFESSOR_H
#include "Employee.h"
#include <iostream>
namespace seneca {
class Professor : public Employee {
  char *m_subject{};
  int m_sections{};
  double devPay() const;

public:
  Professor() = default;
  Professor(const char *name, const char *subject, int sections,
            size_t employeeNo, double salary);
  Professor(const Professor &) = delete;
  Professor &operator=(const Professor &) = delete;
  ~Professor();

  std::istream &read(std::istream &istr = std::cin);
  std::ostream &write(std::ostream &ostr = std::cout) const;
  std::ostream &title(std::ostream &ostr = std::cout) const;
};

std::ostream &operator<<(std::ostream &ostr, const Professor &P);
std::istream &operator>>(std::istream &istr, Professor &P);
} // namespace seneca
#endif // !SENECA_PROFESSOR_H
