'''Faça um programa que leia do arquivo matriz.dat os valores de uma matriz 10 x 10 de números 
inteiros, 10 números por linha separados por espaço em branco e gere um arquivo chamado 
transp.dat, contendo a matriz transposta da que foi lida.'''


ArqEntrada = open('matriz.dat','r')

ArqSaída = open('transp.dat','w')


NovaMatriz = [[],
              [],
              [],
              [],
              [],
              [],
              [],
              [],
              [],
              []]

for linha in ArqEntrada:
    linha = linha.strip().split()
    for k in range(len(linha)):
        NovaMatriz[k].append(linha[k])

for elemento in NovaMatriz:
    for sub in elemento:
        ArqSaída.write(sub + ' ')
    ArqSaída.write('\n')

ArqEntrada.close()
ArqSaída.close()