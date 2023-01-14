#include "../headers/DataBase.h"
#include "../headers/string.h"
#include "../headers/Std_Headers.h"
/*************************** Global Variables Definations *******************************/

// Main Data Storage Place. BSS section.
Student_t Arr[NR_OF_STUDENTS];
// hold number of student in school.
static short Curr_Nr_Of_Students;

/*************************** Functions Implementations *******************************/

short Data_Base_Get_Curr_Student_Number(void)
{
    return Curr_Nr_Of_Students;
}

void Data_Base_Increase_Students_Number(void)
{
    Curr_Nr_Of_Students++;
}

char Data_Base_Is_School_Full(void)
{
    char Is_Full;
    Is_Full = (Curr_Nr_Of_Students == NR_OF_STUDENTS);
    return (Is_Full);
}

char Data_Base_Is_ID_Valid(short Id)
{
    char Ret_Val = VALID_ID;
    if (0 > Id)
    {
        Ret_Val = NOT_VALID_ID;
    }
    else if (Id >= Curr_Nr_Of_Students)
    {
        Ret_Val = NOT_VALID_ID;
    }
    else
    {
        Ret_Val = VALID_ID;
    }

    return (Ret_Val);
}

char Data_Base_Find_By_Name(const char *const Name, short *Id)
{
    char Ret_Val = STUDENT_FOUND;
    char String_Ret = 1;
    short Counter = 0;
    while ((String_Ret) && (Counter < Curr_Nr_Of_Students))
    {
        String_Ret = String_Compare_Exact(Name, Arr[Counter].Main_Data.Name);
        Counter++;
    }
    if (0 == String_Ret)
    {
        *Id = Counter - (short)1;
    }
    else
    {
        Ret_Val = STUDENT_NOT_FOUND;
    }
    return (Ret_Val);
}

void Data_Base_Delete_Student(short Id)
{
    short Counter = Id;
    while (Counter < Curr_Nr_Of_Students - 1)
    {
        Arr[Counter] = Arr[Counter + 1];
        Counter++;
    }
    Curr_Nr_Of_Students--;
}
