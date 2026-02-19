'''Faça um programa que leia do arquivo matriz.dat os valores de uma matriz 10 x 10 de números 
inteiros, 10 números por linha separados por espaço em branco e imprima na tela a matriz e o 
resultado da soma de todos os seus valores. '''


Arquivo = 'matriz'

arqEntrada = open(Arquivo +'.dat','r')



somaLinha = 0
for linha in arqEntrada:
    print(linha.strip())
    linha2 = linha.split()
    for elemento in linha2:
            somaLinha = somaLinha + int(elemento)


arqEntrada.close()

print(somaLinha)