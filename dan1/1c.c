#include <stdio.h>
#include <stdlib.h> /* EXIT_FAILURE, EXIT_SUCCESS */

int main(int argc, char** argv)
{
    int i;

    if (argc < 2)
    {
        /* argv[0] je naredba koristena za pokretanje programa */
        printf("usage: %s <args>\n", argv[0]);
        return EXIT_FAILURE;
    }

    /* Preskoci argv[0] */
    for (i = 1; i < argc; ++i)
        puts(argv[i]);
    return EXIT_SUCCESS;
}
