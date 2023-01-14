#include "../headers/DataBase.h"
#include "../headers/Insertion_Editing.h"
#include "../headers/string.h"
/*************************** Static Functions Deceleration *******************************/

/**
 * @brief Function to take student main data (Name_Age_Phone_Gender) from user.
 *
 */
static void Insertion_Scan_Student_General_Data(short Curr_Position);
/**
 * @brief Function To get Parents Data.
 *
 */
static void Insertion_Scan_Parents_General_Data(short Curr_Position);
/**
 * @brief Function to insert Family Data (Father-Mother-Brothers).
 *
 */
static void Insertion_Scan_Brothers_Data(short Curr_Position);
/**
 * @brief Function To scan Subjects of student data.
 *
 */
static void Insertion_Scan_Student_Subjects_Data(short Curr_Position);

/**
 * @brief Function To check if name input of person type is valid.
 *
 * @param Ps pointer to struct of type Person_t.
 * @return char
 *              0 : Valid.
 *              1 : Not Valid.
 */
static char Helper_Function_Validate_Name_Input(Person_t *Ps);
static void Helper_Function_Calc_GBA(short Id);
/**
 * @brief Function to check if gender is valid.
 *
 * @param Ps pointer to struct of type Person_t.
 * @return char
 *              0 : Valid.
 *              1 : Not Valid.
 */
static char Helper_Function_Validate_Gender_Input(Person_t *Ps);
/**
 * @brief Function to validate mobile input.
 *
 * @param Ps pointer to struct of type Person_t.
 * @return char
 *              0 : Valid.
 *              1 : Not Valid.
 */
static char Helper_Function_Validate_Mobile_Input(Person_t *Ps);

/**
 * @brief Function used to fill data in any Person type object.
 *
 * @param Ps pointer to struct of type Person_t.
 * @param Curr_Position Variable to till Id of student.
 * @param Gender        variable if equal to 0 then let user enter the gender else then its known gender.(father-mother)case.
 */
static void Helper_Function_Scan_Person_Data(Person_t *Ps, short Curr_Position, char Gender);
/**
 * @brief Function used to fill data in any Subject Type object.
 *
 * @param Ps pointer to struct of type Person_t.
 * @param Curr_Position Variable to till Id of student.
 */
static void Helper_Function_Scan_Subjects_Data(Subject_t *Ps);
/**
 * @brief Helper function to help edit function in validating name input.
 *
 * @param Buffer pointer hold string to check.(Name)
 * @return char
 *              0  : No Error.
 *              -1 : Invalid Input.
 */
static char Helper_Function_Edit_Name(char *const Buffer);
static char Helper_Function_Edit_Mobile(char *const Buffer);
/**
 * @brief Function used to edit (Name-Age-Gender-Mobile) of student.
 *
 * @param Buffer hold Name or Mobile based on option entered from user.
 * @param Temp   hold age or gender based on option entered from user.
 * @param Option Edit_Name - Edit_Mobile - Edit_Age - Edit_Gender.
 * @return char
 *              Edit_Failed.(If input data are invalid).
 *              Edit_Success.
 */
static char Editing_Check_Edit_Student_Main_Data(Person_t *Ps, char *const Buffer, char *Temp, char Option);
/*************************** Functions Implementations *******************************/

char Insertion_Add_Student(void)
{
    char Error_State = DATA_BASE_NO_ERROR;
    short Curr_Position = Data_Base_Get_Curr_Student_Number();
    if (!(Data_Base_Is_School_Full()))
    {
        printf("Please Follow order in adding the student\n");
        Insertion_Scan_Student_General_Data(Curr_Position);
        printf("=============================================\n");
        Insertion_Scan_Parents_General_Data(Curr_Position);
        printf("=============================================\n");
        Insertion_Scan_Brothers_Data(Curr_Position);
        printf("=============================================\n");
        Insertion_Scan_Student_Subjects_Data(Curr_Position);
        printf("=============================================\n");
        printf("Successfully added student.\nSave Student ID [%i]\n", Curr_Position);
        Helper_Function_Calc_GBA(Curr_Position);
        Data_Base_Increase_Students_Number();
    }
    else
    {
        Error_State = DATA_BASE_FULL;
    }
    return (Error_State);
}

char Editing_Edit_Student_Main_Data(char Option, short Id, char *const Buffer, char *Temp)
{
    char Ret_Val = EDIT_SUCCESS;
    Ret_Val = Editing_Check_Edit_Student_Main_Data(&(Arr[Id].Main_Data), Buffer, Temp, Option);
    return (Ret_Val);
}

char Editing_Edit_Student_Family_Data(char Option, short Id, char *const Buffer, char *Temp, char Family_Member_Option)
{
    char Ret_Val = EDIT_FAILED;
    switch (Family_Member_Option)
    {
    case FATHER:
        Ret_Val = Editing_Check_Edit_Student_Main_Data(&(Arr[Id].Father), Buffer, Temp, Option);
        break;
    case MOTHER:
        Ret_Val = Editing_Check_Edit_Student_Main_Data(&(Arr[Id].Mother), Buffer, Temp, Option);
        break;
    default:
        printf("Invalid Option.\n");
        break;
    }
    return (Ret_Val);
}

char Insertion_Add_Subject(short Id)
{
    char Ret_Val = 0;
    char Flag = 0;
    short Sub_Count = 0;
    short Counter = 0;
    Subject_t *P_Sub = NULL;
    Sub_Count = Arr[Id].Number_Of_Subjects + 1;
    while ((Counter < Sub_Count - 1))
    {
        if (!((Arr[Id].P_Sub + Counter)->Reserved))
        {
            Flag = 1;
            break;
        }
        Counter++;
    }
    if (1 == Flag)
    {
        Helper_Function_Scan_Subjects_Data((Arr[Id].P_Sub + Counter));
        Arr[Id].Number_Of_Subjects++;
        Helper_Function_Calc_GBA(Id);
    }
    else
    {
        P_Sub = (Subject_t *)realloc(Arr[Id].P_Sub, Sub_Count * sizeof(Subject_t));
        if (NULL == P_Sub)
        {
            Ret_Val = 1;
        }
        else
        {
            Arr[Id].P_Sub = P_Sub;
            Sub_Count--;
            Helper_Function_Scan_Subjects_Data((Arr[Id].P_Sub + Sub_Count));
            Arr[Id].Number_Of_Subjects++;
            Helper_Function_Calc_GBA(Id);
        }
    }
    return (Ret_Val);
}

char Insertion_Delete_Subject(short Id, char Subject_Id)
{
    char Ret_Val = 0;
    if (Subject_Id < Arr[Id].Number_Of_Subjects)
    {
        (Arr[Id].P_Sub + Subject_Id)->Reserved = 0;
        Helper_Function_Calc_GBA(Id);
    }
    else
    {
        Ret_Val = 1;
    }
    return (Ret_Val);
}

char Insertion_Edit_Subjects_Data(short Id, char Subject_Id, char Option)
{
    char Error_State = 0;
    char Ret_Val = 0;
    char True = 1;
    unsigned int Temp = 0;
    if (Subject_Id < Arr[Id].Number_Of_Subjects)
    {
        switch (Option)
        {
        case EDIT_NAME:
            while (True)
            {
                printf("Name:");
                String_Scanf((Arr[Id].P_Sub + Subject_Id)->Name, SUBJECT_LENGTH);
                Ret_Val = String_Validate_Name((Arr[Id].P_Sub + Subject_Id)->Name, SUBJECT_LENGTH);
                if (0 == Ret_Val)
                {
                    True = 0;
                }
                else
                {
                    printf("Enter Valid Subject Name.\n");
                }
            }
            break;
        case EDIT_MAX_DEGREE:
            while (True)
            {
                printf("Enter Max Subject Degree, [50:250].\n");
                scanf("%u", &Temp);
                if ((50 <= Temp) && (250 >= Temp))
                {
                    (Arr[Id].P_Sub + Subject_Id)->Max_Degree = (unsigned char)Temp;
                    True = 0;
                }
                else
                {
                    printf("Follow school rules please!!!\n");
                }
            }
            Helper_Function_Calc_GBA(Id);
            break;
        case EDIT_CURR_DEGREE:
            while (True)
            {
                printf("Enter Student Degree:");
                scanf("%u", &Temp);
                if ((Temp) > ((Arr[Id].P_Sub + Subject_Id)->Max_Degree))
                {
                    printf("Enter True Degree Don't Cheat\n");
                }
                else if (0 > Temp)
                {
                    printf("Enter Positive Degree :)))\n");
                }
                else
                {
                    (Arr[Id].P_Sub + Subject_Id)->Curr_Degree = (unsigned char)Temp;
                    True = 0;
                }
            }
            Helper_Function_Calc_GBA(Id);
            break;
        default:
            Error_State = 1;
            break;
        }
    }
    else
    {
        Error_State = 1;
    }
    return (Error_State);
}

/*************************** Static Functions Implementations *******************************/

static void Insertion_Scan_Student_General_Data(short Curr_Position)
{
    Curr_Position = Data_Base_Get_Curr_Student_Number();
    printf("Enter Student General Data and follow instructions please.\n");
    printf("Note Number in the [] is student ID\n");
    Helper_Function_Scan_Person_Data(&(Arr[Curr_Position].Main_Data), Curr_Position, 0);
}

static void Insertion_Scan_Parents_General_Data(short Curr_Position)
{
    printf("First Father Data:\n");
    Helper_Function_Scan_Person_Data(&(Arr[Curr_Position].Father), Curr_Position, 'M');
    printf("Second Mother Data:\n");
    Helper_Function_Scan_Person_Data(&(Arr[Curr_Position].Mother), Curr_Position, 'F');
}

static void Insertion_Scan_Brothers_Data(short Curr_Position)
{
    unsigned char True = 1;
    unsigned char Count = 0;
    signed int Temp;
    printf("Enter Number of Brothers.\n");
    while (True)
    {
        scanf("%i", &Temp);
        if (14 < Temp)
        {
            printf("Doesn't need to insert more than 14 brothers-sisters data\n4 is enough\n");
        }
        else
        {
            Arr[Curr_Position].Number_Of_Brothers = (char)Temp;
            True = 0;
        }
    }
    if (0 == Temp)
    {
        ;
    }
    else
    {
        Arr[Curr_Position].P_Brothers = (Person_t *)malloc((Arr[Curr_Position].Number_Of_Brothers) * sizeof(Person_t));
        printf("Enter Brothers-Sisters Data:\n");
        while (Temp)
        {
            printf("Enter [%i]Brother/sister Data:\n", Count + 1);
            Helper_Function_Scan_Person_Data((Arr[Curr_Position].P_Brothers + Count), Curr_Position, 0);
            Temp--;
            Count++;
        }
    }
}

static void Insertion_Scan_Student_Subjects_Data(short Curr_Position)
{
    int Temp;
    char Count = 0;
    char True = 1;
    printf("Fill Number of Subjects first:");
    while (True)
    {
        scanf("%i", &Temp);
        if (0 == Temp)
        {
            printf("Sure he is student?\nEnter Valid Number!!.\n");
        }
        else
        {
            True = 0;
        }
    }

    Arr[Curr_Position].Number_Of_Subjects = (char)Temp;
    Arr[Curr_Position].P_Sub = (Subject_t *)malloc((Arr[Curr_Position].Number_Of_Subjects) * sizeof(Subject_t));
    printf("Now Fill Subjects Data One By One.\n");
    while (Temp)
    {
        printf("[%i]Subject Data:\n", Count);
        Helper_Function_Scan_Subjects_Data((Arr[Curr_Position].P_Sub + Count));
        Temp--;
        Count++;
    }
}

static void Helper_Function_Scan_Person_Data(Person_t *Ps, short Curr_Position, char Gender)
{
    char True = 1;
    char Ret_Val = 0;
    signed int Temp;
    signed int Diff = 0;
    Curr_Position = Data_Base_Get_Curr_Student_Number();
    printf("Enter Full Name till forth name\n");
    while (True)
    {
        printf("[%i].Name:", Curr_Position);
        String_Scanf(Ps->Name, PERSON_NAME_LENGTH);
        Ret_Val = Helper_Function_Validate_Name_Input(Ps);
        if (0 == Ret_Val)
        {
            True = 0;
        }
        else
        {
            printf("Enter Valid Name\n");
        }
    }
    True = 1;
    if ((char)0 == Gender)
    {
        while (True)
        {
            printf("Enter M for Male F for Female.\n");
            printf("[%i].Gender:", Curr_Position);
            scanf(" %c", &(Ps->Gender));
            Ret_Val = Helper_Function_Validate_Gender_Input(Ps);
            if (0 == Ret_Val)
            {
                True = 0;
            }
            else
            {
                printf("Enter Valid Gender Boy(M-m) or Girl(F-f).!!\n");
                getchar();
            }
        }
    }
    else
    {
        Ps->Gender = Gender;
    }
    True = 1;
    Temp = 0;
    while (True)
    {
        printf("[%i].Age:", Curr_Position);
        scanf("%i", &Temp);
        Diff = 20;
        if (0 != Gender)
        {
            Diff = Temp - Arr[Curr_Position].Main_Data.Age;
        }
        else
        {
            ;
        }
        if ((0 >= Temp) || (100 <= Temp) || (0 > Diff))
        {
            printf("Enter Valid Age!!\n");
            getchar();
            // fflush(stdin);
        }
        else if (10 >= Diff)
        {
            printf("Enter Logical Age!!\n");
        }
        else
        {
            True = 0;
            Ps->Age = (char)Temp;
        }
        Temp = 0;
    }
    True = 1;
    while (True)
    {
        printf("[%i].Phone_Number:", Curr_Position);
        String_Scanf(Ps->Mobile, MOBILE_LENGTH);
        Ret_Val = Helper_Function_Validate_Mobile_Input(Ps);
        if (0 == Ret_Val)
        {
            True = 0;
        }
        else
        {
            printf("Enter Valid Number.\n");
        }
    }
}

static void Helper_Function_Scan_Subjects_Data(Subject_t *Ps)
{
    char True = 1;
    unsigned int Temp = 0;
    char Ret_Val = 0;
    while (True)
    {
        printf("Name:");
        String_Scanf(Ps->Name, SUBJECT_LENGTH);
        Ret_Val = String_Validate_Name(Ps->Name, SUBJECT_LENGTH);
        if (0 == Ret_Val)
        {
            True = 0;
        }
        else
        {
            printf("Enter Valid Subject Name.\n");
        }
    }
    True = 1;
    while (True)
    {
        printf("Enter Max Subject Degree, [50:250].\n");
        scanf("%u", &Temp);
        if ((50 <= Temp) && (250 >= Temp))
        {
            Ps->Max_Degree = (unsigned char)Temp;
            True = 0;
        }
        else
        {
            printf("Follow school rules please!!!\n");
            getchar();
        }
        Temp = 0;
    }
    True = 1;
    while (True)
    {
        printf("Enter Student Degree:");
        scanf("%u", &Temp);
        if ((Temp) > (Ps->Max_Degree))
        {
            printf("Enter True Degree Don't Cheat\n");
            getchar();
        }
        else if (0 > Temp)
        {
            printf("Enter Positive Degree :)))\n");
            getchar();
        }
        else
        {
            Ps->Curr_Degree = (unsigned char)Temp;
            True = 0;
        }
        Temp = 0;
    }
    Ps->Reserved = 1;
}

static char Helper_Function_Validate_Name_Input(Person_t *Ps)
{
    char Ret_Val = 0; // Valid input.
    char String_Ret = 0;
    String_Ret = String_Validate_Name(Ps->Name, PERSON_NAME_LENGTH);
    if (0 == String_Ret)
    {
        String_Ret = String_Count_Spaces(Ps->Name, PERSON_NAME_LENGTH);
        if (3 != String_Ret)
        {
            Ret_Val = 1;
        }
    }
    else
    {
        Ret_Val = 1;
    }

    return (Ret_Val);
}

static char Helper_Function_Validate_Gender_Input(Person_t *Ps)
{
    char Ret_Val = 0;
    char Temp = 0;
    Temp = Ps->Gender;
    if (!(('M' == Temp) || ('m' == Temp) || ('F' == Temp) || ('f' == Temp)))
    {
        Ret_Val = 1;
    }
    else
    {
        ;
    }
    return (Ret_Val);
}

static char Helper_Function_Validate_Mobile_Input(Person_t *Ps)
{
    char Ret_Val = 0;
    char String_Ret = 0;
    String_Ret = String_Validate_Digits(Ps->Mobile, MOBILE_LENGTH);
    if (0 == String_Ret)
    {
        String_Ret = String_Length(Ps->Mobile);
        if (11 == String_Ret)
        {
            if ('0' == Ps->Mobile[0])
            {
                Ret_Val = 0;
            }
            else
            {
                Ret_Val = 1;
            }
        }
        else
        {
            Ret_Val = 1;
        }
    }
    else
    {
        Ret_Val = 1;
    }
    return (Ret_Val);
}

static char Helper_Function_Edit_Name(char *const Buffer)
{
    char Ret_Val = -1;
    char String_Error = 0;
    String_Error = String_Validate_Name(Buffer, PERSON_NAME_LENGTH);
    if (0 == String_Error)
    {
        String_Error = String_Count_Spaces(Buffer, PERSON_NAME_LENGTH);
        if (3 == String_Error)
        {
            Ret_Val = 0;
        }
        else
        {
            printf("Name isn't valid, Must be till 4th name.\n");
        }
    }
    else
    {
        printf("Name isn't valid, it contains invalid characters or digits.\n");
    }

    return (Ret_Val);
}

static char Helper_Function_Edit_Mobile(char *const Buffer)
{
    char Ret_Val = -1;
    char String_Error = 0;
    String_Error = String_Validate_Digits(Buffer, MOBILE_LENGTH);
    if (0 == String_Error)
    {
        String_Error = String_Length(Buffer);
        if (11 == String_Error)
        {
            if ('0' == Buffer[0])
            {
                Ret_Val = 0;
            }
            else
            {
                ;
            }
        }
        else
        {
            ;
        }
    }
    else
    {
        ;
    }

    return (Ret_Val);
}

static char Editing_Check_Edit_Student_Main_Data(Person_t *Ps, char *const Buffer, char *Temp, char Option)
{
    char Ret_Val = EDIT_FAILED;
    char Error = 0;
    switch (Option)
    {
    case EDIT_NAME:
        Error = Helper_Function_Edit_Name(Buffer);
        if (0 == Error)
        {
            String_Copy_String_To_String(Buffer, PERSON_NAME_LENGTH, Ps->Name, PERSON_NAME_LENGTH);
            Ret_Val = EDIT_SUCCESS;
        }
        else
        {
            ;
        }
        break;
    case EDIT_GENDER:
        if (!(('M' == *Temp) || ('m' == *Temp) || ('f' == *Temp) || ('F' == *Temp)))
        {
            printf("Invalid Gender must be male of female.\n");
        }
        else
        {
            Ps->Gender = *Temp;
            Ret_Val = EDIT_SUCCESS;
        }
        break;
    case EDIT_AGE:
        if ((0 >= *Temp) || (100 <= *Temp))
        {
            printf("InValid Age!!\n");
        }
        else
        {
            Ps->Age = *Temp;
            Ret_Val = EDIT_SUCCESS;
        }
        break;
    case EDIT_MOBILE:
        Error = Helper_Function_Edit_Mobile(Buffer);
        if (0 == Error)
        {
            String_Copy_String_To_String(Buffer, MOBILE_LENGTH, Ps->Mobile, MOBILE_LENGTH);
            Ret_Val = EDIT_SUCCESS;
        }
        else
        {
            printf("Invalid Mobile Number\n");
        }
        break;
    default:
        Ret_Val = EDIT_FAILED;
        break;
    }
    return (Ret_Val);
}

static void Helper_Function_Calc_GBA(short Id)
{
    short Sub_Count = 0;
    double Sum_Max = 0.0;
    double Sum_Student = 0.0;
    double GPA = 0.0;
    short Counter = 0;
    Sub_Count = Arr[Id].Number_Of_Subjects;
    while (Sub_Count)
    {
        if (1 == (Arr[Id].P_Sub + Counter)->Reserved)
        {
            Sum_Max += ((Arr[Id].P_Sub + Counter)->Max_Degree);
            Sum_Student += ((Arr[Id].P_Sub + Counter)->Curr_Degree);
        }
        Sub_Count--;
        Counter++;
    }
    GPA = (Sum_Student) / (Sum_Max);
    GPA = GPA * 4.0;
    Arr[Id].Student_GPA = GPA;
}
