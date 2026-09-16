import random


moeda = ["CA", "CO"]


n_jogadas = 1000000

cont_ataqueFisico_Foraca4 = 0

for i in range(n_jogadas):

    dado = random.randint(1, 6)
    result1_moeda = random.choice(moeda)


    if result1_moeda == "CA" and dado == 4:
        cont_ataqueFisico_Foraca4 += 1  


# a) Quantas combinações diferentes de ataque podem acontecer
combinacoes = 2*6
print(f"a) Quantas combinações diferentes de ataque podem acontecer: {combinacoes}")

# b) Qual a probabilidade de ocorrer ataque físico com força 4
probabilidade_ataqueFisico_Foraca4 = cont_ataqueFisico_Foraca4 / n_jogadas
print(f"b) Qual a probabilidade de ocorrer ataque físico com força 4: {probabilidade_ataqueFisico_Foraca4:.2f}")


# c) Qual a probabilidade de realizar um ataque físico com força 4 se a moeda apresentar probabilidade de 2/3 de tirar Cara?
cont_ataqueFisico_Foraca4 = 0

for i in range(n_jogadas):

    result2_moeda = random.choices(moeda, weights=[2/3, 1/3])[0]  # Probabilidade de 2/3 para Cara e 1/3 para Coroa
    dado = random.randint(1, 6)

    if result2_moeda == "CA" and dado == 4:
        cont_ataqueFisico_Foraca4 += 1

probabilidade_ataqueFisico_Foraca4_com_moeda = cont_ataqueFisico_Foraca4 / n_jogadas
print(f"c) Qual a probabilidade de realizar um ataque físico com força 4 se a moeda apresentar probabilidade de 2/3 de tirar Cara: {probabilidade_ataqueFisico_Foraca4_com_moeda:.2f}")
