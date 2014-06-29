#include <stdio.h>
#include <time.h> /* time_t time(time_t* t); */

/* <string.h> */
void* memset(void* s, int c, size_t n);
/* <stdlib.h> */
int rand(void);
void srand(unsigned int seed);

char map[16][16];
int x = 0, y = 0;
int zx, zy;

void init()
{
    memset(map, '.', 16 * 16 * sizeof(char));
    map[y][x] = 'M';
    srand(time(NULL));
    zx = rand() % 16;
    zy = rand() % 16;
    map[zy][zx] = 'Z';
}

void draw()
{
    int i, j;
    for (i = 0; i < 16; ++i)
    {
        for (j = 0; j < 16; ++j)
            putchar(map[i][j]);
        putchar('\n');
    }
}

void play()
{
    int input;
    while (x != zx || y != zy)
    {
        draw();
        scanf("%d", &input);
        map[y][x] = '.';
        switch (input)
        {
            case 2: if (y != 15) ++y; break;
            case 4: if (x != 0) --x; break;
            case 6: if (x != 15) ++x; break;
            case 8: if (y != 0) --y; break;
            default: puts("unesi 2, 4, 6 ili 8!"); break;
        }
        map[y][x] = 'M';
    }
}

int main()
{
    init();
    play();
}
