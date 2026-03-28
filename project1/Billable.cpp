/* Citation and Sources...
-----------------------------------------------------------
Project Milestone 3
Module: Billable
Filename: Billable.cpp
-----------------------------------------------------------
Author: Issa Abishev
Student number: 175980234
Email: iabishev@myseneca.ca
Subject: OOP244NAA
-----------------------------------------------------------
Revision History
------- --------- ------------------------------------------
Version Date      Reason
V1.0    2025/03/23  Milestone 3: Billable implementation
-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my work for function whatever.
-----------------------------------------------------------
*/
#include "Billable.h"
#include "Utils.h"
using namespace std;
namespace seneca {

// Default constructor
Billable::Billable() : m_name(nullptr), m_price(0.0) {}

// Copy constructor
Billable::Billable(const Billable &other) : m_name(nullptr), m_price(0.0) {
  *this = other;
}

// Copy assignment
Billable &Billable::operator=(const Billable &other) {
  if (this != &other) {
    ut.alocpy(m_name, other.m_name);
    m_price = other.m_price;
  }
  return *this;
}

// Destructor
Billable::~Billable() { delete[] m_name; }

// Protected setters
void Billable::price(double value) { m_price = value; }

void Billable::name(const char *name) { ut.alocpy(m_name, name); }

// Virtual price getter
double Billable::price() const { return m_price; }

// Conversion operator
Billable::operator const char *() const { return m_name; }

// Helper operators
double operator+(double money, const Billable &B) { return money + B.price(); }

double &operator+=(double &money, const Billable &B) {
  money += B.price();
  return money;
}

} // namespace seneca
