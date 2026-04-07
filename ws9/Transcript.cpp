/* Citation and Sources...
-----------------------------------------------------------
Workshop 9
Module: Transcript
Filename: Transcript.h
-----------------------------------------------------------
Author: Issa Abishev
Student number: 175980234
Email: iabishev@myseneca.ca
Subject: OOP244NAA
-----------------------------------------------------------
Revision History
------- --------- ------------------------------------------
Version Date      Reason
V1.0    2026/4/5  Ready for submission
-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my work for function whatever.
-----------------------------------------------------------
*/
#include "Transcript.h"
#include "Utils.h"

namespace seneca {

Transcript::Transcript(const char *name, unsigned int number)
    : stud_number(number) {
  ut.alocpy(student_name, name);
}

Transcript::Transcript(const Transcript &other) : Marks(other) {
  ut.alocpy(student_name, other.student_name);
  stud_number = other.stud_number;
}

Transcript &Transcript::operator=(const Transcript &other) {
  if (this != &other) {      // Guard against self-assignment
    Marks::operator=(other); // Copy base class attributes
    ut.alocpy(student_name, other.student_name);
    stud_number = other.stud_number;
  }
  return *this;
}

Transcript::~Transcript() {
  delete[] student_name;
  student_name = nullptr;
}

std::ostream &Transcript::display(std::ostream &ostr) const {
  ostr << student_name << " (" << stud_number << ")\n";
  ostr << "--------------------------------------------------------------------"
          "------\n";
  Marks::display(ostr);
  return ostr;
}
} // namespace seneca
