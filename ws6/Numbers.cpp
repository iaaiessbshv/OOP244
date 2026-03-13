/* Citation and Sources...
-----------------------------------------------------------
Workshop 6
Module: Numbers
Filename: Numbers.cpp
-----------------------------------------------------------
Author: Issa Abishev
Student number: 175980234
Email: iabishev@myseneca.ca
Subject: OOP244NAA
-----------------------------------------------------------
Revision History
------- --------- ------------------------------------------
Version Date      Reason
V1.0    2025/3/12  Ready for submission
-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my work for function whatever.
-----------------------------------------------------------
*/
#define _CRT_SECURE_NO_WARNINGS
#include "Numbers.h"
#include <fstream>
#include <iostream>
using namespace std;
namespace seneca {

// Destructor
Numbers::~Numbers() {
  save();
  delete[] m_numbers;
  delete[] m_filename;
}

// Copy Constructor
Numbers::Numbers(const Numbers &other) {
  setEmpty();
  m_isOriginal = false;
  m_numbers = new double[other.m_numCount];
  for (int i = 0; i < other.m_numCount; i++)
    m_numbers[i] = other.m_numbers[i];
  m_numCount = other.m_numCount;
}

// Copy Assignment Operator
Numbers &Numbers::operator=(const Numbers &other) {
  if (this != &other) {
    delete[] m_numbers;
    m_numbers = new double[other.m_numCount];
    for (int i = 0; i < other.m_numCount; i++)
      m_numbers[i] = other.m_numbers[i];
    m_numCount = other.m_numCount;
  }
  return *this;
}

// numberCount
int Numbers::numberCount() const {
  int count = 0;
  char ch;
  ifstream f(m_filename);
  while (f.get(ch)) {
    if (ch == '\n')
      count++;
  }
  return count;
}

// load
bool Numbers::load() {
  bool result = false;
  if (m_numCount > 0) {
    m_numbers = new double[m_numCount];
    ifstream f(m_filename);
    int i = 0;
    while (!f.fail()) {
      f >> m_numbers[i];
      if (!f.fail())
        i++;
    }
    if (i != m_numCount) {
      delete[] m_numbers;
      setEmpty();
      result = false;
    } else {
      result = true;
    }
  }
  return result;
}

// save
void Numbers::save() const {
  if (m_isOriginal && !isEmpty()) {
    ofstream f(m_filename);
    for (int i = 0; i < m_numCount; i++)
      f << m_numbers[i] << "\n";
  }
}

// operator+=
Numbers &Numbers::operator+=(double value) {
  if (!isEmpty()) {
    double *temp = new double[m_numCount + 1];
    for (int i = 0; i < m_numCount; i++)
      temp[i] = m_numbers[i];
    m_numCount++;
    temp[m_numCount - 1] = value;
    delete[] m_numbers;
    m_numbers = temp;
    sort();
  }
  return *this;
}

// display
std::ostream &Numbers::display(std::ostream &ostr) const {
  if (isEmpty()) {
    ostr << "Empty list";
  } else {
    ostr.precision(2);
    ostr << fixed;
    ostr << "=========================" << "\n";
    if (m_isOriginal)
      ostr << m_filename;
    else
      ostr << "*** COPY ***";
    ostr << "\n";
    for (int i = 0; i < m_numCount; i++) {
      if (i > 0)
        ostr << ", ";
      ostr << m_numbers[i];
    }
    ostr << "\n";
    ostr << "-------------------------" << "\n";
    ostr << "Total of " << m_numCount << " number(s)" << "\n";
    ostr << "Largest number:  " << max() << "\n";
    ostr << "Smallest number: " << min() << "\n";
    ostr << "Average:         " << average() << "\n";
    ostr << "=========================";
  }
  return ostr;
}

// Helper operators
ostream &operator<<(ostream &os, const Numbers &N) { return N.display(os); }

istream &operator>>(istream &istr, Numbers &N) {
  double val;
  istr >> val;
  if (!istr.fail())
    N += val;
  return istr;
}

} // namespace seneca
