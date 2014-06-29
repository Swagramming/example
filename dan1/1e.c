#include <stdio.h>

struct test
{
    int a;
};

typedef unsigned char byte;
struct entry
{
    byte u8_1;
    byte u8_2;
    short unsigned int u16_1;
    int i32_1;
    long int i64_1;
} objekt;
typedef struct entry entry_t;

typedef struct
{
    int a; /* 4 bajta */
    byte b; /* 1 bajt */
    /* 3 bajta alignment */
}entry2_t;

int main()
{
    struct test to;
    entry_t eo;
    entry2_t e2o;
    to.a = 5;
    eo.u8_1 = 6;
    objekt.i32_1 = 7;
    e2o.a = 8;
    printf("%lu, %lu, %lu", sizeof(struct test), sizeof(entry_t), sizeof(entry2_t));
    /* slience compiler warning */
    (void)e2o;
    (void)eo;
    (void)to;
    return 0;
}
