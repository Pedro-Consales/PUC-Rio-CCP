ArqEntrada = open('4a.txt','r')

for linha in ArqEntrada:
    linha.strip()
    linha2 = linha.split('  ')
    print(linha2)



ArqEntrada.close()