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
V1.0    2026/03/26  Milestone 3: Billable , Food, Drink class
-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my work for function whatever.
-----------------------------------------------------------
*/
#ifndef SENECA_DRINK_H
#define SENECA_DRINK_H
#include "Billable.h"
#include <fstream>
namespace seneca {
class Drink : public Billable {
  char m_size = '\0';

public:
  double price() const override;
  bool order() override;
  bool ordered() const override;
  std::ostream &print(std::ostream &ostr = std::cout) const override;
  std::ifstream &read(std::ifstream &file) override;
};
} // namespace seneca
#endif // !SENECA_DRINK_H
