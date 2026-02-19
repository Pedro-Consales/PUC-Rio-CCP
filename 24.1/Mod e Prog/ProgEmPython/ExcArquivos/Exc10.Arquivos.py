'''Faça um programa que leia, de um arquivo (3a.dat), um conjunto de números inteiros, um por 
linha, e grave outro arquivo (3b.dat) com os mesmos números na ordem inversa. '''


ArqEntrada = open('3a.txt','r')
ArqSaída = open('3b.dat','w')


lista = []
for linha in ArqEntrada:
    lista.append(linha.strip())
print(lista)

d = lista[::-1]
for elemento in d:
    ArqSaída.write(elemento + '\n')

ArqEntrada.close()
ArqSaída.close()