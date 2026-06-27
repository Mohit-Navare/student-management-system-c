#include <stdio.h>
#include "utility.h"

void clearInputBuffer()
{
    int ch;

    while ((ch = getchar()) != '\n' && ch != EOF)
        ;
}

void pressEnter()
{
    printf("\nPress Enter to continue...");
    getchar();
}

void printLine(int length)
{
    for (int i = 0; i < length; i++)
        printf("=");

    printf("\n");
}
