#ifndef VALIDATION_H
#define VALIDATION_H

/*************************** Macros Section ********************************/

#define STUDENT_DELETED (2)
#define SEARCH_BY_ID (1)
#define SEARCH_BY_NAME (0)

/*************************** Functions Prototype *******************************/

/**
 * @brief Abstraction Function Contact with data base to validate user id input.
 *
 * @param Id variable hold id input from user.
 * @return char
 *              VALID_ID
 *              NOT_VALID_ID
 */
char Validation_Is_Id_Exist(short Id);

/**
 * @brief Abstraction Function Contact with data base to validate Input name from user.
 *
 * @param Name pointer to first character address of string.
 * @param Id   pointer to return Id value of that student(in case it found it), if not (it doesn't change it's original value).
 * @return char
 *              STUDENT_FOUND
 *              STUDENT_NOT_FOUND
 */
char Validation_Is_Name_Exist(const char *const Name, short *Id);

/**
 * @brief Function used to delete student from school.
 *
 * @param Option  Variable entered from main, based on user option (Delete by name or id).
 *                  Option = SEARCH_BY_ID or SEARCH_BY_NAME.
 * @return char
 *  @            Student_Not_Found.
 *  @           STUDENT_DELETED(on success).
 *  @            INVALID_INPUT : if option is not valid.
 */
char Validation_Delete_Student(const char *const Name, short Id, char Option);

/**
 * @brief Function used to search for mobile number of student.
 *
 * @param Option  Variable entered from main, based on user option (Delete by name or id).
 *                  Option = SEARCH_BY_ID or SEARCH_BY_NAME.
 * @param Mobile Pointer to return mobile number in it, on success but if failed it won't change it.
 * @return char
 *  @            Student_Not_Found.
 *  @           FUNC_OK(on success).
 *  @            INVALID_INPUT : if option is not valid.
 */
char Validation_Get_Student_Mobile(const char *const Name, short Id, char Option, char *const Mobile);

#endif /* VALIDATION_H */
