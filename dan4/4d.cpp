#include <cstdio>
#include <climits>

void merge(int* array, int low, int mid, int high)
{
    int an = mid - low + 1, bn = high - mid;
    int* a = new int[an + 1];
    int* b = new int[bn + 1];

    for (int i = 0; i < an; ++i)
        a[i] = array[low + i];
    for (int i = 0; i < bn; ++i)
        b[i] = array[mid + i + 1];

    a[an] = INT_MAX;
    b[bn] = INT_MAX;

    int i = 0, j = 0;
    for (int k = low; k <= high; ++k)
    {
        if (a[i] <= b[j])
            array[k] = a[i++];
        else array[k] = b[j++];
    }

    delete[] a;
    delete[] b;
}

void merge2(int* array, int low, int mid, int high)
{
    int size = high - low + 1;
    int* a = new int[size];
    int i = 0, j = 0;
    for (int k = 0; k < size; ++k)
    {
        if (low + i > mid)
            do a[k] = array[mid + 1 + j++]; while (++k < size);
        else if (mid + j + 1 > high)
            do a[k] = array[low + i++]; while (++k < size);
        else if (array[low + i] <= array[mid + j + 1])
            a[k] = array[low + i++];
        else a[k] = array[mid + 1 + j++];
    }
    for (int k = 0; k < size; ++k)
        array[low + k] = a[k];
    delete[] a;
}

void merge_sort(int* array, int low, int high)
{
    if (low >= high)
        return;

    int mid = (low + high) / 2;
    merge_sort(array, low, mid);
    merge_sort(array, mid + 1, high);

#if defined(MERGE2)
    merge2(array, low, mid, high);
#else
    merge(array, low, mid, high);
#endif
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
    merge_sort(array, 0, size - 1);
    print(array, size);
}
