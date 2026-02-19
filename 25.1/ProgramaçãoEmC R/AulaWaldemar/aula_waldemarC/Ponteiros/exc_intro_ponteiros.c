#include <stdio.h>

// declara três variáveis locais: inteiro x, inteiro y e um ponteiro p para inteiro.
// atribui o valor 5 à variável x diretamente.
// guarda o endereço da variável y em p.
// atribui o valor 2 para a variável y usando o ponteiro p.
// imprime os endereços de x, y, e de p em hexadecimal e decimal. Por exemplo, o endereço da variável y é impresso como: 0078FDB0 (7929264).
// imprime os conteúdos das variáveis x, y e p. Note que ponteiros guardam endereços!
// imprime o conteúdo de y através do ponteiro p.
// muda o valor de p somando 1 (i.e., p = p +1)
// imprime o novo endereço colocado em p, em hexadecimal e decimal.



int main(void) 
{

    int x = 5;
    int y;
    int *p;

    p = &y;

    *p = 2;

    

    printf("Endereco de p em hexadecimal: %p / Endereco de p em decimal: %d\n", &p, &p); // Nesse caso o endereço do ponteiro é o mesmo que o endereço da variável y, isso está correto?: Sim ou Não?: Sim Então porque?: Porque o ponteiro p está apontando para o endereço de y. Mas o ponteiro p não tem seu proprio endereço de memória?: Sim, o ponteiro p tem seu próprio endereço de memória, mas o que está sendo impresso é o endereço de memória para o qual o ponteiro p está apontando. E o que eu devo fazer para imprimir o endereço de memória do ponteiro p?: Para imprimir o endereço de memória do ponteiro p, basta usar o operador & antes do ponteiro p. Exemplo: &p
    printf("Endereco de x em hexadecimal: %p / Endereco de x em decimal: %d\n", &x, &x);
    printf("Endereco de y em hexadecimal: %p / Endereco de y em decimal: %d\n", &y, &y);
    printf("Endereco de y atraves de p em decimal: %d\n\n", p);

    printf("Conteudo de x: %d / Conteudo de y: %d / Conteudo de p: %d \n", x, y, *p);
    printf("Conteudo de y atraves de p: %d\n", *p);

    p = p + 1;

    printf("Novo endereco de p em hexadecimal: %p / Novo endereco de p em decimal: %d\n", p, p);
    printf("Novo conteudo de y atraves de p: %d", *p);

    return 0;

}