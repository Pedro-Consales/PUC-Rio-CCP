#include <stdio.h>
int main(void) {
  unsigned int x = 0x87654321;
  unsigned int y, z;

  /* o byte menos significativo de x e os outros bits em 0 */
  y = x & 0xFF;

  /* o byte mais significativo com todos os bits em '1' 
     e os outros bytes com o mesmo valor dos bytes de x */
  z =  (x & 0x00FFFFFF) | 0xFF000000;

  printf("%08X %08X\n", y, z);
}



// Para y:
// O enunciado pede que fiquemos apenas com o byte menos significativo (LSB) de x.
// Para nós, basta imaginar "zerar os outros bytes" e deixar só o último.
// Mas o computador não entende isso diretamente: ele precisa de uma operação lógica
// aplicada a uma máscara. 
// Aqui usamos o operador lógico & com a máscara 0xFF (11111111 em binário).
// Essa máscara preserva apenas os 8 bits menos significativos e zera todos os outros.
// Assim, y = x & 0xFF.


// Para y:
// Queremos apenas o byte menos significativo de x (LSB).
// O valor de x = 0x87654321 em binário é:
//    10000111 01100101 01000011 00100001
// A máscara 0xFF em binário é:
//    00000000 00000000 00000000 11111111
//
// Aplicando o operador lógico &:
//    10000111 01100101 01000011 00100001   (x)
// &  00000000 00000000 00000000 11111111   (máscara)
// -------------------------------------------------
//    00000000 00000000 00000000 00100001
//
// Resultado: y = 0x00000021 (apenas o LSB de x). 


//====================


// Para z:
// Queremos substituir o byte mais significativo (MSB) de x por 0xFF.
// O valor de x = 0x87654321 em binário é:
//    10000111 01100101 01000011 00100001
//
// Passo 1: aplicar a máscara 0x00FFFFFF para zerar o MSB:
//    10000111 01100101 01000011 00100001   (x)
// &  00000000 11111111 11111111 11111111   (máscara 0x00FFFFFF)
// ------------------------------------------------------------
//    00000000 01100101 01000011 00100001   (0x00654321)
//
// Passo 2: aplicar OR com 0xFF000000 para inserir 0xFF no MSB:
//    00000000 01100101 01000011 00100001   (resultado do passo 1)
// |  11111111 00000000 00000000 00000000   (0xFF000000)
// ------------------------------------------------------------
//    11111111 01100101 01000011 00100001
//
// Resultado final: z = 0xFF654321


