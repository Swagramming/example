#include <setjmp.h>
#include <stdio.h>

jmp_buf place;
int n = 5;

void func()
{
    longjmp(place, n--);
    puts("WTF");
}

int main()
{
    int ret = setjmp(place); /* first call returns 0 */
    printf("%d\n", ret);
    if (ret == 1)
        return 0;

    func(n); /* never returns */
    puts("WTF");
}
