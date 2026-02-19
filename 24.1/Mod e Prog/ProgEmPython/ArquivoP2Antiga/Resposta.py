


def InfoDisciplinas():
    NovaLista = []
    ArqEntrada = open('DISCIPLINAS.TXT','r', encoding = 'utf-8')
    for linha in ArqEntrada:
        NovaLista.append(linha.strip().split(','))
    ArqEntrada.close()
    return NovaLista
print(InfoDisciplinas())




def retorna(NovaLista,cod):
    cont = 0
    for elemento in NovaLista:
        cont += 1
        if cod in elemento:
            return cont
    return None
            
print(retorna(InfoDisciplinas(),'MAT101'))


ArqEntrada2 = open('ALUNOS.TXT','r', encoding = 'utf-8')


