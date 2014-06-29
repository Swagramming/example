#include <cstdio>

void swap(int* a, int* b)
{
    int c = *a;
    *a = *b;
    *b = c;
}

void bubble_sort(int* array, int size)
{
    bool Changed;
    do
    {
        Changed = false;
        for (int i = 0; i < size; ++i)
        {
            if (array[i] > array[i + 1])
            {
                swap(array + i, array + i + 1);
                Changed = true;
            }
        }
    } while (Changed);
}

void print(int* array, int size)
{
    for (int i = 0; i < size; ++i)
        std::printf("%d ", array[i]);
    std::putchar('\n');
}

int main()
{
    int array[] = { 3, 8, 2, 4, 1 };
    int size = sizeof(array) / sizeof(int);
    bubble_sort(array, size);
    print(array, size);
}
