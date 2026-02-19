'''Faça um programa que leia do teclado os valores de duas matrizes inteiras 3x3 e armazene em 
um arquivo chamado matriz o resultado da soma das duas matrizes. '''


ArqSaída = open('MatrizExc7.txt','w')

Matriz1 = [[],
           [],
           []]


for linha in Matriz1:
    for elemento in range(3):
        Número = int(input('Digite um número para a matriz1:'))
        linha.append(Número)



Matriz2 = [[],
           [],
           []]

for linha in Matriz2:
    for elemento in range(3):
        Número = int(input('Digite um número para a matriz2:'))
        linha.append(Número)

print(Matriz1)
print(Matriz2)

MatrizSomada = [[],
                [],
                []]



for i in range(3):
    for j in range(3):
        MatrizSomada[i].append(Matriz1[i][j] + Matriz2[i][j])


print(MatrizSomada)


for elemento in MatrizSomada:
    for sub_elemento in elemento:
        ArqSaída.write(str(sub_elemento)+' '*(5-len(str(sub_elemento))))
    ArqSaída.write('\n')

ArqSaída.close()




