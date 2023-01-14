#include "../headers/Printing.h"
#include "../headers/DataBase.h"
#include "../headers/Std_Headers.h"
#include <windows.h>
#include <unistd.h>

void Printing_Print_All_Students(void)
{
    short Curr_Students_Number = Data_Base_Get_Curr_Student_Number();
    short Student_Counter = 0;
    printf("%-34s   %-7s   %-7s   %-18s   %s\n", "Name", "Gender", "Age", "Mobile", "GPA");
    while (Student_Counter < Curr_Students_Number)
    {
        printf("[%d]%-33s   %-5c   %-5d   %-20s   %0.2lf\n", Student_Counter, Arr[Student_Counter].Main_Data.Name, Arr[Student_Counter].Main_Data.Gender, Arr[Student_Counter].Main_Data.Age, Arr[Student_Counter].Main_Data.Mobile, Arr[Student_Counter].Student_GPA);
        Student_Counter++;
    }
}

void Printing_Print_Student(short Id)
{
    short Counter = (Arr[Id].Number_Of_Subjects) - 1;
    printf("%-34s   %-7s   %-7s   %-18s   %-5s   %-30s   %-2s   %s\n", "Name", "Gender", "Age", "Mobile", "GPA", "Subjects", "Max_Degree", "Student_Degree");
    printf("[%d]%-33s   %-5c   %-5d   %-20s   %0.2lf    ", Id, Arr[Id].Main_Data.Name, Arr[Id].Main_Data.Gender, Arr[Id].Main_Data.Age, Arr[Id].Main_Data.Mobile, Arr[Id].Student_GPA);
    while (Counter >= 0)
    {
        if (1 == (Arr[Id].P_Sub + Counter)->Reserved)
        {
            printf("%-30s   %-10u   %u\n", (Arr[Id].P_Sub + Counter)->Name, (Arr[Id].P_Sub + Counter)->Max_Degree, (Arr[Id].P_Sub + Counter)->Curr_Degree);
            printf("%-34s   %-7s   %-7s   %-18s   %-5s   ", "    ", "    ", "   ", "      ", "   ");
        }
        Counter--;
    }
    printf("\n");
}

void Printing_Print_Call_Student(void)
{
    char Counter = 0;
    char Loop = 4;
    system("cls");
    while (Loop)
    {
        printf("Calling\n");
        for (; Counter < 4; Counter++)
        {
            printf("*");
            sleep(1);
        }
        system("cls");
        Counter = 0;
        Loop--;
    }
    printf("No Response\n");
}

void Printing_Print_Student_Family_Data(short Id)
{
    char Brothers = 0;
    char Counter = 0;
    // Father Data.
    printf("Father Data:\n");
    printf("%-34s   %-7s   %s\n", "Name", "Age", "Mobile");
    printf("%-34s   %-7d   %s\n", Arr[Id].Father.Name, Arr[Id].Father.Age, Arr[Id].Father.Mobile);
    // Mother Data.
    printf("Mother Data:\n");
    printf("%-34s   %-7s   %s\n", "Name", "Age", "Mobile");
    printf("%-34s   %-7d   %s\n", Arr[Id].Mother.Name, Arr[Id].Mother.Age, Arr[Id].Mother.Mobile);
    // Brothers.
    Brothers = Arr[Id].Number_Of_Brothers;
    printf("Brothers/Sisters Data:\n");
    printf("%-34s   %-7s   %s\n", "Name", "Age", "Mobile");
    while (Brothers)
    {
        printf("%-34s   %-7d   %s\n", (Arr[Id].P_Brothers + Counter)->Name, (Arr[Id].P_Brothers + Counter)->Age, (Arr[Id].P_Brothers + Counter)->Mobile);
        Counter++;
        Brothers--;
    }
}

void Printing_Print_Subjects(short Id)
{
    short Counter = 0;
    system("cls");
    printf("%-30s   %-10s   %s\n", "Subject Name", "Max Degree", "Student Degree");
    while (Counter < Arr[Id].Number_Of_Subjects)
    {
        if (1 == (Arr[Id].P_Sub + Counter)->Reserved)
        {
            printf("[%d]%-30s   %-10u   %u\n", Counter, (Arr[Id].P_Sub + Counter)->Name, (Arr[Id].P_Sub + Counter)->Max_Degree, (Arr[Id].P_Sub + Counter)->Curr_Degree);
        }
        else
        {
            ;
        }
        Counter++;
    }
}
