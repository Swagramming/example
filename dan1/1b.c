/* Deklaracije funkcija <stdio.h> */
int scanf(const char* format, ...);
int printf(const char* format, ...);

/* Definicije funkcija */
int sum(int a, int b)
{
    return a + b;
}

int sub(int a, int b)
{
    return a - b;
}

int mul(int a, int b)
{
    return a * b;
}

int div(int a, int b)
{
    return b == 0 ? 0 : a / b;
}

float fdiv(int a, int b)
{
    return b == 0 ? 0 : (float)a / (float)b;
}

/* Deklaracija mod*/
int mod(int a, int b);

int main()
{
    /* Lokalne varijable */
    int a, b;
    scanf("%d%d", &a, &b);
    printf("zbroj: %d\nrazlika: %d\numnozak: %d\nkolicnik: %d\nostatak: %d\n", sum(a, b), sub(a, b), mul(a, b), div(a, b), mod(a, b));
    printf("%f\n", fdiv(a, b));
}

/* Definicija mod */
int mod(int a, int b)
{
    return b == 0 ? 0 : a % b;
}
