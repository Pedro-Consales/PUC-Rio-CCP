''' Passo 1
 ● Façaumprograma para imprimir as 10 primeiras linhas do arquivo
 dadosFilmesAmostra.tsv
 ● Inspecione a formatação do arquivo e entenda quais dados existem em cada coluna


 Passo 2
 ● Façaumprograma que conte e imprima a quantidade para:
 ○ titleType- short, movie, tvShort, etc…
 ○ genres- Documentary, Short, Animation, etc…
 ○ Obs:oseparador de campos nesse formato é o ‘\t’

 Passo 3
 ● Façaumprograma que crie um arquivo para cada tipo de ‘titleType’ e adicione os
 respectivos tipos em cada arquivo.

 Passo 4
 ● Execute os passos 2 e 3 para o arquivo dadosFilmes.tsv

 Passo 5
 ● Escolha uma palavra que exista nos títulos dos filmes e conte quantos filmes contém
 essa palavra no título.
 ● Imprima o resultado'''


ArqEntrada = open('dadosFilmesAmostra.tsv','r', encoding = 'utf-8')


Linha = ArqEntrada.readline()

contType = {}
ArqType = {}
for Linha in ArqEntrada:
    lista = Linha.split('\t')
    if lista[1] not in contType:
        contType[lista[1]] = 0
        ArqType[lista[1]] = open('Arq_'+lista[1]+'.txt','w', encoding = 'utf-8')
    contType[lista[1]] += 1
    ArqType[lista[1]].write(Linha)
print(contType)





ArqEntrada.close()

for elemento in ArqType:
    ArqType[elemento].close()


ArqEntrada2 = open('dadosFilmes.tsv','r', encoding='utf-8')


Linha2 = ArqEntrada2.readline()

contType2 = {}
ArqType2 = {}
for Linha2 in ArqEntrada2:
    lista2 = Linha2.split('\t')
    if lista2[1] not in contType2:
        contType2[lista[1]] = 0
        ArqType2[lista[1]] = open('Arq2_'+lista2[1]+'.txt','w', encoding = 'utf-8')
    contType2[lista[1]] += 1
    ArqType2[lista[1]].write(Linha2)
    contMiss = 0
    if 'Miss' in lista2[2]:
        contMiss += 1 
print(contMiss,'!!!!!!!!!!!!!!!!!')
print(contType2)






ArqEntrada2.close()

for elemento2 in ArqType2:
    ArqType2[elemento2].close()
