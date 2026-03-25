#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

typedef unsigned packed_t;

/* extrai byte indicado e retorna valor inteiro correspondente (32 bits) com sinal */
// int xbyte (packed_t word, int bytenum)
// {
//     packed_t buff = word;

//     buff >>= (bytenum*8);

//     buff = buff & 0x000000FF;
    
//     return (signed char) buff;
// }

int string2num (char *s, int base) {
  int a = 0;
  for (; *s; s++) {
    if(isdigit(*s))
      a = a*base + (*s - '0');
    else if((*s >= 'A') && (*s < (base-10+'A')))
      a = a*base + ((*s - 'A') + 10);
    else if((*s >= 'a') && (*s < (base-10+'a')))
      a = a*base + ((*s - 'a') + 10);
    else {
      printf("pane: numero invalido! \n");
      exit(1);
    }
  }
  return a;
}

int xbyte (packed_t word, int bytenum) {
  /* implementar!!! */
  packed_t buff = word;

  buff >>= (bytenum*8);

  buff = buff & 0x000000FF;

  return (signed char) buff;
}

int main (int argc, char **argv) {
  int x;
  if (argc != 3) {
    printf ("uso: %s <word (em hexadecimal)> <bytenum>\n", argv[0]);
    exit(1);
  }

  x = xbyte(string2num(argv[1], 16), atoi(argv[2]));
  printf ("%08x  %d\n", x, x);
  return 0;
}


// 0x01ABCD02 >> 8 = 0x0001ABCD
// 0x0001ABCD & 0xFF = 0xCD

// C -> 1100
// D -> 1101

// 1100 1101

//Como o primeiro caractere é 1, caractere de controle no signed significa que é negativo

//Transofrmando para decimal
// Inverta os bits sabendo que já é negativo e soma um.

// 0011 0010
// +       1
//------------
// 0011 0011

//1*2ˆ5 = 32
//+
//1*2ˆ4 = 16
//+
//1*2ˆ1 = 2
//+
//1*2ˆ0 = 1

//= -51

// Uma forma alternativa (rápida) é converter por hex: 0011 0011 = 0x33.
// Em decimal: 3×16 + 3 = 48 + 3 = 51.