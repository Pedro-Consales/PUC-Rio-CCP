'''Faça um programa que leia da entrada uma sequência de nomes de pessoas. O usuário pode 
terminar a leitura com um nome vazio, ou seja, digitando <Enter> como primeiro caracter de um 
novo nome. Armazene esta sequência de nomes em um arquivo chamado nomes.dat. '''



arqSaída = open('nomes.dat','w')

Nome = input('Digite o nome:')
while Nome != '':
    arqSaída.write(Nome + '\n')
    Nome = input('Digite o nome:')


arqSaída.close()

