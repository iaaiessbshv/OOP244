/* Citation and Sources...
-----------------------------------------------------------
Assignment 1
Module: cstr
Filename: cstr.h
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

#ifndef SENECA_CSTR_H
#define SENECA_CSTR_H

#include <cstddef>

namespace seneca {

char *strcat(char *des, const char *src);

char tolower(char ch);
char *tolower(char *des, const char *src);
char *tolower(char *str);

int strcmp(const char *s1, const char *s2);
int strcmp(const char *s1, const char *s2, size_t len);

char *strcpy(char *des, const char *src);
char *strcpy(char *des, const char *src, size_t len);
char *strncpy(char *des, const char *src, size_t len);

size_t strlen(const char *str);

const char *strstr(const char *str, const char *toFind);

bool isalpha(char ch);
bool isspace(char ch);

} // namespace seneca

#endif
