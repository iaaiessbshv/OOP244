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
V2.0    2026/03/25  Milestone 2: Added Menu constructor, destructor,operator<<,
select(), ostream operator<<
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
  // print row number if non-negative
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

Menu::Menu(const char *title, const char *exitOption, unsigned int indentNum,
           unsigned int indentSize)
    : m_indentNum(indentNum), m_indentSize(indentSize), m_numItems(0),
      m_title(title, indentNum, indentSize, -1),
      m_exitOption(exitOption, indentNum, indentSize, 0),
      m_selectionPrompt("> ", indentNum, indentSize, -1) {
  for (size_t i = 0; i < MaximumNumberOfMenuItems; i++) {
    m_items[i] = nullptr;
  }
}

Menu::~Menu() {
  for (size_t i = 0; i < MaximumNumberOfMenuItems; i++) {
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
  // Display title if valid
  if (m_title) {
    m_title.display(cout);
    cout << '\n';
  }
  // Display each menu item
  for (unsigned int i = 0; i < m_numItems; i++) {
    if (m_items[i]) {
      m_items[i]->display(cout);
      cout << '\n';
    }
  }
  // Display exit option
  m_exitOption.display(cout);
  cout << '\n';
  // Display selection prompt (no newline — user types on same line)
  m_selectionPrompt.display(cout);
  // Get validated integer selection
  size_t sel = (size_t)ut.getInt(0, (int)m_numItems);
  // Newline so the next output starts on a fresh line
  cout << '\n';
  return sel;
}

size_t operator<<(ostream &ostr, const Menu &m) {
  if (&ostr == &cout) {
    return m.select();
  }
  return 0;
}

} // namespace seneca
