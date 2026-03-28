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
V1.0    2025/03/23  Milestone 3: Billable abstract base class
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
  char *m_name;
  double m_price;

protected:
  void price(double value);
  void name(const char *name);

public:
  // Constructors & Rule of Three
  Billable();
  Billable(const Billable &other);
  Billable &operator=(const Billable &other);
  virtual ~Billable();

  // Virtual
  virtual double price() const;

  // Pure Virtuals
  virtual std::ostream &print(std::ostream &ostr = std::cout) const = 0;
  virtual bool order() = 0;
  virtual bool ordered() const = 0;
  virtual std::ifstream &read(std::ifstream &file) = 0;

  // Conversion operator
  operator const char *() const;
};

// Helper operators
double operator+(double money, const Billable &B);
double &operator+=(double &money, const Billable &B);

} // namespace seneca

#endif // SENECA_BILLABLE_H
