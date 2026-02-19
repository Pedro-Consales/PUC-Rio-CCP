'''Faça um programa que leia da entrada o nome e a nota final (número real) dos alunos de uma 
turma de Prog1. O programa deve armazenar os dados em um arquivo chamado prog1.dat, 
separados por ponto-e-vírgula. '''


ArqSaída = open('prog1.dat','w')

Nome = input('Digite o nome do aluno:')
Nota = input('Digite a nota desse aluno:')
while Nome != '':
    ArqSaída .write(Nome +';' + Nota + '\n')
    Nome = input('Digite o nome do aluno:')
    Nota = input('Digite a nota desse aluno:')

ArqSaída.close()