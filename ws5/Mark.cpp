/* Citation and Sources...
-----------------------------------------------------------
Workshop 5
Module: Mark.h
Filename: Mark.cpp
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
#include "Mark.h"
#include <cmath> // for round function
#include <fstream>
#include <iostream>
using namespace std;
namespace seneca {
bool Mark::isValid() const { return (m_value >= 0 && m_value <= 100); }
Mark::Mark(int value, char type) {
  *this = type;
  m_value = double(value);
}
Mark::Mark(double value) {
  m_type = MARK;
  m_value = value;
}
Mark &Mark::operator+=(const Mark &M) {
  m_value += M.m_value;
  return *this;
}
Mark &Mark::operator-=(const Mark &M) {
  m_value -= M.m_value;
  return *this;
}
Mark Mark::operator+(const Mark &M) const { return Mark(*this) += M; }
Mark Mark::operator-(const Mark &M) const { return Mark(*this) -= M; }
Mark &Mark::operator/=(int other) {
  m_value = m_value / other;
  return *this;
}
Mark Mark::operator/(int other) const { return Mark(m_value / other); }
Mark &Mark::operator=(int value) {
  m_value = value;
  return *this;
}
Mark &Mark::operator=(char type) {
  m_type = MARK;
  if (type == GRADE || type == GPA) {
    m_type = type;
  }
  return *this;
}
double Mark::raw() const { return m_value; }
Mark::operator int() const {
  int value = -1;
  if (isValid()) {
    value = int(std::round(m_value < 0 ? 0 : m_value));
  }
  return value;
}
Mark::operator bool() const { return isValid(); }
// returns the GPA not the m_value!!!
Mark::operator double() const {
  double gpa = 0;
  if (!isValid())
    gpa = -1;
  else
    gpa = m_value * 0.04;
  return gpa;
}
Mark::operator const char *() const {
  char *grade = const_cast<char *>(m_grade);
  int value = int(*this);
  grade[1] = grade[2] = '\0';
  if (value < 0 || value > 100)
    grade[0] = 'X';
  else if (value >= 90)
    grade[0] = 'A', grade[1] = '+';
  else if (value >= 80)
    grade[0] = 'A';
  else if (value >= 75)
    grade[0] = 'B', grade[1] = '+';
  else if (value >= 70)
    grade[0] = 'B';
  else if (value >= 65)
    grade[0] = 'C', grade[1] = '+';
  else if (value >= 60)
    grade[0] = 'C';
  else if (value >= 55)
    grade[0] = 'D', grade[1] = '+';
  else if (value >= 50)
    grade[0] = 'D';
  else
    grade[0] = 'F';
  return m_grade;
}

// display method
ostream &Mark::display(ostream &os) const {
  if (!isValid()) {
    if (m_type == GRADE) {
      os << "**";
    } else {
      os << "***";
    }
  } else if (m_type == GPA) {
    // width 3, 1 decimal place
    os.precision(1);
    os.setf(ios::fixed);
    os.width(3);
    os << double(*this);
  } else if (m_type == MARK) {
    // width 3, right-justified, fill with '_'
    char prevFill = os.fill('_');
    os.setf(ios::right, ios::adjustfield);
    os.width(3);
    os << int(*this);
    os.fill(prevFill);
  } else { // GRADE
    // width 3, left-justified, fill with spaces
    char prevFill = os.fill(' ');
    os.setf(ios::left, ios::adjustfield);
    os.width(3);
    os << (const char *)(*this);
    os.fill(prevFill);
    // restore right justify
    os.setf(ios::right, ios::adjustfield);
  }
  return os;
}

// Non-member display helper
ostream &display(const Mark &m, char type, ostream &os) {
  // Always print as MARK first
  Mark tmp = m;
  tmp = MARK;
  tmp.display(os);
  if (type != MARK) {
    os << ": ";
    Mark tmp2 = m;
    tmp2 = type;
    tmp2.display(os);
  }
  return os;
}

// operator<<
ostream &operator<<(ostream &os, const Mark &m) { return m.display(os); }

// operator>> for istream (foolproof)
istream &operator>>(istream &is, Mark &m) {
  bool valid = false;
  while (!valid) {
    int val;
    is >> val;
    if (is.fail()) {
      // not a valid integer
      is.clear();
      is.ignore(1000, '\n');
      cout << "Invalid integer, try again.\n> ";
    } else {
      // check for trailing characters
      char ch;
      is.get(ch);
      if (ch != '\n') {
        // trailing characters
        is.ignore(1000, '\n');
        cout
            << "Invalid trailing characters. Please enter only an integer.\n> ";
      } else {
        // validate range
        if (val < 0 || val > 100) {
          cout << "Invalid mark. Enter a value between 0 and 100.\n> ";
        } else {
          m = val;
          valid = true;
        }
      }
    }
  }
  return is;
}

// operator>> for ifstream
ifstream &operator>>(ifstream &ifs, Mark &m) {
  int val;
  char type;
  ifs >> val;
  ifs.ignore(1, ',');
  ifs >> type;
  // consume newline
  if (ifs.good()) {
    m = val;
    m = type;
  }
  return ifs;
}

// operator+ helpers
double operator+(double val, const Mark &m) { return val + m.raw(); }
int operator+(int val, const Mark &m) { return val + int(m); }

// operator- helpers
double operator-(double val, const Mark &m) { return val - m.raw(); }
int operator-(int val, const Mark &m) { return val - int(m); }

// friend operator/ helpers (access m_value directly)
double operator/(double val, const Mark &m) { return val / m.m_value; }
int operator/(int val, const Mark &m) {
  return val / int(std::round(m.m_value));
}

} // namespace seneca
