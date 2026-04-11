/* Citation and Sources...
-----------------------------------------------------------
Project Milestone 5
Module: Main App
Filename: main.cpp
-----------------------------------------------------------
Author: Issa Abishev
Student number: 175980234
Email: iabishev@myseneca.ca
Subject: OOP244NAA
-----------------------------------------------------------
Revision History
------- --------- ------------------------------------------
Version Date      Reason
V1.0    2026/04/10  Milestone 5
-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my work for function whatever.
-----------------------------------------------------------
*/
#include "Menu.h"
#include "Ordering.h"
#include <iostream>
using namespace std;
using namespace seneca;

int main() {
  // Initialize Ordering with data files
  Ordering ord("drinks.csv", "foods.csv");

  // Validate that data files loaded successfully
  if (!ord) {
    cout << "Failed to open data files or the data files are corrupted!"
         << endl;
    return 1;
  }

  // Build main menu
  Menu mainMenu("Seneca Restaurant ", "End Program");
  mainMenu << "Order"
           << "Print Bill"
           << "Start a New Bill"
           << "List Foods"
           << "List Drinks";

  // Build order sub-menu
  Menu orderMenu("Order Menu", "Back to main menu", 1);
  orderMenu << "Food"
            << "Drink";

  // Build exit confirmation menu
  Menu confirmMenu(
      "You have bills that are not saved. Are you sue you want to exit?", "No",
      1);
  confirmMenu << "Yes";

  bool running = true;
  while (running) {
    size_t mainSel = cout << mainMenu;

    switch (mainSel) {
    case 1: { // Order
      bool ordering = true;
      while (ordering) {
        size_t orderSel = cout << orderMenu;
        switch (orderSel) {
        case 1:
          ord.orderFood();
          break;
        case 2:
          ord.orderDrink();
          break;
        case 0:
          ordering = false;
          break;
        }
      }
      break;
    }
    case 2: // Print Bill
      ord.printBill(cout);
      break;
    case 3: // Start a New Bill
      ord.resetBill();
      break;
    case 4: // List Foods
      ord.listFoods();
      break;
    case 5: // List Drinks
      ord.listDrinks();
      break;
    case 0: // End Program
      if (ord.hasUnsavedBill()) {
        size_t confirmSel = cout << confirmMenu;
        if (confirmSel == 1) {
          running = false;
        }
      } else {
        running = false;
      }
      break;
    }
  }
  return 0;
}
