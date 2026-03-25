/* Citation and Sources...
-----------------------------------------------------------
Project Milestone 2
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
V1.0    2025/03/09  Milestone 1: MenuItem implementation
V2.0    2026/03/21  Milestone 2: Menu class implementation
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
// MenuItem
MenuItem::MenuItem(const char *content, unsigned int indents,
                   unsigned int indentSize, int row) {
  m_content = nullptr;
  m_indentNum = 0;
  m_indentSize = 0;
  m_itemNumber = -1;
  if (indents > 4 || indentSize > 4)
    return;
  if (row > (int)MaximumNumberOfMenuItems)
    return;
  if (content == nullptr || content[0] == '\0' || ut.isspace(content))
    return;
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
  unsigned int i;
  unsigned int totalIndent = m_indentNum * m_indentSize;
  for (i = 0; i < totalIndent; i++)
    ostr << ' ';
  if (m_itemNumber >= 0) {
    ostr.width(2);
    ostr << m_itemNumber << "- ";
  }
  const char *text = m_content;
  while (*text && ut.isspace(*text))
    text++;
  ostr << text;
  return ostr;
}

// Menu
Menu::Menu(const char *title, const char *exitOption, unsigned int indentNum,
           unsigned int indentSize)
    : m_indentNum(indentNum), m_indentSize(indentSize), m_numItems(0),
      m_title(title, indentNum, indentSize, -1),
      m_exitOption(exitOption, indentNum, indentSize, 0),
      m_selectionPrompt(
          "> ", indentNum, indentSize,
          -1) // used and initialization list to simplify assignement
{
  unsigned int i;
  for (i = 0; i < MaximumNumberOfMenuItems; i++)
    m_items[i] = nullptr;
}
Menu::~Menu() {
  unsigned int i;
  for (i = 0; i < MaximumNumberOfMenuItems; i++) {
    delete m_items[i];
    m_items[i] = nullptr;
  }
}
Menu &Menu::operator<<(const char *menuItem) {
  if (m_numItems < MaximumNumberOfMenuItems) {
    m_items[m_numItems] = new MenuItem(menuItem, m_indentNum, m_indentSize,
                                       (int)(m_numItems + 1));
    m_numItems++;
  }
  return *this;
}
size_t Menu::select() const {
  unsigned int i;
  if (m_title) {
    m_title.display(cout);
    cout << '\n';
  }
  for (i = 0; i < m_numItems; i++) {
    m_items[i]->display(cout);
    cout << '\n';
  }
  m_exitOption.display(cout);
  cout << '\n';
  m_selectionPrompt.display(cout);
  return (size_t)ut.getInt(0, (int)m_numItems);
}
size_t operator<<(ostream &ostr, const Menu &m) {
  if (&ostr == &cout)
    return m.select();
  return 0;
}
} // namespace seneca
