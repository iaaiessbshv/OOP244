/* Citation and Sources...
-----------------------------------------------------------
Workshop 5
Module: Mark.h
Filename: Mark.h
-----------------------------------------------------------
Author: Issa Abishev
Student number: 175980234
Email: iabishev@myseneca.ca
Subject: OOP244NAA
-----------------------------------------------------------
Revision History
------- --------- ------------------------------------------
Version Date      Reason
V1.0    2025/3/4  Ready for submission
-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my work for function whatever.
-----------------------------------------------------------
*/
#ifndef SENECA_MARK_H
#define SENECA_MARK_H
#include <fstream>
#include <iostream>
const char GPA = 'G';
const char MARK = 'M';
const char GRADE = 'R';
namespace seneca {
class Mark {
  // Temporary c-string for grade display
  char m_grade[3]{};
  // Exact mark value (double) to maintain precision; rounded when displayed
  double m_value;
  // Display type: 'G' (GPA), 'M' (MARK), or 'R' (GRADE)
  char m_type;
  // Checks if the Mark object is valid
  bool isValid() const;

public:
  Mark(int value = 0, char type = 'M');
  Mark(double value);
  Mark &operator+=(const Mark &other);
  Mark &operator-=(const Mark &other);
  Mark operator+(const Mark &other) const;
  Mark operator-(const Mark &other) const;
  Mark &operator/=(int other);
  Mark operator/(int other) const;
  Mark &operator=(int value);
  Mark &operator=(char type);
  double raw() const;
  operator int() const;
  operator double() const;
  operator const char *() const;
  operator bool() const;

  // display method
  std::ostream &display(std::ostream &os = std::cout) const;

  // friend operator/ overloads
  friend double operator/(double val, const Mark &m);
  friend int operator/(int val, const Mark &m);
};

// Non-member helper function prototypes
std::ostream &display(const Mark &m, char type, std::ostream &os = std::cout);
std::ostream &operator<<(std::ostream &os, const Mark &m);
std::istream &operator>>(std::istream &is, Mark &m);
std::ifstream &operator>>(std::ifstream &ifs, Mark &m);

// operator+ helpers
double operator+(double val, const Mark &m);
int operator+(int val, const Mark &m);

// operator- helpers
double operator-(double val, const Mark &m);
int operator-(int val, const Mark &m);

} // namespace seneca
#endif // !SENECA_MARK_H
