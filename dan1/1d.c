#include <stdio.h>

int main()
{
    int a, b;
    scanf("%d%d", &a, &b);

    if (a < b)
        while (++a < b)
            printf("%d\n", a);
    else if (a > b)
        while (--a > b)
            printf("%d\n", a);
    else
        puts("a == b");
}
