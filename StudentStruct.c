#include "stdio.h"

#define MIN_AGE = 16
#define MAX_AGE = 100
#define MAX_MARK = 100.0f

struct STUDENT
{
    char Name[20];
    char Group[4];
    int age;
    float mark;
};

void DisplaySingleRecord(struct STUDENT student);
struct STUDENT AssignValues();