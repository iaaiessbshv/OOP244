/* Citation and Sources...
-----------------------------------------------------------
Workshop 7
Module: Professor
Filename: Professor.cpp
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
#include "Professor.h"
#include "Utils.h"
#include <iostream>
using namespace std;
namespace seneca {

double Professor::devPay() const { return (salary() * 0.01) * m_sections; }

Professor::Professor(const char *name, const char *subject, int sections,
                     size_t employeeNo, double salary)
    : Employee(name, employeeNo, salary), m_subject(ut.alocpy(subject)),
      m_sections(sections) {}

Professor::~Professor() { delete[] m_subject; }

std::istream &Professor::read(std::istream &istr) {
  char buffer[1024];
  Employee::read(istr);
  istr.ignore(); // skip comma after salary
  istr.getline(buffer, 1024, ',');
  ut.alocpy(m_subject, buffer);
  istr >> m_sections;
  return istr;
}

std::ostream &Professor::write(std::ostream &ostr) const {
  char sub2print[21]{};
  if (m_subject)
    ut.strcpy(sub2print, m_subject, 20);
  Employee::write(ostr);
  ostr << " ";
  ostr.setf(ios::left);
  ostr.width(20);
  ostr << sub2print;
  ostr.unsetf(ios::left);
  ostr << " | ";
  ostr.setf(ios::right);
  ostr.width(5);
  ostr << m_sections;
  ostr << " | ";
  ostr.setf(ios::fixed);
  ostr.precision(2);
  ostr.width(8);
  ostr << devPay();
  ostr.unsetf(ios::right);
  ostr << " |";
  return ostr;
}

std::ostream &Professor::title(std::ostream &ostr) const {
  Employee::title(ostr);
  return ostr << " Teaching Subject     | Sec # | $Dev Pay |";
}

ostream &operator<<(ostream &ostr, const Professor &P) { return P.write(ostr); }
istream &operator>>(istream &istr, Professor &P) { return P.read(istr); }
} // namespace seneca
