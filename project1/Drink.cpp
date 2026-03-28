/* Citation and Sources...
-----------------------------------------------------------
Project Milestone 3
Module: Drink
Filename: Drink.cpp
-----------------------------------------------------------
Author: Issa Abishev
Student number: 175980234
Email: iabishev@myseneca.ca
Subject: OOP244NAA
-----------------------------------------------------------
Revision History
------- --------- ------------------------------------------
Version Date      Reason
V1.0    2026/03/25  Milestone 3: Drink class implementation
-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my work for function whatever.
-----------------------------------------------------------
*/
#include "Drink.h"
#include "Menu.h"
#include "Utils.h"
#include <fstream>
#include <iomanip>
#include <iostream>
using namespace std;
namespace seneca {

Drink::Drink() : m_size(0) {}

ostream &Drink::print(ostream &ostr) const {
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

  // Print size (5 chars)
  if (ordered()) {
    switch (m_size) {
    case 'S':
      ostr << "SML..";
      break;
    case 'M':
      ostr << "MID..";
      break;
    case 'L':
      ostr << "LRG..";
      break;
    case 'X':
      ostr << "XLR..";
      break;
    default:
      ostr << ".....";
      break;
    }
  } else {
    ostr << ".....";
  }

  // Print price right-justified in 7 spaces with 2 decimal places
  ostr << setw(7) << fixed << setprecision(2) << right << price();

  return ostr;
}

bool Drink::order() {
  Menu sizeMenu("Drink Size Selection", "Back", 3, 3);
  sizeMenu << "Small" << "Medium" << "Larg" << "Extra Large";
  size_t selection = cout << sizeMenu;
  switch (selection) {
  case 1:
    m_size = 'S';
    break;
  case 2:
    m_size = 'M';
    break;
  case 3:
    m_size = 'L';
    break;
  case 4:
    m_size = 'X';
    break;
  default:
    m_size = 0;
    break;
  }
  return ordered();
}

bool Drink::ordered() const { return m_size != 0; }

ifstream &Drink::read(ifstream &file) {
  char nameBuf[256] = {};
  double p = 0.0;
  if (file.getline(nameBuf, 256, ',')) {
    file >> p;
    if (file) {
      file.ignore(1000, '\n');
      name(nameBuf);
      Billable::price(p);
      m_size = 0;
    }
  }
  return file;
}

double Drink::price() const {
  double base = Billable::price();
  if (!ordered())
    return base;
  switch (m_size) {
  case 'S':
    return base / 2.0;
  case 'M':
    return base * 3.0 / 4.0;
  case 'L':
    return base;
  case 'X':
    return base * 1.5;
  default:
    return base;
  }
}

} // namespace seneca
