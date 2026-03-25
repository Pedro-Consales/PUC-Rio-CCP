/* 

3. (5,0 pontos) Traduza as fun¸c˜oes corta e buba abaixo para assembly IA-64 (o assembly visto
em sala), utilizando as regras usuais de alinhamento, passagem de parˆametros, salvamento de
registradores e resultados em C/linux. Traduza o mais diretamente poss´ıvel o c´odigo de C para
assembly.
Comente seu c´odigo!

(a) (1,5 pontos)
int corta(char c1, int b)
{
    temp = c1
    temp = temp + b;
    return temp;
    //return c1 + b;
}
(b) (3,5 pontos)
int buba(char *v, int n, char c)
{
    int i = 0;
    int s = 0;
    //for (i; i<n; i++)
    while(i<n)
    {
        char char_vetor = v[i];
        if (char_vetor <= c)
        {
            int cut = corta(char_vetor, n)
            soma = soma + cut
        }
        i++;
    }
    return s;
}

*/





.text
.globl buba:





buba:
    pushq %rbp
    movq %rsp, %rbp
    subq $32, %rsp

    /*Aqui devo ver quais registradores callee-saved eu usei*/
    movq %r12d, -8(%rbp) 
    movq %r13d, -16(%rbp)
    movq %ebx, -24(%rbp)
    movq %rbx, -32(%rbp)
    movq %r14d, -40(%rbp)



    movl $0, %r12d /*i=0*/ 
    movl $0, %r13d /*s = 0*/ 

    WHILE:
        cmpq %r12d, %esi
        jge FORA_WHILE

        movslq %r12d, %rbx     # Estende i para 64 bits
        addq %rdi, %rbx        # rbx = v + i
        movsbl (%rbx), %r14d   # r14d = v[i] (char estendido para int)

        cmpb %dl, %r14d 
        jg FORA_IF

        movb %r14d, %dil /**/
        call corta /* */

        addl %eax, %r13d



        FORA_IF:
        incl %r12d




        FORA_WHILE:
                movq -8(%rbp), %r12    # Restaura r12
                movq -16(%rbp), %r13   # Restaura r13
                movq -24(%rbp), %rbx   # Restaura rbx
                movq -32(%rbp), %r14   # Restaura r14

                movl %r13d, %eax
                leave
                ret





corta:
    movsbl %dil, %r10d /*temp = c1 possível pronelma assim como anteriormente*/
    addl %esi, %r10d
    movl %r10d, %eax
    ret
