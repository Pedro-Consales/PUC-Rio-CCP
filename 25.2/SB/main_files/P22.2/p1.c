#include <stdio.h>



unsigned int inverteOrdemBytes(unsigned int i)
{
    unsigned int buff_i = i;

    
    unsigned int byte1 = buff_i & 0xff;
    byte1 <<= 24;
    buff_i >>= 8;

    unsigned int byte2 = buff_i & 0xff;
    byte2 <<= 16;
    buff_i >>= 8;

    unsigned int byte3 = buff_i & 0xff;
    byte3 <<= 8;
    buff_i >>= 8;

    unsigned int byte4 = buff_i & 0xff;
    buff_i >>= 8;


    unsigned int i_final = byte1| byte2 | byte2 | byte4;
    
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