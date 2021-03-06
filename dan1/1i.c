#include <stdio.h>

const char* const name[] = {"on", "off", "flip", "test"};
void (*func[4]) (int in);
int mask = 0;

int provjera(int in)
{
    if (in < 0 || in >= sizeof(int) * 8)
        return 0;
    return 1;
}

void on(int in)
{
    mask |= (1 << in);
}

void off(int in)
{
    mask &= ~(1 << in);
}

void flip(int in)
{
    mask ^= (1 << in);
}

void test(int in)
{
    putchar('0' + ((mask & (1 << in)) != 0));
    putchar('\n');
}

void init()
{
    func[0] = &on;
    func[1] = &off;
    func[2] = &flip;
    func[3] = &test;
}

void run()
{
    int i, in;
    for (i = 0; i < 4; ++i)
    {
        printf("%d\n%s:", mask, name[i]);
        do
        {
            scanf("%d", &in);
            if (provjera(in) == 1)
            {
                func[i](in);
                break;
            }
        } while (1);
    }
}

int main()
{
    init();
    run();
    return 0;
}
