/*
 Name: Issa Abishev
 Course: OOP244 NAA
 Date: March 6th , 2026
 _______________________
 Partially completed by professor Fardad Soleimanloo
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

  // Assignment to text (set/reset m_text)
  Label &operator=(const char *text);

  std::ostream &print(std::ostream &ostr = std::cout) const;
};

// insertion operator
std::ostream &operator<<(std::ostream &ostr, const Label &label);

} // namespace seneca
#endif // !SENECA_LABEL_H
