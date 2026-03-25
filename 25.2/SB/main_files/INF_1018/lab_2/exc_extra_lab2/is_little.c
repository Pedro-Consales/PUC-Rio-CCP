#include <stdio.h>

void dump(void *p, int n);
int is_little();

int main(void)
{
    int i = 100;
    dump(&i,sizeof(i));
    if(is_little())
    {
        printf("Arquitetura: Little-endian\n");
    } else {
        printf("Arquitetura: Big-endian\n");
    }
    return 0;
}

void dump (void *p, int n) {

    //Iniciar um vetor de ponteiros que aponta para cada endereço

    unsigned char *p1 = p; 

    while (n--) {
        
        //Direcionar quem aponta para o tal endereço

        printf("%p - %02x\n", p1, *p1);
        
        //Anda uma casa do vetor
        p1++;
    }

    
}

int is_little()
{
    int x = 1;
    unsigned char *p = (unsigned char*) &x;

    if(*p == 1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

