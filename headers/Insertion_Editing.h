#ifndef INSERTION_EDITING_H
#define INSERTION_EDITING_H

/*************************** Functions Prototype *******************************/

/**
 * @brief Function used by user to add student.
 *
 * @return char
 *              DATA_BASE_NO_ERROR.(On Success)
 *              DATA_BASE_FULL.
 */
char Insertion_Add_Student(void);

/**
 * @brief Function edit student data based on option.
 *
 * @param Option Edit_Name - Edit_Mobile - Edit_Age - Edit_Gender.
 * @param Id     variable hold id of student to be edited.
 * @param Buffer hold Name or Mobile based on option entered from user.
 * @param Temp   hold age or gender based on option entered from user.
 * @return char
 *              Edit_Failed.(If input data are invalid).
 *              Edit_Success.
 */
char Editing_Edit_Student_Main_Data(char Option, short Id, char *const Buffer, char *Temp);
/**
 * @brief  Function edit student family data based on Family_Member_option.
 *
 * @param Option Edit_Name - Edit_Mobile - Edit_Age - Edit_Gender.
 * @param Id                    variable hold id of student to edit data related to him.
 * @param Buffer                hold Name or Mobile based on option entered from user.
 * @param Temp                  hold age or gender based on option entered from user.
 * @param Family_Member_Option  variable hold FATHER or MOTHER.
 * @return char
 *              Edit_Failed.(If input data are invalid).
 *              Edit_Success.
 */
char Editing_Edit_Student_Family_Data(char Option, short Id, char *const Buffer, char *Temp, char Family_Member_Option);
/**
 * @brief Function used to add subject.
 *
 * @param Id student id.
 * @return char
 *              0:  Done.
 *              1 : Failed.
 */
char Insertion_Add_Subject(short Id);
/**
 * @brief Function used to delete one subject from student subjects.
 *
 * @param Id         Student Id.
 * @param Subject_Id Subject Number.
 * @return char
 *              0:  Done.
 *              1 : Failed.
 */
char Insertion_Delete_Subject(short Id, char Subject_Id);
/**
 * @brief Function used to Edit one subject from student subjects.
 *
 * @param Id         Student Id.
 * @param Subject_Id Subject Number.
 * @param Option     Edit_Name or Edit_Max_Degree or Edit_Curr_Degree.
 * @return char
 *              0:  Done.
 *              1 : Failed.
 */
char Insertion_Edit_Subjects_Data(short Id, char Subject_Id, char Option);

#endif /* INSERTION_EDITING_H */
