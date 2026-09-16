import random

#Enunciado.

#Suponha que há 3 moedas, cada uma de uma cor diferente (irrelevante), mas todas com probabilidade de 3/5 de obter coroa
#e 2/5 de obter cara.

#Caso A = Obter uma coroa e uma cara nos odis primeiros lançamentos em qualquer ordem
#Caso B = Obtter duas coros nos dois ultimos lançamentos

nsamples = 1000000
contA = 0
contB = 0
moeda = ['CA', 'CO']

for i in range(nsamples):

    face1 = random.choices(moeda, weights=[2/5, 3/5], k = 1)[0]
    face2 = random.choices(moeda, weights=[2/5, 3/5], k = 1)[0]
    face3 = random.choices(moeda, weights=[2/5, 3/5], k = 1)[0]


    if ((face1 == 'CO' and face2 == 'CA') or (face1 == 'CA' and face2 == 'CO')): #Caso A: 
        contA += 1

    if (face2 == 'CO' and face3 == 'CO'): #Caso B: 
        contB += 1

PA = contA / nsamples
PB = contB / nsamples

print(f'Probabilidade de A: {PA:.4f}')
print(f'Probabilidade de B: {PB:.4f}')