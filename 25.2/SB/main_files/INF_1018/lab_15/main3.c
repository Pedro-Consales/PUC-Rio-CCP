#include <stdio.h>



double foo3 (double *a, int n);

int main(void)
{
    int n = 2;
    double a[2] = {(3.14159265358979323846f/2.0f),(3.14159265358979323846f/2.0f)};

    double resp = foo3(&a, n);

    printf("%f\n", resp);

    return 0;
}