#include <stdio.h>
#include <ctype.h>

int (*func[])(int) =
{
    isalnum, isalpha, isblank, iscntrl, isdigit, islower,
    isupper, isgraph, isprint, ispunct, isspace, isxdigit,
};

int main()
{
    for (unsigned char y = 0; y < 16; ++y)
    {
        for (unsigned char x = y * 16; x < y * 16 + 16; ++x)
        {
            int num_space = printf("%d: ", (int)x);
            printf("%.*s ", 5 - num_space, "       ");
            for (int i = 0; i < 12; ++i)
                putchar('0' + (func[i](x) == 0 ? 0 : 1));
            putchar(' ');
            if (x == 0xFF) break;
        }
        putchar('\n');
    }
}
