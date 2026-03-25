/*

int f(int x);

void map2 (int* um, int * outro, int n) {
  int i;
  for (i=0; i<n; i++)
    *(outro+i) = f(*(um+i));
}

*/



.text
.globl map2
map2:
    # Configuração inicial do stack frame
    pushq %rbp 
    movq %rsp, %rbp
    subq $32, %rsp
    movq %r12, -8(%rbp)    # Salva r12 (usarei como contador)

    movl $0, %r12d         # Inicializa contador i = 0

INICIO_LOOP:
    cmpl %edx, %r12d       # Verifica se i < n
    jge ENCERRA_FUNCAO     # Se i >= n, sai do loop

    # Cálculo do endereço outro[i]
    movslq %r12d, %r13     # Converte i para 64 bits
    shlq $2, %r13          # Multiplica por 4 (tamanho do int)
    addq %rsi, %r13        # r13 = &outro[i]

    # Cálculo do endereço um[i]  
    movslq %r12d, %r14     # Converte i para 64 bits
    shlq $2, %r14          # Multiplica por 4
    addq %rdi, %r14        # r14 = &um[i]

    # Preserva registradores antes da chamada de função
    movq %rdi, -16(%rbp)   # Salva primeiro parâmetro
    movq %rsi, -24(%rbp)   # Salva segundo parâmetro
    movl %edx, -28(%rbp)   # Salva terceiro parâmetro
    
    # Prepara chamada para f(um[i])
    movl (%r14), %edi      # Carrega um[i] como argumento
    call f                 # Chama função f

    # Restaura registradores após chamada
    movq -16(%rbp), %rdi
    movq -24(%rbp), %rsi
    movl -28(%rbp), %edx

    # Armazena resultado em outro[i]
    movl %eax, (%r13)      # outro[i] = f(um[i])
    
    incl %r12d             # Incrementa contador
    jmp INICIO_LOOP        # Volta para próxima iteração

ENCERRA_FUNCAO:
    # Restaura registrador salvo e finaliza
    movq -8(%rbp), %r12
    leave
    ret