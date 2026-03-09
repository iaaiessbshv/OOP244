/* Citation and Sources...
-----------------------------------------------------------
Project Milestone 1
Module: Menu
Filename: Menu.cpp
-----------------------------------------------------------
Author: Issa Abishev
Student number: 175980234
Email: iabishev@myseneca.ca
Subject: OOP244NAA
-----------------------------------------------------------
Revision History
------- --------- ------------------------------------------
Version Date      Reason
V1.0    2025/3/9  Ready for submission
-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my work for function whatever.
-----------------------------------------------------------
*/
#include "Menu.h"
#include "Utils.h"
#include "constants.h"
#include <iostream>
using namespace std;
namespace seneca {
MenuItem::MenuItem(const char *content, unsigned int indents,
                   unsigned int indentSize, int row) {
  m_content = nullptr;
  m_indentNum = 0;
  m_indentSize = 0;
  m_itemNumber = -1;

  // validate: indentation values
  if (indents > 4 || indentSize > 4) {
    return;
  }
  // validate: row must not exceed MaximumNumberOfMenuItems
  if (row > (int)MaximumNumberOfMenuItems) {
    return;
  }
  // validate: content must not be null, empty, or all whitespace
  if (content == nullptr || content[0] == '\0' || ut.isspace(content)) {
    return;
  }
  // all valid — store dynamically
  m_content = ut.alocpy(content);
  m_indentNum = indents;
  m_indentSize = indentSize;
  m_itemNumber = row;
}
MenuItem::~MenuItem() { delete[] m_content; }
void MenuItem::setEmptyState() {
  delete[] m_content;
  m_content = nullptr;
  m_indentNum = 0;
  m_indentSize = 0;
  m_itemNumber = -1;
}
MenuItem::operator bool() const { return m_content != nullptr; }
ostream &MenuItem::display(ostream &ostr) const {
  if (!m_content) {
    ostr << "??????????";
    return ostr;
  }
  // print indentation
  unsigned int totalIndent = m_indentNum * m_indentSize;
  for (unsigned int i = 0; i < totalIndent; i++) {
    ostr << ' ';
  }
  // print row numbe
  // non-negative
  if (m_itemNumber >= 0) {
    ostr.width(2);
    ostr << m_itemNumber << "- ";
  }
  // print content, skipping any leading whitespace
  const char *text = m_content;
  while (*text && ut.isspace(*text)) {
    text++;
  }
  ostr << text;
  return ostr;
}
} // namespace seneca
