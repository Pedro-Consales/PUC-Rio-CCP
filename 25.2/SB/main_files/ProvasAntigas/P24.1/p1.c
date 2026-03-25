#include <stdio.h>



// 0x01020304
// 0000 0001 0000 0010 0000 0011 0000 0100
//  0     1    0    2   0    3     0    4
// 0000 0000 0000 0000 0000 0000 1111 1111
//   byte1     byte2     byte3     byte4
unsigned int inverteOrdemBytes(unsigned int i)
{
    unsigned int buff_i = i;
    unsigned int i_final;

    unsigned int byte_um, byte_dois, byte_tres, byte_quatro;

    byte_um = buff_i & 0x000000FF; //0000 0000 | 0000 0000 | 0000 0000 | 0000 1111
    byte_um <<= 24; // 0000 1111 | 0000 0000 | 0000 0000 | 0000 0000
    buff_i >>= 8; //0000 0000 0000 0001 0000 0010 0000 0011




    //0000 0000 0000 0001 0000 0010 0000 0011
    // 0    0    0   1    0    2    0    3
    byte_dois = buff_i & 0x000000FF; //0000 0000 | 0000 0000 | 0000 0000 | 0000 0011
    byte_dois <<= 16; // 0000 0000 | 0000 0011 | 0000 0000 | 0000 0000|
    buff_i >>= 8; //0000 0000 0000 0000 0000 0001 0000 0010

    byte_tres = buff_i & 0x000000FF;//0000 0000 0000 0000 0000 0000 0000 0010
    byte_tres <<= 8; //0000 0000 | 0000 0000 | 0000 0010 | 0000 0000
    buff_i >>= 8; //0000 0000 0000 0000 0000 0000 0000 0001

    byte_quatro = buff_i & 0x000000FF; //0000 0000 0000 0000 0000 0000 0000 0001
    //Não precisa caminhar com o byte 4
    buff_i >>= 8; //0000 0000 0000 0000 0000 0000 0000 0000

    i_final = byte_um | byte_dois | byte_tres | byte_quatro;
    
    return i_final;
}

void dump (void *p, int n) { //p é um ponteiro para um endereço de memória (void????)
  unsigned char *p1 = p;
  while (n--) {
    printf("%02x ", *p1);
    p1++;
  }
}


int main(void)
{

    int num = 16909060;
    dump(&num, sizeof(num));

    printf("\n\n");

    int i_final = inverteOrdemBytes(num);
    dump(&i_final, sizeof(num));
    

    return 0;
}