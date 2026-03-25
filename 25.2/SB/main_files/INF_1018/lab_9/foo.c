#include <stdio.h>


void foo(int a[], int n);

int main(void)
{
    int n = 3;
    int a[3] = {1,0,3};
    foo(a, n);
    for(int i = 0; i < n; i++)
    {
        printf("N%d: %d ", i, a[i]);
    }
    return 0;
}