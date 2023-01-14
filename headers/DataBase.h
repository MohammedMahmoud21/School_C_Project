#ifndef DATABASE_H
#define DATABASE_H
/*************************** Macros Section ********************************/

#define NR_OF_STUDENTS ((short)1000)
#define PERSON_NAME_LENGTH ((char)100)
#define MOBILE_LENGTH ((char)12)
#define SUBJECT_LENGTH ((char)30)

/*************************** Structs Section *******************************/

/**
 * @brief General struct describe person data.
 *
 */
typedef struct
{
    char Name[PERSON_NAME_LENGTH];
    char Mobile[MOBILE_LENGTH];
    char Gender;
    char Age;
} Person_t;

/**
 * @brief struct describe subjects data.
 * @Note Reserved is used to know if this subject still with student or was deleted.
 *          if it was 1 then still with him, 0 then not.
 */
typedef struct
{
    char Name[SUBJECT_LENGTH];
    unsigned char Max_Degree; // max 250
    unsigned char Curr_Degree;
    char Reserved;
} Subject_t;

/**
 * @brief struct to describe student data.
 *
 */
typedef struct Student
{
    Person_t Main_Data;
    Person_t Father;
    Person_t Mother;
    Person_t *P_Brothers;
    Subject_t *P_Sub;
    char Number_Of_Subjects;
    char Number_Of_Brothers;
    float Student_GPA;
} Student_t;

/*************************** Global Variables Declarations *******************************/

extern Student_t Arr[NR_OF_STUDENTS];

/*************************** Functions Prototype *******************************/

/**
 * @brief return current number of students in school.
 *
 * @return short
 */
short Data_Base_Get_Curr_Student_Number(void);

/**
 * @brief Function to increase static variable responsible for number of current students
 *
 */
void Data_Base_Increase_Students_Number(void);

/**
 * @brief To know space available in data base.
 *
 * @return char
 *              1 : No Space.
 *              0 : Space available.
 */
char Data_Base_Is_School_Full(void);
/**
 * @brief Function used to check if wanted id is valid.
 *
 * @param Id variable passed from user through other functions.
 * @return char
 *              Valid_ID     =  0.
 *              NOT_VALID_ID =  1.
 */
char Data_Base_Is_ID_Valid(short Id);

/**
 * @brief Function search in data base for student by his name.
 *
 * @param Name pointer to first character address of string.
 * @param Id pointer to return Id of student in it.
 * @return char
 *              STUDENT_FOUND.
 *              STUDENT_NOT_FOUND.
 */
char Data_Base_Find_By_Name(const char *const Name, short *Id);

/**
 * @brief Function used to shift (delete) students.
 *
 * @param Id Entered from callee function, must be verified before passing to this function.
 */
void Data_Base_Delete_Student(short Id);
#endif /* DATABASE_H */
