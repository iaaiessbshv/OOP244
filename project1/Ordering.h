/* Citation and Sources...
-----------------------------------------------------------
Project Milestone 4
Module: Ordering
Filename: Ordering.h
-----------------------------------------------------------
Author: Issa Abishev
Student number: 175980234
Email: iabishev@myseneca.ca
Subject: OOP244NAA
-----------------------------------------------------------
Revision History
------- --------- ------------------------------------------
Version Date      Reason
V1.0    2025/03/30  Milestone 4: Ordering module
-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my work for function whatever.
-----------------------------------------------------------
*/
#ifndef SENECA_ORDERING_H
#define SENECA_ORDERING_H
#include "Billable.h"
#include "Drink.h"
#include "Food.h"
#include "Menu.h"
#include "constants.h"
#include <iostream>
namespace seneca {
class Ordering {
  unsigned int food_counter;
  unsigned int drink_counter;
  unsigned int billable_counter;
  unsigned int serial_n;
  Food *food_arr;
  Drink *drink_arr;
  Billable *bill_items[MaximumNumberOfMenuItems];

  std::ostream &printBillTitle(std::ostream &ostr = std::cout) const;
  std::ostream &printTotal(std::ostream &ostr = std::cout,
                           double value = 0) const;
  size_t countRecords(const char *file) const;

public:
  Ordering(const char *drink_file, const char *food_file);
  ~Ordering();

  operator bool() const;
  unsigned int noOfBillItems() const;
  bool hasUnsavedBill() const;

  void listFoods() const;
  void listDrinks() const;
  void orderFood();
  void orderDrink();
  void printBill(std::ostream &ostr) const;
  void resetBill();
};
} // namespace seneca
#endif // !SENECA_ORDERING_H
