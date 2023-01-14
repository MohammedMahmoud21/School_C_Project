/**
 * @file main.c
 * @author Mohammed Elsayaad.
 * @brief This is the main file in the School project.
 * @version 0.1
 * @date 2023-01-10
 * @LinkedIn: https://www.linkedin.com/in/mohamed-elsayaad2112/
 * @GitHub:   https://github.com/MohammedAshraf2
 */

/*************************** Include Section ********************************/
#include "headers/Insertion_Editing.h"
#include "headers/Std_Headers.h"
#include "headers/Printing.h"
#include "headers/Validation.h"
#include "headers/string.h"
/*************************** Macros Section ********************************/

#define ADD_STUDENT (1)
#define EDIT_STUDENT (2)
#define DELETE_STUDENT (3)
#define PRINT_ALL_STUDENTS (4)
#define PRINT_STUDENT (5)
#define CALL_STUDENT (6)
#define QUIT_PROGRAM ((unsigned int)7)
#define STUDENT (1)
#define PARENTS (2)
#define SUBJECTS (3)

/*************************** Functions Prototype *******************************/

/**
 * @brief Function used to check user input, if finding student is needed.
 *
 * @param Array  empty buffer to fill name in it.
 * @param Size   array maximum size.
 * @param Temp  pointer to return student id in it, if user chose to search by id.
 * @param Option pointer to return searching option (Search By name-Search By Id).
 * @return char
 *              0 : No Error.
 *              1 : Invalid Input.
 */
char Main_Check_Input(char *Array, short Size, signed int *Temp, char *Option);
/**
 * @brief function to help in editing mode, reducing size of code, its responsible for take user input
 *          and see which part he want to edit.
 *
 * @param Array                Empty buffer to return name or mobile in it.
 * @param Size                 Maximum array size.
 * @param Id                   Id of student to be edited.
 * @param Option               To know which person data the user want to modify, student or parents.(PARENTS)-(STUDENT).
 * @param Family_Member_Option Father or mother must be found in it, if user chose to edit parents data.
 * @return char
 *              0 : No Error.
 *              1 : Invalid Input.
 */
char Main_Edit_Person_Data(char *const Array, unsigned char Size, short Id, char Option, char Family_Member_Option);
int main(void)
{
    signed int User_Choice = 0;
    signed int Temp = 0;
    signed int Temp_2 = 0;
    char Edit_Flag = 0;
    char Option = 0;
    char Error = 0;
    char Array[100] = {0};
    char Mobile[14];
    short Id = 0;

    while (QUIT_PROGRAM != User_Choice)
    {
        printf("Enter Option\nChoose (1) to Add New Student.\nChoose (2) to Edit Student Data.\n");
        printf("Choose (3) to Delete Student\nChoose (4) To print All Students\n");
        printf("Choose (5) to print Specific Student\nChoose (6) to call specific student\n");
        printf("Choose (7) to Quit.\n->");
        fflush(stdin);
        User_Choice = 0;
        scanf("%i", &User_Choice);
        switch (User_Choice)
        {
        case ADD_STUDENT:
            Error = Insertion_Add_Student();
            if (DATA_BASE_FULL == Error)
            {
                printf("Can't added more data base is full\n");
            }
            else
            {
                ;
            }
            break;
        case EDIT_STUDENT:
            // Over Head :(.
            Edit_Flag = 0;
            Error = Main_Check_Input(Array, 100, &Temp, &Option);
            if (0 == Error)
            {
                if (SEARCH_BY_ID == Option)
                {
                    Id = Temp;
                    Error = Validation_Is_Id_Exist(Id);
                    if (VALID_ID == Error)
                    {
                        Edit_Flag = 1;
                    }
                    else
                    {
                        printf("Id Doesn't Exist.\n");
                    }
                }
                else
                {
                    // By Name.
                    Error = Validation_Is_Name_Exist(Array, &Id);
                    if (STUDENT_FOUND == Error)
                    {
                        Edit_Flag = 1;
                    }
                    else
                    {
                        printf("No Student by this name.\n");
                    }
                }
                if (1 == Edit_Flag)
                {
                    printf("Choose edit category:\n(1)Student Main Data.\n(2)Parents Data.\n(3)Subjects Data.\nTo quit press any number except the mentioned before.\n->");
                    Temp = 0;
                    scanf("%i", &Temp);
                    switch (Temp)
                    {
                    case STUDENT:
                        Edit_Flag = STUDENT;
                        Main_Edit_Person_Data(Array, 100, Id, Edit_Flag, 1);
                        break;
                    case PARENTS:
                        Edit_Flag = PARENTS;
                        printf("Choose (1) for Father-----(2) For Mother.\n->");
                        scanf("%i", &Temp);
                        if ((FATHER == Temp) || (MOTHER == Temp))
                        {
                            Main_Edit_Person_Data(Array, 100, Id, Edit_Flag, Temp);
                        }
                        else
                        {
                            printf("Invalid Option.\n");
                        }
                        break;
                    case SUBJECTS:
                        printf("Choose:\n(1)Add Subject.\n(2)Delete Subject.\n(3)Edit Subject.\n");
                        scanf("%i", &Temp);
                        switch (Temp)
                        {
                        case 1:
                            Insertion_Add_Subject(Id);
                            break;
                        case 2:
                            Printing_Print_Subjects(Id);
                            printf("\nEnter Subject Number:");
                            scanf("%i", &Temp);
                            Insertion_Delete_Subject(Id, (char)Temp);
                            break;
                        case 3:
                            Printing_Print_Subjects(Id);
                            printf("\nEnter Subject Number:");
                            scanf("%i", &Temp);
                            while (END_EDITING != Temp_2)
                            {
                                printf("(1)Edit Name.\n(2)Edit Max Degree.\n(3)Edit Student Degree\n(5)End Edit");
                                scanf("%i", &Temp_2);
                                switch (Temp_2)
                                {
                                case EDIT_NAME:
                                    Error = Insertion_Edit_Subjects_Data(Id, Temp, EDIT_NAME);
                                    break;
                                case EDIT_MAX_DEGREE:
                                    Error = Insertion_Edit_Subjects_Data(Id, Temp, EDIT_MAX_DEGREE);
                                    break;
                                case EDIT_CURR_DEGREE:
                                    Error = Insertion_Edit_Subjects_Data(Id, Temp, EDIT_CURR_DEGREE);
                                    break;
                                case END_EDITING:
                                    break;
                                default:
                                    printf("Enter Valid Input.\n");
                                    break;
                                }
                                if (0 == Error)
                                {
                                    printf("Done\n");
                                }
                                else
                                {
                                    printf("Fault Input Data\n");
                                    printf("Check your input.\n");
                                }
                            }
                            break;
                        default:
                            printf("Invalid Option.\n");
                        }
                        break;
                    default:
                        printf("Invalid Input Quit Editing Mode.\n");
                        break;
                    }
                }
                else
                {
                    ;
                }
            }
            else
            {
                printf("Invalid Option.\n");
            }
            break;
        case DELETE_STUDENT:
            Error = Main_Check_Input(Array, 100, &Temp, &Option);
            if (0 == Error)
            {
                Error = Validation_Delete_Student(Array, Id, Option);
                if (STUDENT_DELETED == Error)
                {
                    printf("Deleted successfully\n");
                }
                else
                {
                    printf("There isn't student by this name.\n");
                }
            }
            else
            {
                printf("Invalid Input.\n");
            }
            break;
        case PRINT_ALL_STUDENTS:
            Printing_Print_All_Students();
            break;
        case PRINT_STUDENT:
            Error = Main_Check_Input(Array, 100, &Temp, &Option);
            if (0 == Error)
            {
                if (SEARCH_BY_ID == Option)
                {
                    Error = Validation_Is_Id_Exist(Temp);
                    if (VALID_ID == Error)
                    {
                        Printing_Print_Student(Temp);
                        Printing_Print_Student_Family_Data(Temp);
                    }
                    else
                    {
                        printf("There isn't student by this Id.\n");
                    }
                }
                else if (SEARCH_BY_NAME == Option)
                {
                    Error = Validation_Is_Name_Exist(Array, &Id);
                    if (STUDENT_FOUND == Error)
                    {
                        Printing_Print_Student(Id);
                        Printing_Print_Student_Family_Data(Id);
                    }
                    else
                    {
                        printf("There isn't student by this name.\n");
                    }
                }
                else
                {
                    printf("Invalid Input.\n");
                }
            }
            else
            {
                printf("Invalid Input.\n");
            }
            break;
        case CALL_STUDENT:
            Error = Main_Check_Input(Array, 100, &Temp, &Option);
            if (0 == Error)
            {
                Error = Validation_Get_Student_Mobile(Array, Temp, Option, Mobile);
                if (FUNC_OK == Error)
                {
                    printf("Student mobile is : %s\n", Mobile);
                    printf("Call Student Now??\nEnter (1) for YES, (2) for No\n");
                    scanf("%i", &Temp);
                    if (1 == Temp)
                    {
                        Printing_Print_Call_Student();
                    }
                    else if (2 == Temp)
                    {
                        printf("Okay\n");
                    }
                    else
                    {
                        printf("Invalid Input.\n");
                    }
                }
                else
                {
                    printf("No student found make sure from your input.\n");
                }
            }
            else
            {
                printf("Invalid Input\n");
            }
            break;
        case QUIT_PROGRAM:
            printf("Bye!!.\n");
            break;
        default:
            printf("Follow Program Rules!!!\n");
            break;
        }
        fflush(stdin);
        printf("Press Enter to Continue\n");
        getchar();
        getchar();
        system("cls");
    }

    return 0;
}

char Main_Check_Input(char *Array, short Size, signed int *Temp, char *Option)
{
    char Ret_Val = 0;
    char True = 1;
    char Error = 0;
    char Spaces = 0;
    printf("Choose Find by (1)name or (2)id\n");
    scanf("%i", Temp);
    if (1 == *Temp)
    {
        while (True)
        {
            printf("Enter Full Name till forth name.\n");
            String_Scanf(Array, Size);
            Spaces = String_Count_Spaces(Array, Size);
            if (3 == Spaces)
            {
                True = 0;
            }
            else
            {
                printf("Invalid Enter Full Name.\n");
            }
        }
        *Option = SEARCH_BY_NAME;
    }
    else if (2 == *Temp)
    {
        printf("Enter Id:");
        scanf("%i", Temp);
        *Option = SEARCH_BY_ID;
    }
    else
    {
        Ret_Val = 1;
        *Option = -1;
    }

    return (Ret_Val);
}

char Main_Edit_Person_Data(char *const Array, unsigned char Size, short Id, char Option, char Family_Member_Option)
{
    char Ret_Val = 0;
    char Holder = 0;
    char Error = 0;
    char Flag = 1;
    signed int Temp = 0;
    signed int Choice = 1;
    while (END_EDITING != Choice)
    {
        printf("Choose what to edit? (one at a time please)\n");
        printf("(1)Name.\n(2)Age.\n(3)Gender.\n(4)Mobile.\n(5)End Editing.\n");
        Choice = 0;
        scanf("%i", &Choice);
        Flag = 1;
        switch (Choice)
        {
        case EDIT_NAME:
            printf("Enter New Name\n");
            String_Scanf(Array, Size);
            break;
        case EDIT_AGE:
            printf("Enter New Age:");
            scanf("%i", &Temp);
            Holder = (char)Temp;
            break;
        case EDIT_GENDER:
            printf("Enter Gender:");
            scanf(" %c", &Holder);
            break;
        case EDIT_MOBILE:
            String_Scanf(Array, Size);
            break;
        case END_EDITING:
            printf("Editing Done.\n");
            Flag = 0;
            break;
        default:
            Flag = 0;
            printf("Enter Valid OPtion.\n");
            break;
        }

        if ((PARENTS == Option) && (1 == Flag))
        {
            Error = Editing_Edit_Student_Family_Data(Choice, Id, Array, &Holder, Family_Member_Option);
            if (EDIT_FAILED == Error)
            {
                printf("Edit Failed, Please check the data you entered\n");
            }
            else
            {
                printf("Done.\n");
            }
        }
        else if ((STUDENT == Option) && (1 == Flag))
        {
            Error = Editing_Edit_Student_Main_Data(Choice, Id, Array, &Holder);
            if (EDIT_FAILED == Error)
            {
                printf("Edit Failed, Please check the data you entered\n");
            }
            else
            {
                printf("Done.\n");
            }
        }
        else
        {
            ;
        }
    }

    return (Ret_Val);
}
