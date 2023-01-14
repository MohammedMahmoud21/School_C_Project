#ifndef STD_HEADERS_H
#define STD_HEADERS_H

#include <stdlib.h>
#include <stdio.h>
/*************************** Macros Section ********************************/

/**
 * Function to get absolute value of number.
 */
#define MY_ABS(Num) ((Num) * (((2 * Num) + (1)) % (2)))
#define DATA_BASE_FULL 1
#define DATA_BASE_NO_ERROR 0
#define VALID_ID (0)
#define NOT_VALID_ID (1)
#define STUDENT_FOUND (0)
#define STUDENT_NOT_FOUND (1)
#define FUNC_OK (0)
#define INVALID_INPUT (-1)
#define EDIT_SUCCESS (0)
#define EDIT_FAILED (1)
#define EDIT_NAME (1)
#define EDIT_GENDER (3)
#define EDIT_AGE (2)
#define EDIT_MOBILE (4)
#define END_EDITING (5)
#define EDIT_MAX_DEGREE (2)
#define EDIT_CURR_DEGREE (3)
#define FATHER (1)
#define MOTHER (2)
#endif /* STD_HEADERS_H */
