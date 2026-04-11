/* Citation and Sources...
-----------------------------------------------------------
Project Milestone 4
Module: Ordering
Filename: Ordering.cpp
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
#include "Ordering.h"
#include "Menu.h"
#include "Utils.h"
#include "constants.h"
#include <cstddef>
#include <fstream>
#include <iostream>
using namespace std;
namespace seneca {

ostream &Ordering::printBillTitle(ostream &ostr) const {
  ostr << "Bill # ";
  if (serial_n < 100)
    ostr << "0";
  if (serial_n < 10)
    ostr << "0";
  ostr << serial_n << " =============================" << endl;
  return ostr;
}

ostream &Ordering::printTotal(ostream &ostr, double value) const {
  double tax_amount = value * Tax / 100.0;
  double grand_total = value + tax_amount;
  ostr.setf(ios::fixed);
  ostr.precision(2);
  ostr << "                     Total:         " << value << endl
       << "                     Tax:           " << tax_amount << endl
       << "                     Total+Tax:    " << grand_total << endl
       << "========================================" << endl;
  ostr.unsetf(ios::fixed);
  return ostr;
}

size_t Ordering::countRecords(const char *file) const {
  size_t count = 0;
  ifstream fin(file);
  if (!fin)
    return 0;
  char ch;
  while (fin.get(ch)) {
    if (ch == '\n')
      count++;
  }
  return count;
}

Ordering::Ordering(const char *drink_file, const char *food_file)
    : food_counter(0), drink_counter(0), billable_counter(0), serial_n(1),
      food_arr(nullptr), drink_arr(nullptr) {

  // Initialize bill_items array to nullptr
  for (size_t i = 0; i < MaximumNumberOfMenuItems; i++) {
    bill_items[i] = nullptr;
  }

  const size_t drink_size = countRecords(drink_file);
  const size_t food_size = countRecords(food_file);

  drink_arr = new Drink[drink_size];
  food_arr = new Food[food_size];

  ifstream if_drink(drink_file);
  ifstream if_food(food_file);

  size_t drink_read = 0;
  size_t food_read = 0;

  if (if_drink && if_food) {
    for (size_t i = 0; i < drink_size; i++) {
      if (drink_arr[i].read(if_drink)) {
        drink_read++;
      } else {
        break;
      }
    }
    for (size_t i = 0; i < food_size; i++) {
      if (food_arr[i].read(if_food)) {
        food_read++;
      } else {
        break;
      }
    }

    // Validation and cleanup
    if (drink_read != drink_size || food_read != food_size) {
      delete[] drink_arr;
      delete[] food_arr;
      drink_arr = nullptr;
      food_arr = nullptr;
    } else {
      drink_counter = (unsigned int)drink_read;
      food_counter = (unsigned int)food_read;
    }
  } else {
    // Files failed to open
    delete[] drink_arr;
    delete[] food_arr;
    drink_arr = nullptr;
    food_arr = nullptr;
  }
}

Ordering::~Ordering() {
  delete[] food_arr;
  food_arr = nullptr;
  delete[] drink_arr;
  drink_arr = nullptr;
  for (unsigned int i = 0; i < billable_counter; i++) {
    delete bill_items[i];
    bill_items[i] = nullptr;
  }
}

Ordering::operator bool() const {
  return drink_arr != nullptr && food_arr != nullptr;
}

unsigned int Ordering::noOfBillItems() const { return billable_counter; }

bool Ordering::hasUnsavedBill() const { return billable_counter > 0; }

void Ordering::listFoods() const {
  cout << "List Of Avaiable Meals" << endl;
  cout << "========================================" << endl;
  for (unsigned int i = 0; i < food_counter; i++) {
    food_arr[i].print(cout);
    cout << endl;
  }
  cout << "========================================" << endl;
}

void Ordering::listDrinks() const {
  cout << "List Of Avaiable Drinks" << endl;
  cout << "========================================" << endl;
  for (unsigned int i = 0; i < drink_counter; i++) {
    drink_arr[i].print(cout);
    cout << endl;
  }
  cout << "========================================" << endl;
}

void Ordering::orderFood() {
  Menu foodMenu("Food Menu", "Back to Order", 2);
  for (unsigned int i = 0; i < food_counter; i++) {
    foodMenu << (const char *)food_arr[i];
  }
  size_t selection = cout << foodMenu;
  if (selection != 0) {
    // Dynamic copy of selected food item
    Food *item = new Food(food_arr[selection - 1]);
    bill_items[billable_counter] = item;
    if (item->order()) {
      billable_counter++;
    } else {
      delete item;
      bill_items[billable_counter] = nullptr;
    }
  }
}

void Ordering::orderDrink() {
  Menu drinkMenu("Drink Menu", "Back to Order", 2);
  for (unsigned int i = 0; i < drink_counter; i++) {
    drinkMenu << (const char *)drink_arr[i];
  }
  size_t selection = cout << drinkMenu;
  if (selection != 0) {
    Drink *item = new Drink(drink_arr[selection - 1]);
    bill_items[billable_counter] = item;
    if (item->order()) {
      billable_counter++;
    } else {
      delete item;
      bill_items[billable_counter] = nullptr;
    }
  }
}

void Ordering::printBill(ostream &ostr) const {
  double total = 0.0;
  printBillTitle(ostr);
  for (unsigned int i = 0; i < billable_counter; i++) {
    bill_items[i]->print(ostr);
    ostr << endl;
    total += bill_items[i]->price();
  }
  printTotal(ostr, total);
}

void Ordering::resetBill() {
  char filename[30];
  ut.makeBillFileName(filename, serial_n);

  // Save bill to file
  ofstream billFile(filename);
  printBill(billFile);

  cout << "Saved bill number " << serial_n << endl;
  serial_n++;
  cout << "Starting bill number " << serial_n << endl;

  for (unsigned int i = 0; i < billable_counter; i++) {
    delete bill_items[i];
    bill_items[i] = nullptr;
  }

  billable_counter = 0;
}

} // namespace seneca
