#include <stdio.h>

//
// Created by George Marr on 21/11/2017.
//
int main()
{
    int64_t CFR = 0;

    FILE * fp;
    if(fopen((const char *) &fp, "readme.txt") != (FILE *) CFR)
    {
        printf("Cannot open file");
        return 0;
    }

    char String[20] = "Input data";
    fprintf(fp, String);
    fclose(fp);
}
