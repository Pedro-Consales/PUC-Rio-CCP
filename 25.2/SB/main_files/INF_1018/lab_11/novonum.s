/*

int novonum(void) {
  int minhalocal;
  printf("numero: ");
  scanf("%d",&minhalocal);
  return minhalocal;
}

*/




.data
Pf1: .string "numero: \n"
Sf1: .string "%d"

.text
.globl novonum

novonum:
        pushq %rbp
        movq %rsp, %rbp
        subq $16, %rsp

        /*Devo preparar os parametro para o print*/
        movq $Pf1, %rdi
        call printf

        movq $Sf1, %rdi
        leaq -4(%rbp), %rsi /*Aqui eu vou pegar o enderço e gravar num registrados de 2o parâmetro*/
        call scanf

        movl -4(%rbp), %eax


        leave
        ret



        