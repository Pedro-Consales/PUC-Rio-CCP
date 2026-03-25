#include <stdio.h>


int main(void)
{
    char *s = '\0';

    num2string(s, 10, 2);

    printf("%s", s);
}


void num2string(char *s, int num, int base)
{
    int resto = num%base;

    char c1,c2;

    c1 = *s;
    c2 = (resto + '0');
    anda_para_direira(&s,c1);

    *s = c2;
}

void anda_para_direira(char *s, char c1)
{
    *(s+1) = c1;
}