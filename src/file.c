#include <stdio.h>
#include <string.h>

#include "file.h"
#include "student.h"

/*
    Reads one student from CSV file

    Returns:
    1 -> Success
    0 -> End of file / Invalid record
*/
int readStudent(FILE *fp, Student *s)
{
    char line[MAX_LINE];

    if (fgets(line, sizeof(line), fp) == NULL)
        return 0;

    return sscanf(line,
                  "%d,%49[^,],%d,%9[^\n]",
                  &s->id,
                  s->name,
                  &s->age,
                  s->grade) == 4;
}

/*
    Writes one student to CSV file
*/
void writeStudent(FILE *fp, Student s)
{
    fprintf(fp,
            "%d,%s,%d,%s\n",
            s.id,
            s.name,
            s.age,
            s.grade);
}

/*
    Checks whether student ID already exists
*/
int studentExists(int id)
{
    FILE *fp = fopen(DATA_FILE, "r");

    if (fp == NULL)
        return 0;

    Student s;

    while (readStudent(fp, &s))
    {
        if (s.id == id)
        {
            fclose(fp);
            return 1;
        }
    }

    fclose(fp);
    return 0;
}
