#include "../headers/Validation.h"
#include "../headers/DataBase.h"
#include "../headers/Std_Headers.h"
#include "../headers/string.h"
char Validation_Is_Id_Exist(short Id)
{
    char Valid = VALID_ID;
    Valid = Data_Base_Is_ID_Valid(Id);
    return (Valid);
}

char Validation_Is_Name_Exist(const char *const Name, short *Id)
{
    char Is_Exist = STUDENT_FOUND;
    Is_Exist = Data_Base_Find_By_Name(Name, Id);
    return (Is_Exist);
}

char Validation_Delete_Student(const char *const Name, short Id, char Option)
{
    char Ret_Val = STUDENT_DELETED;
    char Error = 0;
    switch (Option)
    {
    case SEARCH_BY_ID:
        Error = Validation_Is_Id_Exist(Id);
        if (VALID_ID == Error)
        {
            Data_Base_Delete_Student(Id);
        }
        else
        {
            Ret_Val = STUDENT_NOT_FOUND;
        }
        break;
    case SEARCH_BY_NAME:
        Error = Validation_Is_Name_Exist(Name, &Id);
        if (STUDENT_FOUND == Error)
        {
            Data_Base_Delete_Student(Id);
        }
        else
        {
            Ret_Val = STUDENT_NOT_FOUND;
        }
        break;
    default:
        Ret_Val = INVALID_INPUT;
        break;
    }
    return (Ret_Val);
}

char Validation_Get_Student_Mobile(const char *const Name, short Id, char Option, char *const Mobile)
{
    char Ret_Val = FUNC_OK;
    char Error = 0;
    switch (Option)
    {
    case SEARCH_BY_ID:
        Error = Validation_Is_Id_Exist(Id);
        if (VALID_ID == Error)
        {
            String_Copy_String_To_String(Arr[Id].Main_Data.Mobile, MOBILE_LENGTH, Mobile, MOBILE_LENGTH);
        }
        else
        {
            Ret_Val = STUDENT_NOT_FOUND;
        }
        break;
    case SEARCH_BY_NAME:
        Error = Validation_Is_Name_Exist(Name, &Id);
        if (STUDENT_FOUND == Error)
        {
            String_Copy_String_To_String(Arr[Id].Main_Data.Mobile, MOBILE_LENGTH, Mobile, MOBILE_LENGTH);
        }
        else
        {
            Ret_Val = STUDENT_NOT_FOUND;
        }
        break;
    default:
        Ret_Val = INVALID_INPUT;
        break;
    }
    return (Ret_Val);
}
