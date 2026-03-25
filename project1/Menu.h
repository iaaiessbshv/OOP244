/* Citation and Sources...
-----------------------------------------------------------
Project Milestone 2
Module: Menu
Filename: Menu.h
-----------------------------------------------------------
Author: Issa Abishev
Student number: 175980234
Email: iabishev@myseneca.ca
Subject: OOP244NAA
-----------------------------------------------------------
Revision History
------- --------- ------------------------------------------
Version Date      Reason
V1.0    2025/03/09  Milestone 1: MenuItem class
V2.0    2026/03/21  Milestone 2: Added full Menu class
-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my work for function whatever.
-----------------------------------------------------------
*/
#ifndef SENECA_MENU_H
#define SENECA_MENU_H
#include "constants.h"
#include <iostream>
namespace seneca {

class Menu;

class MenuItem {
  char *m_content;
  unsigned int m_indentNum;
  unsigned int m_indentSize;
  int m_itemNumber;
  void setEmptyState();
  MenuItem(const char *content, unsigned int indents = 0,
           unsigned int indentSize = 0, int row = -1);
  // Rule of Three
  MenuItem(const MenuItem &) = delete;
  MenuItem &operator=(const MenuItem &) = delete;
  ~MenuItem();
  operator bool() const;
  std::ostream &display(std::ostream &ostr = std::cout) const;

  // Only Menu is a friend
  friend class Menu;
};

class Menu {
  unsigned int m_indentNum;
  unsigned int m_indentSize;
  unsigned int m_numItems;
  MenuItem m_title;
  MenuItem m_exitOption;
  MenuItem m_selectionPrompt;
  MenuItem *m_items[MaximumNumberOfMenuItems];

  // Rule of Three – copying/assignment explicitly prevented
  // Menu(const Menu&) = delete;
  // Menu& operator=(const Menu&) = delete;

public:
  Menu(const char *title, const char *exitOption = "Exit",
       unsigned int indentNum = 0, unsigned int indentSize = 3);

  // Rule of three
  ~Menu();
  Menu(const Menu &) = delete;
  Menu &operator=(const Menu &) = delete;

  Menu &operator<<(const char *menuItem);
  size_t select() const;
};

size_t operator<<(std::ostream &ostr, const Menu &m);
} // namespace seneca
#endif
