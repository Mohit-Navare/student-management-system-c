#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "student.h"
#include "file.h"
#include "utility.h"

/* Add Student */

void addStudent()
{
    Student s;

    printf("\n========== ADD STUDENT ==========\n");

    printf("Enter ID : ");
    scanf("%d", &s.id);
    clearInputBuffer();

    if (studentExists(s.id))
    {
        printf("\nStudent ID already exists.\n");
        return;
    }

    printf("Enter Name : ");
    fgets(s.name, sizeof(s.name), stdin);
    s.name[strcspn(s.name, "\n")] = '\0';

    printf("Enter Age : ");
    scanf("%d", &s.age);
    clearInputBuffer();

    printf("Enter Grade : ");
    fgets(s.grade, sizeof(s.grade), stdin);
    s.grade[strcspn(s.grade, "\n")] = '\0';

    FILE *fp = fopen(DATA_FILE, "a");

    if (fp == NULL)
    {
        printf("Unable to open file.\n");
        return;
    }

    writeStudent(fp, s);

    fclose(fp);

    printf("\nStudent Added Successfully.\n");
}
void displayStudents()
{
    FILE *fp = fopen(DATA_FILE, "r");

    if (fp == NULL)
    {
        printf("\nNo Records Found.\n");
        return;
    }

    Student s;

    printLine(60);
    printf("%-10s%-20s%-10s%-10s\n",
           "ID", "NAME", "AGE", "GRADE");
    printLine(60);

    while (readStudent(fp, &s))

    {
        printf("%-10d%-20s%-10d%-10s\n",
               s.id,
               s.name,
               s.age,
               s.grade);
    }

    printLine(60);

    fclose(fp);
}
void searchStudent()
{
    int id;

    printf("\nEnter Student ID : ");
    scanf("%d", &id);
    clearInputBuffer();

    FILE *fp = fopen(DATA_FILE, "r");

    if (fp == NULL)
    {
        printf("No Records Found.\n");
        return;
    }

    Student s;

    while (readStudent(fp, &s))
    {
        if (s.id == id)
        {
            printf("\nStudent Found\n");

            printLine(35);

            printf("ID    : %d\n", s.id);
            printf("Name  : %s\n", s.name);
            printf("Age   : %d\n", s.age);
            printf("Grade : %s\n", s.grade);

            printLine(35);

            fclose(fp);
            return;
        }
    }

    fclose(fp);

    printf("\nStudent Not Found.\n");
}
void updateStudent()
{
    int id, found = 0;

    printf("\n========== UPDATE STUDENT ==========\n");
    printf("Enter Student ID : ");
    scanf("%d", &id);
    clearInputBuffer();

    FILE *fp = fopen(DATA_FILE, "r");

    if (fp == NULL)
    {
        printf("No Records Found.\n");
        return;
    }

    FILE *temp = fopen("data/temp.csv", "w");

    Student s;

    while (readStudent(fp, &s))
    {
        if (s.id == id)
        {
            found = 1;

            printf("\nEnter New Name : ");
            fgets(s.name, sizeof(s.name), stdin);
            s.name[strcspn(s.name, "\n")] = '\0';

            printf("Enter New Age : ");
            scanf("%d", &s.age);
            clearInputBuffer();

            printf("Enter New Grade : ");
            fgets(s.grade, sizeof(s.grade), stdin);
            s.grade[strcspn(s.grade, "\n")] = '\0';
        }

        writeStudent(temp, s);
    }

    fclose(fp);
    fclose(temp);

    remove(DATA_FILE);
    rename("data/temp.csv", DATA_FILE);

    if (found)
        printf("\nStudent Updated Successfully.\n");
    else
        printf("\nStudent Not Found.\n");
}
void deleteStudent()
{
    int id, found = 0;

    printf("\n========== DELETE STUDENT ==========\n");
    printf("Enter Student ID : ");
    scanf("%d", &id);
    clearInputBuffer();

    FILE *fp = fopen(DATA_FILE, "r");

    if (fp == NULL)
    {
        printf("No Records Found.\n");
        return;
    }

    FILE *temp = fopen("data/temp.csv", "w");

    Student s;

    while (readStudent(fp, &s))
    {
        if (s.id == id)
        {
            found = 1;
            continue;
        }

        writeStudent(temp, s);
    }

    fclose(fp);
    fclose(temp);

    remove(DATA_FILE);
    rename("data/temp.csv", DATA_FILE);

    if (found)
        printf("\nStudent Deleted Successfully.\n");
    else
        printf("\nStudent Not Found.\n");
}
