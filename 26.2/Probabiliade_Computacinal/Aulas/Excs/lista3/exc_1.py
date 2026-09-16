import random

#1) a)  Construa um código baseado no LCG para realizar uma simulação com 10.000 lançamentos simultâneos de duas
# moedas, ambas honestas, e apresentar em quantos lançamentos o resultado obtido foi cara e coroa. O LCG deve ser
# utilizado para tratar o lançamento de ambas as moedas.

def LCG(seed, a, c, M, n):
    x = seed
    u = []
    for i in range(n):
        x = (a * x + c) % M
        u.append(x / M)
    return u

N = 10000                    # lançamentos
a, c, M = 1664525, 1013904223, 2**32
U = LCG(seed=3, a=a, c=c, M=M, n=2 * N)   # 2 sorteios por lançamento

cont_cara_E_coroa = 0

cont_cara = 0
cont_coroa = 0

MoedaA_cont_cara = 0
MoedaA_cont_coroa = 0

MoedaB_cont_cara = 0
MoedaB_cont_coroa = 0

for i in range(N):

    if U[i] < 0.5:
        MoedaA_cont_cara += 1
        cont_cara += 1
    elif U[i] >= 0.5:
        MoedaA_cont_coroa +=1 
        cont_coroa +=1

    if U[N+i] < 0.5:
        MoedaB_cont_cara += 1
        cont_cara += 1
    elif U[N+i] >= 0.5:
        MoedaB_cont_coroa +=1 
        cont_coroa +=1

    if (U[i] < 0.5 and U[N+i] >= 0.5) or (U[i] >= 0.5 and U[N+i] < 0.5):
        cont_cara_E_coroa += 1
    




print(f"Moerda A - Caras: {MoedaA_cont_cara} / Coroas: {MoedaA_cont_coroa}\n")
print(f"Moerda B - Caras: {MoedaB_cont_cara} / Coroas: {MoedaB_cont_coroa}\n\n")

print(f"Caras: {cont_cara} / Coroas: {cont_coroa}\n")

print(f"Carar e Coroas nas duas pontas: {cont_cara_E_coroa}\n\n")

# 1) b) Construa um código baseado no LCG e no Mersenne Twister para realizar uma simulação com 10.000 lançamentos
# simultâneos de uma moeda e de um dado (8 faces), ambos honestos, e apresentar em quantos lançamentos o
# resultado obtido foi simultaneamente coroa e face 𝟓. O LCG deve ser utilizado para tratar o lançamento da moeda e
# o Mersenne Twister para tratar o lançamento do dado.

import numpy as np

N = 10000                    # lançamentos
a, c, M = 1664525, 1013904223, 2**32
U = LCG(seed=1, a=a, c=c, M=M, n=N)   # 1 sorteios por lançamento por que agora é uma moeda

valores_dado = np.random.sample(N)

cont_coroa_face5 = 0



for i in range(N):
    if U[i] >= 0.5 and (valores_dado[i] >= 4/8 and valores_dado[i] < 5/8):
        cont_coroa_face5 += 1

print(f"cont_coroa_face5: {cont_coroa_face5}\n")
print(f"prob: {cont_coroa_face5/N}")




# 1) c) Construa um código baseado no LCG e no LM (com lançamento de 10 moedas) para realizar uma simulação com
# 10.000 lançamentos simultâneos de uma moeda honesta e de um dado (8 faces) viciado (probabilidade de obter a
# face 𝟑 é zero e é a mesma para as demais faces) e apresentar em quantos lançamentos o resultado obtido foi
# simultaneamente coroa e face 𝟖. O LCG deve ser utilizado para tratar o lançamento da moeda e o LM para tratar o
# lançamento do dado.


# def LM(U_moeda, n_bits, n_numeros):

#     MAX = 2**n_bits - 1          # maior número possível (o 31 do exemplo com n=5)
#     u = []
#     k = 0                        # posição do próximo lançamento a consumir
#     for i in range(n_numeros):
#         numero = 0
#         for j in range(n_bits):
#             bit = 0 if U_moeda[k] < 0.5 else 1   # cara = 0, coroa = 1
#             numero = numero * 2 + bit            # empurra uma casa e encaixa o bit novo
#             k += 1
#         u.append(float(numero) / float(MAX))
#     return u




# N = 10000                    # lançamentos
# a, c, M = 1664525, 1013904223, 2**32
# U = LCG(seed=3, a=a, c=c, M=M, n=10 * N)   # 10 sorteios por lançamento pq são 10 moeda ou seja 100.000 jogodas /10 são 10.000. A cada 10.000 é um bloco novo


# n_bits = 10
# U_moeda_dado = U[N:]              # os 100.000 do dado
# V = LM(U_moeda_dado, n_bits, N) 


# cont_coroa_E_face8 = 0
# for i in range(10*N):
#     if U[i] >= 0.5 and (V[i] >= 6/7 and V[i] <= 7/7):
#         cont_coroa_E_face8 += 1

# print(f"cont_coroa_face8: {cont_coroa_E_face8}\n")
# print(f"prob: {cont_coroa_E_face8/(10*N)}")



# 1 d) Construa um código baseado no Mersenne Twister e no LM (com lançamento de 10 moedas) para realizar uma
# simulação com 10.000 lançamentos simultâneos de uma moeda viciada (probabilidade de tirar cara é 0,45) e de um
# dado (𝟖 faces) honesto, e apresentar a probabilidade de se obter pelo menos um dos resultados: simultaneamente
# cara e face 𝟏; simultaneamente cara e face 𝟒;simultaneamente coroa e face 𝟕. O Mersenne Twister deve ser utilizado
# para tratar o lançamento da moeda e o LM para tratar o lançamento do dado.





def lm_dado(n_bits=10):
    bits = [random.randint(0, 1) for _ in range(n_bits)]       # 10 "lançamentos de moeda"
    numero = sum(bit * (2 ** i) for i, bit in enumerate(bits))
    valor = numero / (2 ** n_bits - 1)                          # aqui já para: devolve o u cru
    return valor

faces_moeda = ["CA", "CO"]

cont_cara_e_face1 = 0
cont_cara_e_face4 = 0
cont_cara_e_face7 = 0

cont_acontecimento_evento = 0

for i in range(N):

    resultado_moeda = random.choices(faces_moeda, weights=[0.45, 0.55])[0]
    face_dado = lm_dado()


    if resultado_moeda == "CA" and (face_dado < 1/8 and face_dado >= 0):
        cont_cara_e_face1 += 1
        cont_acontecimento_evento +=1
    if resultado_moeda == "CA" and (face_dado < 4/8 and face_dado >= 3/8):
        cont_cara_e_face4 += 1
        cont_acontecimento_evento +=1
    if resultado_moeda == "CO" and (face_dado < 7/8 and face_dado >= 6/8):
        cont_cara_e_face7 += 1
        cont_acontecimento_evento +=1 


print(f"Probabilidade de acontecer o evento:{cont_acontecimento_evento/N}")