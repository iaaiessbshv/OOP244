/***********************************************************************
// OOP244 Project, Utils Module
//
// File  Utils.h
// Version 0.2
// started by Fardad
// Description
// utility function to be used in the project
// Revision History
// -----------------------------------------------------------
// Name               Date          Reason
// Fardad             -             Initial version
// Issa Abishev       2026/03/25    Milestone 2: Added getInt() and getInt(int
min, int max)
/////////////////////////////////////////////////////////////////
***********************************************************************/
#ifndef SENECA_UTILS_H
#define SENECA_UTILS_H
namespace seneca {
class Utils {
public:
  char *alocpy(const char *src) const;
  char *alocpy(char *&des, const char *src) const;
  char *strcpy(char *des, const char *src) const;
  int strlen(const char *str) const;
  bool isspace(char ch) const;
  bool isspace(const char *cstring) const;
  int getInt() const;
  int getInt(int min, int max) const;
};
extern Utils ut;
} // namespace seneca

#endif // !SENECA_UTILS_H
