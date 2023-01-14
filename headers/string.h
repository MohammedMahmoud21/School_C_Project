#ifndef STRING_H
#define STRING_H

#include "Std_Headers.h"

/*************************** Functions Prototype *******************************/

/**
 * @brief Function to scan string from user.
 *
 * @param Str pointer to first character address of string.
 * @param Size variable to hold array of character size(for more safety).
 */
void String_Scanf(char *const Str, const unsigned char Size);
/**
 * @brief Function compare two strings.
 *
 * @param Str1 Pointer to first character address of first string.
 * @param Str2 Pointer to first character address of second string.
 * @return char
 *              0 : Equal.
 *              1 : Str1 > Str2.
 *             -1 : Str2 > Str1.
 */
char String_Compare(const char *const Str1, const char *const Str2);

/**
 * @brief Function to count spaces in string.
 *
 * @param Str pointer to first character address of string.
 * @param Size variable to hold array of character size(for more safety).
 * @return char
 */
char String_Count_Spaces(const char *const Str, const unsigned char Size);

/**
 * @brief Function to check if string is all alphabets or not.
 *
 * @param Str pointer to first character address of string.
 * @param Size variable to hold array of character size(for more safety).
 * @return char
 *              0 : Valid.
 *              1 : Not Valid.
 */
char String_Validate_Name(const char *const Str, const unsigned char Size);
/**
 * @brief Function to make sure all string contain digits.
 *
 * @param Str pointer to first character address of string.
 * @param Size variable to hold array of character size(for more safety).
 * @return char
 *              0 : Valid.
 *              1 : Not Valid.
 */
char String_Validate_Digits(const char *const Str, const unsigned char Size);
/**
 * @brief Function to get string length.
 *
 * @param Str pointer to first character address of string.
 * @return char
 */
char String_Length(const char *const Str);

/**
 * @brief Function to tell if strings both are equal or not.
 * @param Str1 Pointer to first character address of first string.
 * @param Str2 Pointer to first character address of second string.
 * @return char
 *              0 : Equal.
 *              1 : Not.
 */
char String_Compare_Exact(const char *const Str1, const char *const Str2);
/**
 * @brief
 *
 * @param Str1      Pointer to first character address of first string.
 * @param Str1_Size variable hold max size of string1.
 * @param Str2      Pointer to first character address of second string.
 * @param Str2_Size variable hold max size of string2.
 */
void String_Copy_String_To_String(char *const Str1, const short Str1_Size, char *const Str2, const short Str2_Size);

#endif /* STRING_H */
