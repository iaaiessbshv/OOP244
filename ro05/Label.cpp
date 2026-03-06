/*
 Name: Issa Abishev
 Course: OOP244 NAA
 Date: March 6th , 2026
 _______________________
 Partially completed by professor Fardad Soleimanloo
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

// Copy constructor
Label::Label(const Label &other) {
  m_fill = other.m_fill;
  if (other.m_text) {
    m_text = new char[strlen(other.m_text) + 1];
    strcpy(m_text, other.m_text);
  }
}

// Copy assignment operator
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

// Assignment to text: replaces m_text with new text / resets to safe empty
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

// insertion operator
ostream &operator<<(ostream &ostr, const Label &label) {
  return label.print(ostr);
}

} // namespace seneca
