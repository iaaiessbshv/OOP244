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
V1.0    2025/03/26  Milestone 3: Billable , Food, Drink class
-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my work for function whatever.
-----------------------------------------------------------
*/
#ifndef SENECA_BILLABLE_H
#define SENECA_BILLABLE_H
#include <fstream>
#include <iostream>
namespace seneca {
class Billable {
  char *m_name = nullptr;
  double m_price = 0;

protected:
  void price(double value);
  void name(const char *name);

public:
  Billable();
  // Rule of three
  Billable(const Billable &);
  Billable &operator=(const Billable &);
  virtual ~Billable();
  // virtual methods
  virtual double price() const;
  // pure virtual methods
  virtual std::ostream &print(std::ostream &ostr = std::cout) const = 0;
  virtual bool order() = 0;
  virtual bool ordered() const = 0;
  virtual std::ifstream &read(std::ifstream &file) = 0;
  // Conversion operator
  operator const char *() const;
};

// operator overloads
double operator+(double money, const Billable &B);
double &operator+=(double &money, const Billable &B);

} // namespace seneca

#endif // !SENECA_BILLABLE_H
