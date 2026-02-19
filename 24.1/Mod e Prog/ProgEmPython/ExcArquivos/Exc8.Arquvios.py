'''Faça um programa que leia um número do teclado e a matriz contida no arquivo matriz.dat e 
imprima o resultado da multiplicação do número pelos elementos da matriz.'''

ArqEntrada = open('matriz.dat','r')

Número = int(input('Digite o número a multiplicar:'))



for linha in ArqEntrada:
    #print(linha.strip()) #divide a partir de qualquer caracter de controle ou o do caractere que vc botar no ()
    linha2 = linha.split() #transforma a linha em uma lista de strings
    for i in range(len(linha2)):
        linha2[i] = int(linha2[i]) * Número
    print(linha2)
    

ArqEntrada.close()