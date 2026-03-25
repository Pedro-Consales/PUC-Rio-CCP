  #include <ctype.h>
  #include <stdio.h>

  int string2num (char *s, int base) {//Passa uma cadeia de caracteres que é um ponteiro
    int a = 0; //Inicializa como zero

    for (; *s; s++)
    {
        int d = (*s - '0');

        a = a * base + d;
    }

    return a;//A cada interação do for, o ponteiro anda uma casa. 
  }

  int main (void) {
      printf("%d\n", string2num("1101", 2));
      printf("%d\n", string2num("777", 8));
      printf("%d\n", string2num("777", 10));
    return 0;
  }

  