#include <stdio.h>
#include <stdarg.h>

void print_lines(char* first, ...)
{
    va_list vl;
    char* str = first;
    va_start(vl, first);
    do
    {
        puts(str);
        str = va_arg(vl, char*);
    } while (str != NULL);
    va_end(vl);
}

int main()
{
    print_lines("Jen", "Dva", "Tri", "Cetri", NULL);
}
