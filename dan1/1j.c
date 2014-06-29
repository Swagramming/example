/* <stdio.h>
 * FILE *fopen(const char *path, const char *mode);
 * int fseek(FILE *stream, long offset, int whence);
 * long ftell(FILE *stream);
 * void rewind(FILE *stream);
 * size_t fread(void *ptr, size_t size, size_t nmemb, FILE *stream);
 * size_t fwrite(const void *ptr, size_t size, size_t nmemb, FILE *stream);
 * int fclose(FILE *fp);
 * */
#include <stdio.h>
#include <stdlib.h>

char* read_file(const char* path, size_t* size)
{
    char* buffer = NULL;
    size_t size_read;
    FILE* file;

    file = fopen(path, "rb");
    if (file == NULL)
        return NULL;

    fseek(file, 0, SEEK_END);
    *size = ftell(file);
    rewind(file);

    buffer = malloc(*size);
    if (buffer == NULL)
        goto error;

    size_read = fread(buffer, 1, *size, file);
    if (size_read != *size)
        goto error;
    return buffer;

error:
    free(buffer);
    fclose(file);
    return NULL;
}

void append_file(const char* filename, char* buffer, size_t size)
{
    FILE* file = fopen(filename, "ab");
    fwrite(buffer, sizeof(char), size, file);
    fclose(file);
}

int concat_files(const char* filename, char** filenames)
{
    int i;
    size_t size;
    for (i = 0; filenames[i]; ++i)
    {
        char* buffer = read_file(filenames[i], &size);
        if (buffer == NULL)
            return EXIT_FAILURE;
        append_file(filename, buffer, size);
        free(buffer);
    }
    return EXIT_SUCCESS;
}

int main(int argc, char** argv)
{
    if (argc < 3)
    {
        /* argv[0] je naredba koristena za pokretanje programa */
        printf("usage: %s <dest> <srcs>\n", argv[0]);
        return EXIT_FAILURE;
    }
    return concat_files(argv[1], argv + 2);
}
