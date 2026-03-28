/* Citation and Sources...
-----------------------------------------------------------
Project Milestone 3
Module: Food
Filename: Food.cpp
-----------------------------------------------------------
Author: Issa Abishev
Student number: 175980234
Email: iabishev@myseneca.ca
Subject: OOP244NAA
-----------------------------------------------------------
Revision History
------- --------- ------------------------------------------
Version Date      Reason
V1.0    2026/03/25  Milestone 3: Food class implementation
-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my work for function whatever.
-----------------------------------------------------------
*/
#include "Food.h"
#include "Menu.h"
#include "Utils.h"
#include <cstring>
#include <fstream>
#include <iomanip>
#include <iostream>
using namespace std;
namespace seneca {

Food::Food() : m_ordered(false), m_child(false), m_customize(nullptr) {}

Food::Food(const Food &other)
    : Billable(other), m_ordered(other.m_ordered), m_child(other.m_child),
      m_customize(nullptr) {
  if (other.m_customize) {
    ut.alocpy(m_customize, other.m_customize);
  }
}

Food &Food::operator=(const Food &other) {
  if (this != &other) {
    Billable::operator=(other);
    m_ordered = other.m_ordered;
    m_child = other.m_child;
    ut.alocpy(m_customize, other.m_customize);
  }
  return *this;
}

Food::~Food() { delete[] m_customize; }

ostream &Food::print(ostream &ostr) const {
  const char *n = (const char *)(*this);
  if (n == nullptr)
    return ostr;

  int i;
  int len = ut.strlen(n);
  int nameLen = len > 25 ? 25 : len;

  // Print name up to 25 chars, left-justified in 28 chars, padded with dots
  for (i = 0; i < nameLen; i++)
    ostr << n[i];
  for (i = nameLen; i < 28; i++)
    ostr << '.';

  // Print portion type (5 chars)
  if (ordered()) {
    if (m_child)
      ostr << "Child";
    else
      ostr << "Adult";
  } else {
    ostr << ".....";
  }

  // Print price right-justified in 7 spaces with 2 decimal places
  ostr << setw(7) << fixed << setprecision(2) << right << price();

  // Print customizations only to cout
  if (m_customize && &ostr == &cout) {
    ostr << " >> ";
    // Print first 30 characters of customization
    int custLen = ut.strlen(m_customize);
    int printLen = custLen > 30 ? 30 : custLen;
    for (i = 0; i < printLen; i++)
      ostr << m_customize[i];
  }

  return ostr;
}

bool Food::order() {
  Menu portionMenu("Food Size Selection", "Back", 3, 3);
  portionMenu << "Adult" << "Child";
  size_t selection = cout << portionMenu;
  if (selection == 1) {
    m_ordered = true;
    m_child = false;
  } else if (selection == 2) {
    m_ordered = true;
    m_child = true;
  } else {
    m_ordered = false;
    delete[] m_customize;
    m_customize = nullptr;
    return false;
  }

  // Prompt for special instructions
  cout << "Special instructions" << endl;
  cout << "> ";
  char buf[256] = {};
  cin.getline(buf, 256);
  if (buf[0] == '\0') {
    delete[] m_customize;
    m_customize = nullptr;
  } else {
    ut.alocpy(m_customize, buf);
  }

  return true;
}

bool Food::ordered() const { return m_ordered; }

ifstream &Food::read(ifstream &file) {
  char nameBuf[256] = {};
  double p = 0.0;
  if (file.getline(nameBuf, 256, ',')) {
    file >> p;
    if (file) {
      file.ignore(1000, '\n');
      name(nameBuf);
      Billable::price(p);
      m_ordered = false;
      m_child = false;
      delete[] m_customize;
      m_customize = nullptr;
    }
  }
  return file;
}

double Food::price() const {
  if (m_ordered && m_child) {
    return Billable::price() / 2.0;
  }
  return Billable::price();
}

} // namespace seneca
