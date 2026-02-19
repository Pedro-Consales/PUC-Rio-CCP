'''Faça um programa que leia o arquivo "prog1.dat" (feito pelo código anterior), criado por você, e imprima a média dos 
alunos da turma e quantos alunos tiveram notas acima da média. '''

arqEntrada = open('prog1.dat','r')



soma = 0
contNúmeros = 0
contAcimaMédia = 0
lista = []
for linha in arqEntrada:
    contNúmeros += 1
    linha = linha.split(';')
    for k in range(len(linha)):
        linha[k] = linha[k].strip()
    soma += int(linha[1])
    lista.append(int(linha[1]))
média = soma / contNúmeros



for elemento in lista:
    if elemento > média:
        contAcimaMédia += 1
    
arqEntrada.close()


print('A média é:',média)
print('Foram',contAcimaMédia,'alunos acima da médaia')