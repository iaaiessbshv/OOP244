/* Citation and Sources...
-----------------------------------------------------------
Project Milestone 3
Module: Drink
Filename: Drink.h
-----------------------------------------------------------
Author: Issa Abishev
Student number: 175980234
Email: iabishev@myseneca.ca
Subject: OOP244NAA
-----------------------------------------------------------
Revision History
------- --------- ------------------------------------------
Version Date      Reason
V1.0    2026/03/25  Milestone 3: Drink class declaration
-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my work for function whatever.
-----------------------------------------------------------
*/
#ifndef SENECA_DRINK_H
#define SENECA_DRINK_H
#include "Billable.h"
namespace seneca {

class Drink : public Billable {
  char m_size;

public:
  Drink();
  std::ostream &print(std::ostream &ostr = std::cout) const override;
  bool order() override;
  bool ordered() const override;
  std::ifstream &read(std::ifstream &file) override;
  double price() const override;
};

} // namespace seneca

#endif // SENECA_DRINK_H
