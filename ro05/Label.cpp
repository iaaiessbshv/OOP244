/* Citation and Sources...
-----------------------------------------------------------
Module: Label.h
Filename: Label.cpp
-----------------------------------------------------------
Author: Issa Abishev
Student number: 175980234
Email: iabishev@myseneca.ca
Subject: OOP244NAA
-----------------------------------------------------------
Revision History
------- --------- ------------------------------------------
Version Date      Reason
V1.0    2025/3/6  Ready for submission
-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my work for function whatever.
-----------------------------------------------------------
*/

#include "Label.h"
#include "cstr.h"
#include <iostream>
using namespace std;
namespace seneca {

Label::Label(const char *text, char fill) {
  m_fill = fill;
  if (text) {
    m_text = new char[(strlen(text) > 60 ? 60 : strlen(text)) + 1];
    strcpy(m_text, text, 60);
  }
}

Label::~Label() { delete[] m_text; }

Label::Label(const Label &other) {
  m_fill = other.m_fill;
  if (other.m_text) {
    m_text = new char[strlen(other.m_text) + 1];
    strcpy(m_text, other.m_text);
  }
}

Label &Label::operator=(const Label &other) {
  if (this != &other) {
    delete[] m_text;
    m_text = nullptr;
    m_fill = other.m_fill;
    if (other.m_text) {
      m_text = new char[strlen(other.m_text) + 1];
      strcpy(m_text, other.m_text);
    }
  }
  return *this;
}

Label &Label::operator=(const char *text) {
  delete[] m_text;
  m_text = nullptr;
  if (text) {
    m_text = new char[(strlen(text) > 60 ? 60 : strlen(text)) + 1];
    strcpy(m_text, text, 60);
  }
  return *this;
}

ostream &Label::print(ostream &ostr) const {
  int len = m_text ? strlen(m_text) + 4 : 0;
  if (len) {
    for (int i = 0; i < len; ostr << m_fill, i++)
      ;
    ostr << endl << m_fill << " " << m_text << " " << m_fill << endl;
    for (int i = 0; i < len; ostr << m_fill, i++)
      ;
    ostr << endl;
  }
  return ostr;
}

ostream &operator<<(ostream &ostr, const Label &label) {
  return label.print(ostr);
}

} // namespace seneca
