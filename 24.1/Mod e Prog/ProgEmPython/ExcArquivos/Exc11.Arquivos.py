'''Faça um programa que leia um arquivo texto (4a.txt) com nomes e idades, separados por ponto
e-vírgula e grave um arquivo (4b.txt) com os dados daqueles cujos nomes comecem por 'A'. '''


ArqEntrada = open('4a.txt','r')
ArqSaída = open('4b.txt','w')


for linha in ArqEntrada:
    if linha[0] in 'Aa':
        ArqSaída.write(linha + '\n')