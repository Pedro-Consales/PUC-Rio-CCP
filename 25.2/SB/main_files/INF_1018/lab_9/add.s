/*

int add (int a, int b, int c) {
  return a+b+c;
}

*/


 .data

  .text
  .globl add
  
    add:
        # Soma diretamente usando os registradores de parâmetros
        movl %edi, %eax
        addl %esi, %eax
        addl %edx, %eax
        ret                # Retorna com resultado em %eax
