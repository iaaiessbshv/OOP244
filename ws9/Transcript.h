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
#ifndef SENECA_TRANSCRIPT_H
#define SENECA_TRANSCRIPT_H

#include "Marks.h"

namespace seneca {

class Transcript : public Marks {
  char *student_name{};
  unsigned int stud_number{};

public:
  Transcript(const char *name, unsigned int number);
  Transcript(const Transcript &other);
  Transcript &operator=(const Transcript &other);
  ~Transcript();

  std::ostream &display(std::ostream &ostr = std::cout) const override;
};

} // namespace seneca

#endif // !SENECA_TRANSCRIPT_H
