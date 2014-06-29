/* Deklaracije funkcija <stdio.h> */
int putchar(int c);
int puts(const char* s);

/* Globalne varijable */
char c = ';';
const char* s = "What's up?";
int i = 4;

/* Definicija "main" funkcije */
int main()
{
    putchar(':');
    puts("Hello world!");
    putchar(c);
    puts(s);
    putchar('0' + i);
}
