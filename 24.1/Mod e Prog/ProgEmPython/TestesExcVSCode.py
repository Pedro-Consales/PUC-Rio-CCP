'''def trocachar(s):
    if s == '':
        return ''
    if s[0] == 'A':
        c = '@'
    else:
        c= s[0]
    return c + trocachar(s[1:])

    print(trocachar('AbacAte'))'''



"""def somaNIM(B1,B2):
    ResultSomaNIM = ''
    for i in range(len(B1)):
        if B1[i] == B2[i]:
            ResultSomaNIM += '0'
        elif B1[i] != B2[i]:
            ResultSomaNIM += '1'
    return ResultSomaNIM

print(somaNIM('1001','1010'))


def somaNIMdeUmaLista(l):
    resultado = "0000"
    for el in l:
        resultado = somaNIM(el, resultado)
    return resultado

l = ["1111", "0100","1010","0001"]
print("a soma NIM é %s"%(somaNIMdeUmaLista(l)))
"""





from random import randint as r
n = int(input('Numero de repeticoes: '))
total = 0
for k in range(n):
    jogada = r(1,6)
    if jogada == 1:
        total += 1

print(total / n * 100)




































''' Escreva um programa que leia do teclado três inteiros representando dia, mês e ano de nascimento de um aluno e exiba a 
senha do aluno, string gerada a partir da concatenação da soma dos dígitos do dia com a soma dos dígitos do mês com a 
soma dos dois últimos dígitos do ano. Exemplo: 
Entrada Saída 
27 
3 
1999 
'9318'''

'''dia = int(input('Digite a data do seu nascimento:'))
mes = int(input('Digite o mes do seu nascimento:'))
ano = int(input('Digite o ano do seu nascimento:'))


somaDia = str((dia//10) + (dia%10)) + str((mes//10) + (mes%10)) + str((ano/100) + (ano%100))


print(somaDia)'''

