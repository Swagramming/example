#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef enum
{
    CHAR,
    INT,
    FLOAT,
    DOUBLE,
    STRING
} type_t;

typedef union
{
    char c;
    int i;
    float f;
    double d;
    char* s;
} any_t;

typedef struct
{
    any_t any;
    type_t tag;
} var_t;

var_t make_float(float f)
{
    var_t var;
    var.any.f = f;
    var.tag = FLOAT;
    return var;
}

var_t make_string(const char* s)
{
    var_t var;
    var.any.s = malloc(strlen(s) + 1);
    strcpy(var.any.s, s);
    var.tag = STRING;
    return var;
}

void free_var(var_t var)
{
    if (var.tag == STRING)
        free(var.any.s);
}

void print(var_t var)
{
    switch (var.tag)
    {
        case FLOAT: printf("%f", var.any.f); break;
        case STRING: printf("%s", var.any.s); break;
        /* ... */
        default: break;
    }
    putchar('\n');
}

int main()
{
    var_t var1 = make_float(3.5f);
    var_t var2 = make_string("derp");
    print(var1);
    print(var2);
    free_var(var1);
    free_var(var2);
}
