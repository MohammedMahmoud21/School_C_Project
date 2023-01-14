#include "../headers/string.h"

/*************************** Functions Implementations *******************************/

void String_Scanf(char *const Str, const unsigned char Size)
{
    unsigned char Index = 0;
    scanf(" %c", &Str[Index]);
    for (; ('\n' != Str[Index]) && ((unsigned char)Index < Size - 1);)
    {
        Index++;
        scanf("%c", &Str[Index]);
    }
    Str[Index] = 0;
}

char String_Compare(const char *const Str1, const char *const Str2)
{
    char Result = 0; // 0 Equal.
    unsigned int Index = 0;
    unsigned char Diff = 'a' - 'A';
    signed char Temp = 0;
    for (; (Str1[Index]) && (Str2[Index]); Index++)
    {
        Temp = Str1[Index] - Str2[Index];
        Temp = MY_ABS(Temp);
        if ((0 == Temp) || (Diff == Temp))
        {
            ;
        }
        else if (Str1[Index] > Str2[Index])
        {
            Result = 1; // Str1 Larger.
            break;
        }
        else
        {
            Result = -1; // Str2 Larger.
            break;
        }
    }

    if ((Str1[Index]) && (0 == Str2[Index]))
    {
        Result = 1;
    }
    else if ((Str2[Index]) && (0 == Str1[Index]))
    {
        Result = -1;
    }
    else
    {
        ;
    }
    return (Result);
}

char String_Count_Spaces(const char *const Str, const unsigned char Size)
{
    char Spaces = 0;
    unsigned int Index = 1;
    while ((Str[Index]) && ((unsigned char)Index < Size))
    {
        if ((' ' == Str[Index]) && (' ' != Str[Index - 1]))
        {
            Spaces++;
        }
        else
        {
            ;
        }
        Index++;
    }
    return (Spaces);
}

char String_Validate_Name(const char *const Str, const unsigned char Size)
{
    char Valid = 0;
    unsigned char Index = 1;
    while ((Str[Index]) && (Index < Size))
    {
        if ((('a' <= Str[Index]) && ('z' >= Str[Index])) || (('A' <= Str[Index]) && ('Z' >= Str[Index])))
        {
            ;
        }
        else if ((' ' == (Str[Index])) && (' ' != Str[Index - 1]))
        {
            ;
        }
        else
        {
            Valid = 1;
            break;
        }
        Index++;
    }

    return (Valid);
}

char String_Validate_Digits(const char *const Str, const unsigned char Size)
{
    char Valid = 0;
    unsigned char Index = 0;
    while ((Str[Index]) && (Index < Size))
    {
        if (!(('0' <= Str[Index]) && ('9' >= Str[Index])))
        {
            Valid = 1;
            break;
        }
        Index++;
    }

    return (Valid);
}

char String_Length(const char *const Str)
{
    char Length = 0;
    while (Str[Length])
    {
        Length++;
    }

    return (Length);
}

char String_Compare_Exact(const char *const Str1, const char *const Str2)
{
    char Result = 0; // 0 Equal.
    unsigned int Index = 0;
    unsigned char Diff = 'a' - 'A';
    signed char Temp = 0;
    for (; (Str1[Index]) && (Str2[Index]); Index++)
    {
        Temp = Str1[Index] - Str2[Index];
        Temp = MY_ABS(Temp);
        if ((0 == Temp) || (Diff == Temp))
        {
            ;
        }
        else
        {
            Result = 1; // Not Equal.
            break;
        }
    }

    return (Result);
}

void String_Copy_String_To_String(char *const Str1, const short Str1_Size, char *const Str2, const short Str2_Size)
{
    short Index = 0;
    for (; (Str1[Index]) && (Index < Str1_Size) && (Index < Str2_Size); Index++)
    {
        Str2[Index] = Str1[Index];
    }
    Str2[Index] = 0;
}
