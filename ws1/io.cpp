/* Citation and Sources...
-----------------------------------------------------------
Assignment 1
Module: io
Filename: io.cpp
-----------------------------------------------------------
Author: Issa Abishev
Student number: 175-980-234
Email: iabishev@myseneca.ca
Subject: OOP244NRA
-----------------------------------------------------------
Revision History
------- --------- ------------------------------------------
Version Date      Reason
V1.0    2026/5/15  Ready for submission
-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my work for function whatever.
-----------------------------------------------------------
*/

#include "io.h"
#include "cstr.h"
#include <iostream>

using namespace std;
namespace seneca {

void read(char *name) {
  cout << "name>\n ";
  cin >> name;
}

void print(long long phone) {
  long long area = phone / 10000000;
  long long mid = (phone / 10000) % 1000;
  long long last = phone % 10000;

  cout << "(" << area << ") ";

  cout.fill('0');
  cout.width(3);
  cout << mid << "-";

  cout.width(4);
  cout << last;

  cout.fill(' ');
}

void print(const PhoneRec &rec, size_t &row, const char *filter) {
  bool match = true;

  if (filter) {
    match = strstr(rec.name, filter) || strstr(rec.lastname, filter);
  }

  if (match) {
    cout << row << ": " << rec.name << " " << rec.lastname << " ";
    print(rec.phone);
    cout << endl;
    row++;
  }
}

bool read(PhoneRec &rec, FILE *fptr) {
  return fscanf(fptr, "%s %s %lld", rec.name, rec.lastname, &rec.phone) == 3;
}

void print(PhoneRec *recs[], size_t size, const char *filter) {
  size_t row = 1;
  for (size_t i = 0; i < size; i++) {
    print(*recs[i], row, filter);
  }
}

void setPointers(PhoneRec *ptrs[], PhoneRec recs[], size_t size) {
  for (size_t i = 0; i < size; i++) {
    ptrs[i] = &recs[i];
  }
}

void sort(PhoneRec *ptrs[], size_t size, bool byLastName) {
  for (size_t i = 0; i < size - 1; i++) {
    for (size_t j = i + 1; j < size; j++) {
      int cmp;
      if (byLastName) {
        cmp = strcmp(ptrs[i]->lastname, ptrs[j]->lastname);
      } else {
        cmp = strcmp(ptrs[i]->name, ptrs[j]->name);
      }

      if (cmp > 0) {
        PhoneRec *temp = ptrs[i];
        ptrs[i] = ptrs[j];
        ptrs[j] = temp;
      }
    }
  }
}
} // namespace seneca
