''' Faça um programa que leia do arquivo 6a.dat uma matriz de números inteiros. O programa deve 
gravar, em outro arquivo (6b.dat), a soma das linhas dessa matriz.'''

ArqEntrada = open('matriz.dat','r')

ArqSaída = open('matrizB.dat','w')

soma = 0 
for linha in ArqEntrada:
    print(linha.strip())
    linha2 = linha.split()
    for elemento in linha2:
        soma = soma + int(elemento)
    ArqSaída.write(str(soma) + '\n')
    soma = 0 

ArqEntrada.close()

ArqSaída.close()