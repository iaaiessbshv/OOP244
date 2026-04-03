/* Citation and Sources...
-----------------------------------------------------------
Project Milestone 3
Module: Billable
Filename: Billable.h
-----------------------------------------------------------
Author: Issa Abishev
Student number: 175980234
Email: iabishev@myseneca.ca
Subject: OOP244NAA
-----------------------------------------------------------
Revision History
------- --------- ------------------------------------------
Version Date      Reason
V1.0    2026/03/26  Milestone 3: Billable , Food, Drink class
-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my work for function whatever.
-----------------------------------------------------------
*/
#include "Billable.h"
#include "Utils.h"
namespace seneca {
void Billable::price(double value) { m_price = value; }
void Billable::name(const char *name) { ut.alocpy(m_name, name); }
// constructors and deep copu
Billable::Billable() : m_name(nullptr), m_price(0.0) {}
Billable::Billable(const Billable &other) : m_name(nullptr), m_price(0.0) {
  *this = other;
}
Billable &Billable::operator=(const Billable &other) {
  if (this != &other) {
    name(other.m_name);
    m_price = other.m_price;
  }
  return *this;
}
Billable::~Billable() {
  delete[] m_name;
  m_name = nullptr;
}
double Billable::price() const { return m_price; }
Billable::operator const char *() const { return m_name; }

double operator+(double money, const Billable &B) { return money + B.price(); }
double &operator+=(double &money, const Billable &B) {
  money = money + B.price();
  return money;
}
} // namespace seneca
