#ifndef PRINTING_H
#define PRINTING_H

/*************************** Functions Prototype *******************************/

void Printing_Print_All_Students(void);
/**
 * @brief Function print one student only.
 * Note: Id Must be returned from one of the functions in validation file.
 *
 * @param Id variable hold id of student wanted to be printed.
 */
void Printing_Print_Student(short Id);

void Printing_Print_Call_Student(void);
/**
 * @brief Function print student family data (Father Mother Brothers).
 * Note: Id Must be returned from one of the functions in validation file.
 *
 * @param Id variable hold id of student wanted to be printed.
 */
void Printing_Print_Student_Family_Data(short Id);

void Printing_Print_Subjects(short Id);

#endif /* PRINTING_H */
