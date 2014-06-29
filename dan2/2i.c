#include <stdlib.h>

void main2(int argc, char** argv)
{
    if (argc != 2)
        exit(EXIT_FAILURE);

    char* env = getenv(argv[1]);
    if (env == NULL)
        exit(EXIT_FAILURE);

    system(env);
}

void exit2()
{
    system("echo Bye Bye");
}

int main(int argc, char** argv)
{
    atexit(exit2);
    main2(argc, argv);
    system("echo Successful!");
    return EXIT_SUCCESS;
}
