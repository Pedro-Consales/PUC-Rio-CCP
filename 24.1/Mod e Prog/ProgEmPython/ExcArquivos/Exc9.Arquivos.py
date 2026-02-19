'''Faça um programa que leia o arquivo texto80.txt. Este arquivo contém linhas de texto e deve ser 
impresso na tela em modo justificado. Considere que as linhas terão no máximo 80 caracteres.
'''

ArqEntrada = open('texto80.txt','r')


conc = ''
for linha in ArqEntrada:
    linha = linha.strip()
    for caractere in linha:
        conc += caractere
        if len(conc) == 80:
            print(conc)
            conc = ''
if conc != '':
    print(conc)
        



ArqEntrada.close()
        