/*
int fat (int n) {
  if (n == 0){
    return 1;
  } 
  else{
    int temp;
    temp = n;
    temp--;
    result = fat(temp);
    result = result * n;
    return result;
  }
}
*/


/*
rip -> Ponteiro para a próxima instrução
rsp -> Ponteiro para o topo da pilha
rbp -> Ponteiro para a base da pilha
*/


/*
Dicionário
Reg     Var
%edi      n


*/


.text
.globl fat

fat:

    pushq %rbp #Aumenta espaço para a pilha salvando o RA
    movq %rsp, %rbp #O topo da pilha aponta para a base
    subq $16, %rsp #subo com o ponteiro da topo da pilha 16 bytes para gerar espaço


    cmpl $0, %edi
    jne ELSE

    movl $1, %eax
    jmp END
    
ELSE:
    movl %edi, -4(%rbp) # Salvo o valor de %edi na pilha que eu criei. Subo 4 unidades em rbp para alocar ele
    decl %edi # edi = edi - 1
    call fat
    movl -4(%rbp), %edi #Aqui eu falo, vai no 4 bytes acima da base da pilha e pega o edi que eu guardei e bota em edi denovo
    imull %edi, %eax #Faço edi * o valor de retorno por fat, que é o n-1...

END:
    leave
    ret
