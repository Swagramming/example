#include <alloca.h> /* void *alloca(size_t size); */
#include <stdio.h>
#include <limits.h>

void test_vla()
{
    int n, max = INT_MIN, min = INT_MAX;
    scanf("%d", &n);
    int array[n];
    for (int i = 0; i < n; ++i)
    {
        scanf("%d", &array[i]);
        if (array[i] > max)
            max = array[i];
        if (array[i] < min)
            min = array[i];
    }
    printf("max: %d min: %d\n", max, min);
}

void test_alloca()
{
    int n, max = INT_MIN, min = INT_MAX;
    scanf("%d", &n);
    int* array = alloca(n);
    for (int i = 0; i < n; ++i)
    {
        scanf("%d", &array[i]);
        if (array[i] > max)
            max = array[i];
        if (array[i] < min)
            min = array[i];
    }
    printf("max: %d min: %d\n", max, min);
}

int main()
{
    test_vla();
    test_alloca();
}
