#include <cstdio>

void swap(int* a, int* b)
{
    int c = *a;
    *a = *b;
    *b = c;
}

void insertion_sort(int* array, int size)
{
    for (int i = 0; i < size; ++i)
    {
        int j = i;
        while (j > 0 && array[j - 1] > array[j])
        {
            swap(array + j, array + j - 1);
            j -= 1;
        }
    }
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
    insertion_sort(array, size);
    print(array, size);
}
