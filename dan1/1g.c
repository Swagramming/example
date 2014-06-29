#include <stdio.h>

/* <stdlib.h> */
void *malloc(size_t size);
void *realloc(void *ptr, size_t size);
void free(void *ptr);

void swap(int* a, int* b)
{
    int c = *a;
    *a = *b;
    *b = c;
}

int main()
{
    int a = 3, b = 4, i, n, sum = 0, max = 0, *ptr, *ptr2;
    swap(&a, &b);
    printf("%d, %d\n", a, b);

    scanf("%d", &n);
    ptr = malloc(n * sizeof(int));
    if (ptr == NULL)
    {
        printf("Nemoguce alocirati %d bajta memorije!", n);
        return 1;
    }
    for (i = 0; i < n; ++i)
        scanf("%d", ptr + i);
    for (i = 0; i < n; ++i)
        sum += *(ptr + i);
    printf("sum: %d\n", sum);

    ptr2 = ptr + n - 1;
    printf("last: %d\n", *ptr2);

    scanf("%d", &n);
    /* realloc(NULL, n) == malloc(n); */
    ptr = realloc(ptr, n * sizeof(int));
    if (ptr == NULL)
    {
        printf("Nemoguce alocirati %d bajta memorije!", n);
        return 1;
    }
    for (i = 0; i < n; ++i)
        scanf("%d", ptr + i);
    for (i = 0; i < n; ++i)
        if (ptr[i] > max)
            max = ptr[i];
    printf("max: %d\n", max);
    free(ptr);
}
