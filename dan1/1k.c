#include <stdio.h>
#include <stdlib.h>

/* Deklaracije funkcija iz 1k2.c */
void arraycpy(int** dest, int** src, size_t width, size_t height);
int** arraycalloc(size_t width, size_t height);
int** arraymalloc(size_t width, size_t height);
void arrayfree(int** array, size_t height);

typedef struct
{
    size_t width;
    size_t height;
    int** array;
    int** save;
} game_t;

game_t* construct()
{
    game_t* game = malloc(sizeof(game_t));
    if (game == NULL)
        return NULL;

    scanf("%lu%lu", &game->width, &game->height);

    game->save = NULL;
    game->array = arraycalloc(game->width, game->height);
    if (game->array == NULL)
    {
        free(game);
        return NULL;
    }
    return game;
}

void destruct(game_t* game)
{
    if (game == NULL)
        return;

    arrayfree(game->save, game->height);
    arrayfree(game->array, game->height);
    free(game);
}

void draw(game_t* game)
{
    int y, x, num_space;
    for (y = 0; y < game->height; ++y)
    {
        for (x = 0; x < game->width; ++x)
        {
            num_space = printf("%d", game->array[y][x]);
            printf("%.*s ", 10 - num_space, "          ");
        }
        putchar('\n');
    }
}

void save(game_t* game)
{
    if (game->save == NULL)
        game->save = arraymalloc(game->width, game->height);
    if (game->save != NULL)
        arraycpy(game->save, game->array, game->width, game->height);
}

void load(game_t* game)
{
    if (game->save != NULL)
        arraycpy(game->array, game->save, game->width, game->height);
}

void menu(game_t* game)
{
    int input;
    do
    {
        puts("1) Input\n2) Save\n3) Load");
        scanf("%d", &input);
        switch (input)
        {
            case 2: save(game); break;
            case 3: load(game); draw(game); break;
        }
    } while (input != 1);
}

void play(game_t* game)
{
    int y, x, v;
    while (1)
    {
        draw(game);
        menu(game);
        do
        {
            scanf("%d%d%d", &x, &y, &v);
        } while (x > game->width || y > game->height || x < 1 || y < 1);
        game->array[y - 1][x - 1] = v;
    }
}

int main()
{
    game_t* game = construct();
    if (game != NULL)
        play(game);
    destruct(game);
}
