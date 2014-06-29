#include <stdio.h>

const int NUM = 6;

void func(int n)
{
    static int k = 0;
    k++;

    printf("%d\n", n);
    if (n != 0)
        func(n - 1);
    printf("%d\n", n);
    if (n == NUM)
        printf("k: %d\n", k);
}

int main()
{
    func(NUM);
}
