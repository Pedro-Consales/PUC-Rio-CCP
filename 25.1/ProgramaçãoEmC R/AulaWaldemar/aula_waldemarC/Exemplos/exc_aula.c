#include <stdio.h>

//Aula Waldemar

int main(void)
{

    int n1, n2, n3;

    printf("Digite 3 numeros: ");
    scanf("%d %d %d", &n1, &n2, &n3);

    if(n1>n2 && n1>n3)
    {
        printf("O maior numero eh: %d", n1);
    }
    else if(n2>n1 && n2>n3)
    {
        printf("O maior numero eh: %d", n2);
    }
    else
    {
        printf("O maior numero eh: %d", n3);
    }
    
    return 0;

}