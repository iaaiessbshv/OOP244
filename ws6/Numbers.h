/* Citation and Sources...
-----------------------------------------------------------
Workshop 6
Module: Numbers
Filename: Numbers.h
-----------------------------------------------------------
Author: Issa Abishev
Student number: 175980234
Email: iabishev@myseneca.ca
Subject: OOP244NAA
-----------------------------------------------------------
Revision History
------- --------- ------------------------------------------
Version Date      Reason
V1.0    2025/3/12  Ready for submission
-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my work for function whatever.
-----------------------------------------------------------
*/
#ifndef SENECA_NUMBERS_H_
#define SENECA_NUMBERS_H_
#include <iostream>
namespace seneca {
class Numbers {
  double *m_numbers;
  char *m_filename;
  bool m_isOriginal;
  int m_numCount;
  bool isEmpty() const;
  void setEmpty();
  void setFilename(const char *filename);
  void sort();
  int numberCount() const;
  bool load();
  void save() const;

public:
  Numbers();
  Numbers(const char *filename);
  Numbers(const Numbers &other);
  Numbers &operator=(const Numbers &other);
  ~Numbers();
  Numbers &operator+=(double value);
  std::ostream &display(std::ostream &ostr) const;
  double average() const;
  double max() const;
  double min() const;
};
std::ostream &operator<<(std::ostream &os, const Numbers &N);
std::istream &operator>>(std::istream &istr, Numbers &N);
} // namespace seneca
#endif
