
    /*

    int acerta (int u[], int i)
    {

        temp1 = &u[i];
        
        temp2 = *temp1;

        return temp2;
    }


    struct S
    {
        int v;
        struct S *prox;
    };
    0-3     | v        | 4 bytes | int
    4-7     | padding  | 4 bytes | padding para alinhar prox
    8-15    | prox     | 8 bytes | ponteiro (64 bits)



    extern int norma[];

    int boo(struct S *s, int n)
    {
        //int acum = 0;
        int acum;
        acum = 0;
        while (s != 0) //Como faz esse while "True" em assembly?
        {

            v_address = s->v
            n_acum = n+acum
            *v_address = acerta(norma, n_acum);
            acum += n;
            s = s->prox;
        }
        return acum;
    }


    */


    /*
    Dicionário:

    Reg     Var
    ebx      acum - callesaved 4
    rdi      struct S 16
    r12d     n_acum - callesaved 4
    r15      struct S (temp) 16
            
            24 bytes





    */



    .text
    .globl boo
    .globl acerta

    boo:
        pushq %rbp
        movq %rsp, %rbp
        subq $32, %rsp /*Alocar espaço para o RA*/



        # Salvando registradores callee-saved:
        movq %r15, -8(%rbp)     # Slot 1: 8 bytes
        movq %rbx, -16(%rbp)    # Slot 2: 8 bytes
        movq %r12, -24(%rbp)    # Slot 3: 8 bytes
        
        # Salvando n (int de 4 bytes):
        movl %esi, -32(%rbp)    # Slot 4: usa 4 bytes, mas RESERVA 8!



        movl $0, %ebx /*acum = 0*/

        loop:
            movq %rdi, %r15 /*Faço isso pois posteriormente eu mudo o rdi para ser o primeiro parâmetro da função acerta*/
            cmpq $0, %rdi
            je fora_loop

            movl %esi, %r12d /* n_acum = n */
            addl %ebx, %r12d /* n_acum = n_acum + acum*/


            movq $norma, %rdi
            movl %r12d, %esi
            call acerta

            movq %r15, %rdi /*Como rdi mudou para ser passado como parâmetro, eu volto pra quem ele era e restauro*/ /* Tipo um s = 5, temp = s, s = 10 (uso o s sendo 10) e deposis falo que s = temp que era o 5 de antes */

            movl %eax, (%rdi)

            movl -32(%rbp), %esi
            addl %esi, %ebx /**/
            movq 8(%r15), %r15 /*Vai para o próximo campo, o offset*/
            movq %r15, %rdi



        jmp loop


    fora_loop:

        movq -8(%rbp), %r15     # Slot 1: 8 bytes
        movq -16(%rbp), %rbx     # Slot 2: 8 bytes
        movq -24(%rbp), %r12    # Slot 3: 8 bytes
        movl %ebx, %eax

        leave
        ret


    /*
    Dicionário
    Reg     Var


    */


    acerta: 
        pushq %rbp
        movq %rsp, %rbp
        subq $8, %rsp

        movq %rbx, -8(%rbp)


        movl $4, %r10d /* r10d = 4*/
        imull %esi, %r10d /* r10d = r10d * esi -> 4 = 4 * i */
        movslq %r10d, %rbx /*Aumento para 64 bits porque é o endereço que eu vou somar ao endereço inicial do vetor*/
        addq %rdi, %rbx /*Adiciono quantos bytes eu preciso andar ao endereço inicial*/
        movl (%rbx), %eax

        movq -8(%rbp), %rbx  /*✅ Restaura rbx*/
        leave                 /*✅ Desfaz o stack frame*/
        ret
