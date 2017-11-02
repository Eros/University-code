#include <opencl-c.h>
#include <ctype.h>
#include <stdio.h>
#include <memory.h>
#include <stdlib.h>

#define MAX_DIGITS 20

int checkString(const char *s, size_t n);

int main()
{
    char s[32];
    size_t n;

    fgets(s, sizeof(s), stdin);
    n = strlen(s) - 1;
    s[n] = '\0';

    if(!checkString(s, n))
        puts("String entered");

    return 0;
}

int checkString(const char *s, size_t n)
{
    size_t i;
    for(i = 0; i < n; i++)
        if(!isdigit(s[i]))
            return 0;

    return 1;
}

int checkInput(int value, int okay)
{
    do
    {
        char input[MAX_DIGITS + 2];
        printf("Number required");
        fflush(stdout);
        if(fgets(input, sizeof(input), stdin))
        {
            char *chk = NULL;
            value = (int) strtol(input, &chk, 10);
            if(isspace(*chk) || *chk == 0)
            {
                okay = 1;
            }
            else
            {
                printf("\n%s is not a valid integer", value);
            }
        }
    } while(!okay);
}

