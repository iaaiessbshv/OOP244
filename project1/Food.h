/* Citation and Sources...
-----------------------------------------------------------
Project Milestone 3
Module: Food
Filename: Food.h
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
#ifndef SENECA_FOOD_H
#define SENECA_FOOD_H
#include "Billable.h"
namespace seneca {
class Food : public Billable {
  bool m_ordered = false;
  bool m_child = false;
  char *m_customize = nullptr;

public:
  // Rule of three
  Food() = default;
  Food(const Food &other);
  Food &operator=(const Food &other);
  ~Food();

  bool order() override;
  bool ordered() const override;
  double price() const override;
  std::ostream &print(std::ostream &ostr = std::cout) const override;
  std::ifstream &read(std::ifstream &file) override;
};
} // namespace seneca
#endif
