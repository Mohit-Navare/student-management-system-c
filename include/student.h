#ifndef STUDENT_H
#define STUDENT_H

#define DATA_FILE "data/students.csv"

#define MAX_NAME 50
#define MAX_GRADE 10
#define MAX_LINE 200

typedef struct
{
    int id;
    char name[MAX_NAME];
    int age;
    char grade[MAX_GRADE];
} Student;

/* Student Operations */

void addStudent();
void displayStudents();
void searchStudent();
void updateStudent();
void deleteStudent();

#endif
