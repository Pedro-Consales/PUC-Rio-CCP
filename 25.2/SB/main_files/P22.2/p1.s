/*
 (5,0 pontos) Traduza a fun¸c˜ao foo abaixo para assembly IA-64 (o assembly visto em sala),
utilizando as regras usuais de alinhamento, passagem de parˆametros, salvamento de registradores
e resultados em C/linux. Traduza o mais diretamente poss´ıvel o c´odigo de C para assembly.
Comente seu c´odigo!

(a) 

int gera(char c1, char c2);

int foo(int n, char c, char *v)
{
    int i = 0;
    int s = 0;
    //for (i=0; i<n; i++)
    while(i<n)
    {
        elemento = v[i] é o conteúdo do vetor na posição i 
        e um vetor de char
        if (elemento >= c)
        {

            retorno = gera(elemento, c)

            s = s + retorno
        }
        i++;
    }
    return s;
}

*/



.text
.globl foo

/*
Dicionário

Reg     Var
r12d    i / CS
r13d    s / CS
ebx     sizeof(char) = 1 / CS
r10     &v[i] 
r14b    *v[i] - char /CS
sil     char c - parâmetros 
r11b    char c - cópia do parâmetro


*/


foo:

    pushq %rbp
    movq %rsp, %rbp
    subq $32, %rsp

    movq %r12, -8(%rbp)
    movq %r13, -16(%rbp)
    movq %rbx, -24(%rbp)
    movq %r14, -32(%rbp)




    movl $0, %r12d /*i = 0*/
    movl $0, %r13d /*s = 0*/

    loop:
        cmpl %edi, %r12d
        jge fora_loop

        /*Calculando o index*/
        movl $1, %ebx /* ebx = 1*/
        imull %r12d, %ebx /* ebx = ebx * i */
        movslq %ebx, %r10 /*Aumento o para 64 bits pois estamos falando de endereço*/
        addq %rdx, %r10 /*Pego o endereço do vetor e somo ao endereço que eu tenho para adicionar*/ 
        movb (%r10), %r14b /*Pega o conteúdo de onde r10 aponta*/

        if:
            movb %sil, %r11b
            cmpb %r11b, %r14b


            jnge fora_if

            /*Devo preparar as variáveis para passar de parâmetro*/
            movb %r14b, %dil
            movb %r11b, %sil
            call gera /*chmao a função*/

            movb %r11b, %sil /*Restauro a o valor*/
            addl %eax, %r13d

        fora_if:
                incl %r12d
                jmp loop



    fora_loop:
            movq -8(%rbp), %r12 
            movq -16(%rbp), %r13 
            movq -24(%rbp), %rbx
            movq -32(%rbp), %r14


            movl %r13d, %eax
            leave 
            ret
