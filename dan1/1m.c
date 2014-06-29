/* <stdio.h>
 * KORISTENE FUNKCIJE:
 * int fscanf(FILE *stream, const char *format, ...);
 * int fprintf(FILE *stream, const char *format, ...);
 * int fflush(FILE *stream);
 * 
 * NEKORISTENE FUNKCIJE:
 * int remove(const char *pathname);
 * int rename(const char *old, const char *new);
 * int sprintf(char *str, const char *format, ...);
 * int snprintf(char *str, size_t size, const char *format, ...);
 * */
#include <stdio.h>
#include <stdlib.h>

int write_file(const char* filename)
{
    int i = 1;

    FILE* file = fopen(filename, "w");
    if (file == NULL)
    {
        fprintf(stderr, "Failed to open file %s\n", filename);
        return EXIT_FAILURE;
    }

    while (1)
    {
        char strbuf[32];
        int integer;
        /* BUG: Moguci buffer overflow! */
        fscanf(stdin, "%s %d", strbuf, &integer);
        fprintf(file, "%s %d", strbuf, integer);
        if ((i++ % 3) == 0)
            fflush(file);
    }

    fclose(file);
    return EXIT_SUCCESS;
}

int main(int argc, char** argv)
{
    if (argc != 2)
    {
        fprintf(stdout, "usage: %s <filename>\n", argv[0]);
        return EXIT_FAILURE;
    }
    return write_file(argv[1]);
}
