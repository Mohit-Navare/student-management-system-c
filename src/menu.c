#include <stdio.h>
#include <stdlib.h>

#include "menu.h"
#include "student.h"
#include "utility.h"

void menu()
{
    int choice;

    do
    {
#ifdef _WIN32
        system("cls");
#else
        system("clear");
#endif

        printLine(50);
        printf("      STUDENT MANAGEMENT SYSTEM\n");
        printLine(50);

        printf("1. Add Student\n");
        printf("2. Display Students\n");
        printf("3. Search Student\n");
        printf("4. Update Student\n");
        printf("5. Delete Student\n");
        printf("6. Exit\n");

        printLine(50);

        printf("Enter your choice : ");

        if (scanf("%d", &choice) != 1)
        {
            printf("\nInvalid Input!\n");
            clearInputBuffer();
            pressEnter();
            continue;
        }

        clearInputBuffer();

        switch (choice)
        {
        case 1:
            addStudent();
            break;

        case 2:
            displayStudents();
            break;

        case 3:
            searchStudent();
            break;

        case 4:
            updateStudent();
            break;

        case 5:
            deleteStudent();
            break;

        case 6:
            printf("\nThank You!\n");
            break;

        default:
            printf("\nInvalid Choice!\n");
        }

        if (choice != 6)
            pressEnter();

    } while (choice != 6);
}
