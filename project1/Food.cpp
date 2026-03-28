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
V1.0    2025/03/26  Milestone 3: Billable , Food, Drink class
-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my work for function whatever.
-----------------------------------------------------------
*/
#include "Food.h"
#include "Utils.h"
#include <iostream>
namespace seneca {

Food::Food(const Food &other) { *this = other; }

Food &Food::operator=(const Food &other) {
  if (this != &other) {
    Billable::operator=(other);
    m_ordered = other.m_ordered;
    m_child = other.m_child;
    ut.alocpy(m_customize, other.m_customize);
  }
  return *this;
}

Food::~Food() {
  delete[] m_customize;
  m_customize = nullptr;
}

bool Food::ordered() const { return m_ordered; }

double Food::price() const {
  if (m_ordered && m_child)
    return Billable::price() * 0.5;
  return Billable::price();
}

std::ostream &Food::print(std::ostream &ostr) const {
  const char *n = *this;

  int i = 0;
  if (n) {
    for (; i < 25 && n[i]; i++)
      ostr << n[i];
  }
  for (; i < 28; i++)
    ostr << '.';

  if (!ordered())
    ostr << ".....";
  else
    ostr << (m_child ? "Child" : "Adult");

  // truncate, don't round
  double p = price();
  long long cents = (long long)(p * 100.0);
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

  if (m_customize && &ostr == &std::cout) {
    ostr << " >> ";
    for (int j = 0; j < 30 && m_customize[j]; j++)
      ostr << m_customize[j];
  }

  return ostr;
}

bool Food::order() {
  std::cout << "         Food Size Selection\n"
            << "          1- Adult\n"
            << "          2- Child\n"
            << "          0- Back\n"
            << "         > ";

  int choice = ut.getInt(0, 2);

  if (choice == 0) {
    m_ordered = false;
    delete[] m_customize;
    m_customize = nullptr;
    return false;
  }

  m_child = (choice == 2);
  m_ordered = true;

  std::cout << "Special instructions\n> ";
  char buf[128] = {};
  std::cin.getline(buf, 128);

  delete[] m_customize;
  m_customize = nullptr;

  if (!ut.isspace(buf) && buf[0] != '\0')
    ut.alocpy(m_customize, buf);

  return true;
}

std::ifstream &Food::read(std::ifstream &file) {
  char tempName[128];
  double tempPrice = 0;

  file.getline(tempName, 128, ',');
  file >> tempPrice;
  file.ignore();

  if (file) {
    name(tempName);
    Billable::price(tempPrice);
    m_child = false;
    m_ordered = false;
    delete[] m_customize;
    m_customize = nullptr;
  }
  return file;
}

} // namespace seneca
