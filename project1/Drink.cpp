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
V1.0    2025/03/26  Milestone 3: Billable , Food, Drink class
-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my work for function whatever.
-----------------------------------------------------------
*/
#include "Drink.h"
#include "Billable.h"
#include "Utils.h"
#include <iostream>
#include <ostream>
namespace seneca {
bool Drink::ordered() const {
  return m_size == 'S' || m_size == 'M' || m_size == 'L' || m_size == 'X';
}
bool Drink::order() {
  std::cout << "        Drink Size Selection\n"
            << "   1- Small\n"
            << "   2- Medium\n"
            << "   3- Larg\n"
            << "   4- Extra Large\n"
            << "   0- Back\n"
            << "> ";
  int choice = ut.getInt(0, 4);
  switch (choice) {
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
  case 0:
    m_size = '\0';
    break;
  }
  return ordered();
}
double Drink::price() const {
  switch (m_size) {
  case 'S':
    return Billable::price() * 0.5;
    break;
  case 'M':
    return Billable::price() * 0.75;
    break;
  case 'L':
    return Billable::price();
    break;
  case 'X':
    return Billable::price() * 1.5;
    break;
  }
  return Billable::price();
}

std::ostream &Drink::print(std::ostream &ostr) const {
  const char *n = operator const char *();
  int i = 0;
  if (n) {
    for (; i < 25 && n[i]; i++) {
      ostr << n[i];
    }
  }
  for (; i < 28; i++) {
    ostr << '.';
  }
  if (!ordered()) {
    ostr << ".....";
  } else {
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
    }
  }

  double p = price();
  long long cents = (long long)(p * 100.0 + 0.5);
  long long dollars = cents / 100;
  int decimal = (int)(cents % 100);

  char tmp[16];
  int len = 0;

  if (dollars == 0) {
    tmp[len++] = '0';
  } else {
    int d = 0;
    long long temp = dollars;
    while (temp > 0) {
      tmp[d++] = '0' + (temp % 10);
      temp /= 10;
    }
    for (int a = 0, b = d - 1; a < b; a++, b--) {
      char t = tmp[a];
      tmp[a] = tmp[b];
      tmp[b] = t;
    }
    len = d;
  }
  tmp[len++] = '.';
  tmp[len++] = '0' + decimal / 10;
  tmp[len++] = '0' + decimal % 10;
  tmp[len] = '\0';

  for (int s = len; s < 7; s++)
    ostr << ' ';
  ostr << tmp;
  return ostr;
}

std::ifstream &Drink::read(std::ifstream &file) {
  char tempName[128];
  double tempPrice = 0;

  file.getline(tempName, 128, ',');
  file >> tempPrice;
  file.ignore();
  if (file) {
    name(tempName);
    Billable::price(tempPrice);
    m_size = '\0';
  }
  return file;
}
} // namespace seneca
