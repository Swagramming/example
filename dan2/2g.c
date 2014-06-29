#include <math.h>
#include <stdio.h>

#define PI 3.14159265358979323846
#define E 2.71828182846

void trig()
{
    double a = sin(PI / 2), b = cos(PI), c = tan(1);
    double d = asin(a), e = acos(b), f = atan(c);
    printf("%f %f %f\n%f %f %f\n\n", a, b, c, d, e, f);
}

void log_exp()
{
    double a = log2(0x1000), b = log(E), c = pow(5, 2);
    double d = exp2(a), e = exp(b), f = sqrt(c);
    printf("%f %f %f\n%f %f %f\n\n", a, b, c, d, e, f);
}

void mod_round()
{
    double intpart;
    double a = modf(PI, &intpart), b = fmod(PI, 3), c = ceil(PI);
    double d = floor(-PI), e = trunc(-PI), f = round(PI);
    printf("%f %f %f\n%f %f %f\n\n", a, b, c, d, e, f);
}

void min_max()
{
    double a = fmin(PI, E), b = fmax(PI, E), c = fabs(-PI);
    printf("%f %f %f\n", a, b, c);
}

int main()
{
    trig();
    log_exp();
    mod_round();
    min_max();
}
