/* Citation and Sources...
-----------------------------------------------------------
Project Milestone 1
Module: Menu
Filename: Menu.h
-----------------------------------------------------------
Author: Issa Abishev
Student number: 175 980 234
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
#ifndef SENECA_MENU_H
#define SENECA_MENU_H
#include <iostream>
namespace seneca {
class MenuItem {
private:
  char *m_content;
  unsigned int m_indentNum;
  unsigned int m_indentSize;
  int m_itemNumber;
  void setEmptyState();

public:
  MenuItem(const char *content, unsigned int indents = 0,
           unsigned int indentSize = 0, int row = -1);
  // Rule of Three
  MenuItem(const MenuItem &) = delete;
  MenuItem &operator=(const MenuItem &) = delete;
  ~MenuItem();

  operator bool() const;
  std::ostream &display(std::ostream &ostr = std::cout) const;
};
} // namespace seneca
#endif
