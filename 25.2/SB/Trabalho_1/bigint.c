    //Arquivo para implementação das funções do programa
    #include "bigint.h"
    #include <stdio.h>

    void big_val (BigInt res, long val)
    {

        int tam_val,tam_res, tam_restante, i = 0;
        tam_val = sizeof(val); //Pega a qunatidade de bytes.
        tam_res = NUM_BITS/8; //Como é um unsined char vai ser 16 bytes
        tam_restante = tam_res - tam_val;
        unsigned char *p = (unsigned char*)&val; //Aponto p para o primeiro byte de val
        if(tam_restante > 0)
        {
            while (i < tam_val) 
            { //Faz a mesma coisa que o dump, porém guarda no vetor que é respesntado como um int "Big" de 16 bytes
                res[i] = *p;
                i++;
                p++;
            } 
            if(val < 0)
            {
                while(i < tam_res)
                {
                    res[i] = 0xFF;
                    i++;
                }   
            }
            else
            {
                while(i < tam_res)  
                {
                    res[i] = 0x00;
                    i++;
                }   
            }
        }
    }

    void big_comp2(BigInt res, BigInt a)
    {
        int tam_bigInt = NUM_BITS/8;
        unsigned int carry = 1;
        for(int i = 0; i < tam_bigInt; i++)
        {
            unsigned int inv = (unsigned int)a[i] ^ 0xFFu; //XOR para inverter o byte

            unsigned int sum = inv + carry; //Add o +1

            res[i] = (unsigned char)(sum & 0xFF);

            carry = sum >> 8; 
        }
    }


    /* res = a + b */
void big_sum(BigInt res, BigInt a, BigInt b)
{
    unsigned int carry = 0;
    for(int i = 0; i < (NUM_BITS/8); i++)
    {
        int soma = a[i] + b[i] + carry;
        if(soma >= 256)
        {
            res[i] = soma - 256;
            carry = 1;
        }
        else
        {
            res[i] = soma;
            carry = 0;
        }
    }
}
//Guardo os bytes com um inteiro, somo e vejo se passou de 8 bits, se passou joga pro próximo e add o resto no início


void big_sub (BigInt res, BigInt a, BigInt b)
{
    BigInt neg_b;
    big_comp2(neg_b, b);

    big_sum(res, a, neg_b);
}

void big_mul(BigInt r, BigInt a, BigInt b) {

    for (int i = 0; i < 16; i++) {
        r[i] = 0;
    }

    for (int i = 0; i < 16; i++) {
        if (a[i] == 0) continue;
        
        int carry = 0;
        
        for (int j = 0; j < 16; j++) {
            if (i + j >= 16) break;
            
            int prod = a[i] * b[j] + r[i + j] + carry;
            
            r[i + j] = prod % 256;
            carry = prod / 256;
        }
    }
}


void big_shl(BigInt res, BigInt a, int n) {

    int byte_shift = n / 8;   // quantos bytes INTEIROS pular
    int bit_shift = n % 8;     // quantos bits DENTRO do byte
    
    for (int i = 0; i < NUM_BITS/8; i++) {
        res[i] = 0;
    }
    
    for (int i = 0; i < NUM_BITS/8; i++) {
        // Destino = posição atual + quantos bytes pular
        int dest_byte = i + byte_shift;
        
        if (dest_byte >= NUM_BITS/8) break;
        
        // Máscara 0xFF garante que só pegamos 8 bits por que o compilador automaticamente aumenta para 32 bits
        res[dest_byte] |= (a[i] << bit_shift) & 0xFF;
        
        if (bit_shift > 0 && dest_byte + 1 < NUM_BITS/8) {
            // Bits que "escaparam" vão pro próximo byte
            res[dest_byte + 1] |= (a[i] >> (8 - bit_shift)) & 0xFF;
        }
    }
}



/* res = a >> n (lógico) - sempre entra 0 pela esquerda */
void big_shr(BigInt res, BigInt a, int n) {

    // Caso especial: shift de 0 bits se não fizer shift nenhum
    if (n == 0) {
        for (int i = 0; i < NUM_BITS/8; i++) {
            res[i] = a[i];
        }
        return;
    }
    
    // Caso especial: shift >= 128 bits 16 bytes (zera tudo) -> quer dizer que fez um shift completo. apagou tudo
    if (n >= 128) {
        for (int i = 0; i < NUM_BITS/8; i++) {
            res[i] = 0;
        }
        return;
    }
    
    // Quantos bytes inteiros deslocar
    int byte_shift = n / 8;
    // Quantos bits dentro do byte
    int bit_shift = n % 8;
    
    // Zera o resultado
    for (int i = 0; i < NUM_BITS/8; i++) {
        res[i] = 0;
    }
    
    // Desloca byte a byte (de baixo pra cima no little endian)
    for (int i = 0; i < NUM_BITS/8; i++) {
        int src_byte = i + byte_shift;
        
        if (src_byte >= NUM_BITS/8) break;  // saiu do array
        
        // Desloca os bits do byte de origem pra direita
        res[i] = (a[src_byte] >> bit_shift) & 0xFF;
        
        // Se tem bits do próximo byte que "descem", pega eles
        if (bit_shift > 0 && src_byte + 1 < NUM_BITS/8) {
            res[i] |= (a[src_byte + 1] << (8 - bit_shift)) & 0xFF;
        }
    }
}


void big_sar(BigInt res, BigInt a, int n) {

    if (n == 0) {
        for (int i = 0; i < NUM_BITS/8; i++) {
            res[i] = a[i];
        }
        return;
    }
    
    // Pega o bit de sinal verificnado se ele está ligado pela máscara
    int sinal = (a[15] & 0x80) ? 1 : 0;
    
    // Caso especial: shift >= 128 bits
    if (n >= 128) {
        unsigned char fill = sinal ? 0xFF : 0x00;
        for (int i = 0; i < NUM_BITS/8; i++) {
            res[i] = fill;
        }
        return;
    }
    
    int byte_shift = n / 8;
    int bit_shift = n % 8;
    
    // Zera o resultado
    for (int i = 0; i < NUM_BITS/8; i++) {
        res[i] = 0;
    }
    
    // Desloca byte a byte
    for (int i = 0; i < NUM_BITS/8; i++) {
        int src_byte = i + byte_shift;
        
        // Se o byte de origem não existe, preenche com extensão de sinal
        if (src_byte >= NUM_BITS/8) {
            // Preenche ESTE e TODOS os próximos bytes
            for (int j = i; j < NUM_BITS/8; j++) {
                res[j] = sinal ? 0xFF : 0x00;
            }
            break;  // para o loop principal
        }
        
        // Desloca os bits
        res[i] = (a[src_byte] >> bit_shift) & 0xFF;
        
        // Pega bits que "descem" do próximo byte
        if (src_byte + 1 < NUM_BITS/8) {
            res[i] |= (a[src_byte + 1] << (8 - bit_shift)) & 0xFF;
        } else if (sinal && bit_shift > 0) {
            // Se não tem próximo byte E é negativo, preenche com 1s
            res[i] |= (0xFF << (8 - bit_shift)) & 0xFF;
        }
    }
}