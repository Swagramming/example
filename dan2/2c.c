#include <stdio.h>
#include <assert.h>

#define IME "Mislav"
#define BROJ 123
#define MAX(X, Y) ((X) > (Y) ? (X) : (Y))
#define NUMBERS 0, \
                1, \
                2
#define func(a, b) div(a, b)

#ifdef BROJ
    #undef BROJ
    #define BROJ 321
#endif

#define eprintf(...) fprintf(stderr, __VA_ARGS__)

#define WARN_IF(EXP) \
do { if (EXP) \
        eprintf("Warning: " #EXP " at %s line %d\n", __FILE__, __LINE__); } \
while (0)

#define ASSERT(MSG, EXP) assert(MSG && EXP)

void quit_command();
void help_command();

#define COMMAND(NAME) { #NAME, NAME ## _command }
struct command
{
    char *name;
    void (*function) (void);
};
struct command commands[] =
{
    COMMAND(quit), /* { "quit", quit_command }, */
    COMMAND(help) /* { "help", help_command } */
};

int div(int a, int b)
{
    WARN_IF(b == 1);
    ASSERT("cannot divide by zero", b != 0);
    return a / b;
}

int main()
{
    int arr[] = { NUMBERS };
    func(9, 1);
    commands[arr[0]].function();
}

void quit_command()
{
    puts(commands[0].name);
}

void help_command()
{
    puts(commands[1].name);
}
