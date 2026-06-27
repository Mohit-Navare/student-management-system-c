#ifndef FILE_H
#define FILE_H

#include <stdio.h>
#include "student.h"

// Reads one student record from the file
int readStudent(FILE *fp, Student *s);

// Writes one student record to the file
void writeStudent(FILE *fp, Student s);

// Checks whether a student ID already exists
int studentExists(int id);

#endif
