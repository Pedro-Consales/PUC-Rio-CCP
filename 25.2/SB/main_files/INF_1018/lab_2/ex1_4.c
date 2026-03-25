  #include <ctype.h>
  #include <stdio.h>

  int string2num (char *s, int base) {//Passa uma cadeia de caracteres que é um ponteiro
    int a = 0; //Inicializa como zero

    for (; *s; s++)
    {
      int d;//Declaro d
      if(*s >= 'a' && *s <= 'z')//Se o caractere é uma letra 
      {
        d = (*s - 'a');//Usa o critério de achar o número dessa forma (Coidigo ASCII do atual - o menor ASCII do grupo de números)
      }
      else if(*s >= '0' && *s <= '9')//Se o caractere é da "família dos números"
      {
        d = (*s - '0');//Usa o critério de achar o número por (Código ASCII do atual - o menor ASCII Atual)
      }
        a = a * base + d;//Multiplica pela base com a inciando como zero e soma d que é o valor do número em inteiro
    }

    return a;//A cada interação do for, o ponteiro anda uma casa. 
  }

  int main (void) {
      printf("%d\n", string2num("1101", 2));//Imprime o número binário em decimal por conta do %d
      printf("%d\n", string2num("1a", 16));
      printf("%d\n", string2num("a09b", 16));
      printf("%d\n", string2num("z09b", 36));
    return 0;
  }

  