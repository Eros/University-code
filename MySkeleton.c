#include <opencl-c.h>
#include <ctype.h>
#include <stdio.h>
#include <memory.h>

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

