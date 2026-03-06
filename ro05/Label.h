/* Citation and Sources...
-----------------------------------------------------------
Module: Label.h
Filename: Label.h
-----------------------------------------------------------
Author: Issa Abishev
Student number: 175980234
Email: iabishev@myseneca.ca
Subject: OOP244NAA
-----------------------------------------------------------
Revision History
------- --------- ------------------------------------------
Version Date      Reason
V1.0    2025/3/6  Ready for submission
-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my work for function whatever.
-----------------------------------------------------------
*/

#ifndef SENECA_LABEL_H
#define SENECA_LABEL_H
#include <iostream>
namespace seneca {
class Label {
  char m_fill{};
  char *m_text{};

public:
  explicit Label(const char *text = nullptr, char fill = '*');

  // Rule of Three
  ~Label();
  Label(const Label &other);
  Label &operator=(const Label &other);

  Label &operator=(const char *text);

  std::ostream &print(std::ostream &ostr = std::cout) const;
};

// insertion operator
std::ostream &operator<<(std::ostream &ostr, const Label &label);

} // namespace seneca
#endif // !SENECA_LABEL_H
