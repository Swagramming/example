#include <climits>
#include <cstdio>

void swap(int* a, int* b)
{
    int c = *a;
    *a = *b;
    *b = c;
}

int min_index(int* array, int size)
{
    int min = 0;
    for (int i = 1; i < size; ++i)
        if (array[i] < array[min])
            min = i;
    return min;
}

void selection_sort(int* array, int size)
{
    for (int i = 0; i < size - 1; ++i)
    {
        int min = min_index(array + i, size - i) + i;
        swap(array + i, array + min);
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
    selection_sort(array, size);
    print(array, size);
}
