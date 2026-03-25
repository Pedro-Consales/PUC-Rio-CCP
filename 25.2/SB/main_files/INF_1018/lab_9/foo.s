/*
void foo (int a[], int n) {
  int i = 0;
  int s = 0;
  while(i<n){
    //s += a[i];
    //Aqui eu preciso fazer a aritimética de index
    int temp = a[i];
    s = s + a[i];
    if (a[i] == 0) {
      a[i] = s;
      s = 0;
    }
    i++;
  }
}
*/

/*
Dicionário
Reg       Var
%r10d     i
%r11d     s
%esi      n
%rdi      a
%r15d     4(seizeof) CS -> 4 bytes
r12.      temp de a[] CS -> 8 bytes
rbx       salvo o endereço da posição do vetor CS -> 8 bytes


*/


.text
.globl foo

foo:
    pushq %rbp
    movq %rsp, %rbp
    subq $32, %rsp   #Vou abrir tamanho para o RA
    

    #Salvo os que eu tenho que salvar no RA (salvo todos os calee-ssved)
    #Aqui 
    movq %rbx, -8(%rbp)
    movq %r12, -16(%rbp)
    movl %r15d, -20(%rbp) 

    #Registro os valores de i e s
    movl $0, %r10d
    movl $0, %r11d

    while:
          cmpl %esi, %r10d
          jge FORA_WHILE


          # a[i] = end(a[0]) + i * seizeof(int)
          movl $4, %r15d      # r12d = 4 -> Faço isso para ter onde guardar a multiplicação, ou eu tenho que obrigatóriamente fazer um temp para i
          imull %r10d, %r15d # rbx = rbx * i -> agora eu tenho a quantidade em tamanho de ponteiro pois vou andar em endereço
          movslq %r15d, %rbx # extendo pois é um ponteiro endereço
          movq %rdi, %r12    # guardo o endereço incial em r12
          addq %rbx, %r12   # Ando o endereço a quantidae de vezes do i*seizeof
          addl (%r12), %r11d # addiciona o conteúdo

          cmpl $0, (%r12)
          jne Ai_DifZero

          movl %r11d, (%r12)
          movl $0, %r11d


          Ai_DifZero:


          incl %r10d
          jmp while




    FORA_WHILE:
    leave 
    ret
