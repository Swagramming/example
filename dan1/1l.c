/* <string.h>
 * KORISTENE FUNKCIJE:
 * size_t strlen(const char *s);
 * char *strcpy(char *dest, const char *src);
 * char *strncpy(char *dest, const char *src, size_t n);
 * char *strcat(char *dest, const char *src);
 * int strcmp(const char *s1, const char *s2);
 * char *strchr(const char *s, int c);
 * char *strstr(const char *haystack, const char *needle);
 * char *strtok(char *str, const char *delim);
 * void *memchr(const void *s, int c, size_t n);
 * void *memmove(void *dest, const void *src, size_t n);
 * 
 * NEKORISTENE FUNKCIJE:
 * int strncmp(const char *s1, const char *s2, size_t n);
 * char *strncat(char *dest, const char *src, size_t n);
 * */
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

const char* s1 = "herp.";
const char* s2 = "derp";

int main()
{
    size_t s3_size = strlen(s1) + strlen(s2);
    char* s3 = malloc(s3_size + 1), *pch; /* +1 za NULL terminator */

    strcpy(s3, s1); /* dodaje '\0' */
    puts(s3);

    strcat(s3, s2); /* dodaje '\0' */
    if (strcmp(s3, "herp.derp") == 0)
        puts(s3);

    pch = strchr(s3, 'p');
    while (pch != NULL)
    {
        *pch = 't';
        pch = strchr(pch + 1, 'p');
    }
    puts(s3);

    pch = strstr(s3, "t.d");
    strncpy(pch, "p.h", 3);
    puts(s3);

    pch = strtok(s3, ".");
    while (pch != NULL)
    {
        puts(pch);
        pch = strtok(NULL, ".");
    }
    puts(s3);

    pch = memchr(s3, '\0', s3_size);
    *pch = '.';
    puts(s3);

    /* Ne radi s memcpy! */
    memmove(s3 + 2, s3, strlen(s3) - 2);
    puts(s3);

    memset(s3, 'Q', s3_size);
    puts(s3);

    free(s3);
}
