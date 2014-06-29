#include <stdlib.h> /* void* calloc(size_t nmemb, size_t size); */
#include <string.h>

static void* _calloc(size_t size)
{
    return calloc(sizeof(int), size);
}

static void* _malloc(size_t size)
{
    return malloc(sizeof(int) * size);
}

static int** arrayalloc(size_t width, size_t height, void*(*alloc)(size_t))
{
    int i;
    /* Inicijaliziraj pokazivače na NULL! */
    int** array = calloc(height, sizeof(int*));
    if (array == NULL)
        return NULL;

    for (i = 0; i < height; ++i)
    {
        array[i] = alloc(width);
        if (array[i] == NULL)
            goto error;
    }
    return array;

error:
    for (i = 0; i < height; ++i)
        free(array[i]);
    free(array);
    return NULL;
}

void arraycpy(int** dest, int** src, size_t width, size_t height)
{
    int i;
    for (i = 0; i < height; ++i)
        memcpy(dest[i], src[i], width * sizeof(int));
}

int** arraycalloc(size_t width, size_t height)
{
    return arrayalloc(width, height, _calloc);
}

int** arraymalloc(size_t width, size_t height)
{
    return arrayalloc(width, height, _malloc);
}

void arrayfree(int** array, size_t height)
{
    int i;
    if (array == NULL)
        return;

    for (i = 0; i < height; ++i)
        free(array[i]);
    free(array);
}
