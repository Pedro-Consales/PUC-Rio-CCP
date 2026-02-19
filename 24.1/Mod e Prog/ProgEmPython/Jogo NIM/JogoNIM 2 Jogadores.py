import random



def exibeApresentacaoJogo():
    print('***' + ' '*44 + '***')
    print('***' + ' '*18 + 'Jogo NIM' + ' '*18 + '***')
    print('***' + ' '*5 + 'Vence quem retirar o ultimo bastão' + ' '*5 + '***')
    print('***' + ' '*16 + 'Boa sorte!!!' + ' '*16 + '***')

exibeApresentacaoJogo()




"""def geraListaBastões():
    Grupo = []
    for i in range(random.randint(3,6)):
        i = Grupo.append(random.randint(1,7))
    return Grupo"""



def geraListaBastões():
    Grupo = []
    cont0 = 0
    cont = random.randint(3,6)
    while cont0 < cont:
        Grupo.append(random.randint(1,7))
        cont0 += 1
    return Grupo


print(geraListaBastões())


def exibeBastões():
    for elemento in geraListaBastões():
        Grupos = ('█' + '   ')*elemento
        print(Grupos)
        print('\n')

exibeBastões()