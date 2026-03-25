  #include <ctype.h>
  #include <stdio.h>

  int string2num (char *s) {//Passa uma cadeia de caracteres que é um ponteiro
    int a = 0; //Inicializa como zero
    for (; *s; s++)//Percorre a cadeiad e caracteres
      a = a*10 + (*s - '0');// 0 = 0*10 + (*s(ponteiro para o início da cadeia "Ponteiro para o primeiro elemento") - '0' (Núemro ASCII do zero))
    return a;//A cada interação do for, o ponteiro anda uma casa. 
  }

  int main (void) {
    printf("==> %d\n", string2num("1234"));//Chama e printa a função
    printf("==> %d\n", string2num("1234") + 1);
    printf("==> %d\n", string2num("1234") + string2num("1"));
    return 0;
  }