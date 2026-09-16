# 3) Em um campeonato, três lutadores (A, B e C) participam de uma etapa de dupla eliminação em que os confrontos
# são disputados em formato de duelos individuais. No primeiro duelo, dois lutadores se enfrentam, enquanto o terceiro
# aguarda (descansa). O vencedor do primeiro duelo permanece para o próximo duelo, enfrentando o lutador que ficou
# aguardando; o perdedor do primeiro duelo é eliminado da etapa; o vencedor do segundo duelo é o campeão da etapa.
# As probabilidades de vitória entre os lutadores em duelos diretos são: A vence B com probabilidade 0,60; B vence C
# com probabilidade 0,65; C vence A com probabilidade 0,55. O lutador A, por ter apresentado melhor desempenho que
# os lutadores B e C em etapas anteriores do campeonato, apresenta probabilidade de 0,4 de ser escolhido para
# descansar no primeiro duelo enquanto os lutadores B e C apresentam a mesma probabilidade. Assumindo que os
# resultados dos duelos são independentes e que o lutador que aguarda no primeiro duelo é escolhido aleatoriamente,
# utilize simulação (1.000 execuções e semente 123) para estimar a probabilidade de cada lutador vencer a etapa.

import random

random.seed(123)

qtd_exec = 1000

lutadorA = "A"
lutadorB = "B"
lutadorC = "C"


vencedor_prim_duelo:str
vencedor_seg_duelo:str

cont_vitorias_A = 0
cont_vitorias_B = 0
cont_vitorias_C = 0 

for i in range(1000):

    lutadores = [lutadorA, lutadorB, lutadorC]

    lutador_escolhido_descanso = random.choices(lutadores, weights=[0.4, 0.3, 0.3])[0]

    lutadores.remove(lutador_escolhido_descanso) #Sobra só os do primeiro duelo

    if "A" in lutadores and "B" in lutadores:
        vencedor_prim_duelo = random.choices(lutadores, weights=[0.6, 0.4])[0]
    if "B" in lutadores and "C" in lutadores:
        vencedor_prim_duelo = random.choices(lutadores, weights=[0.65, 0.35])[0]
    if "A" in lutadores and "C" in lutadores:
        vencedor_prim_duelo = random.choices(lutadores, weights=[0.45, 0.55])[0]




    novo_duelo = [lutador_escolhido_descanso, vencedor_prim_duelo]



    if novo_duelo[0] == "A" and novo_duelo[1] == "B":
        vencedor_seg_duelo = random.choices(novo_duelo, weights=[0.6, 0.4])[0]
    elif novo_duelo[0] == "B" and novo_duelo[1] == "A":
        vencedor_seg_duelo = random.choices(novo_duelo, weights=[0.4, 0.6])[0]

    if novo_duelo[0] == "B" and novo_duelo[1] == "C":
        vencedor_seg_duelo = random.choices(novo_duelo, weights=[0.65, 0.35])[0]
    elif novo_duelo[0] == "C" and novo_duelo[1] == "B":
         vencedor_seg_duelo = random.choices(novo_duelo, weights=[0.35, 0.65])[0]

    if novo_duelo[0] == "A" and novo_duelo[1] == "C":
        vencedor_seg_duelo = random.choices(novo_duelo, weights=[0.45, 0.55])[0]
    elif novo_duelo[0] == "C" and novo_duelo[1] == "A":
        vencedor_seg_duelo = random.choices(novo_duelo, weights=[0.55, 0.45])[0]





    if vencedor_seg_duelo == "A":
        cont_vitorias_A += 1
    elif vencedor_seg_duelo == "B":
        cont_vitorias_B += 1
    elif vencedor_seg_duelo == "C":
        cont_vitorias_C += 1


print(f"Probabilidade do A vencer as etapas {cont_vitorias_A/qtd_exec}\n")
print(f"Probabilidade do B vencer as etapas {cont_vitorias_B/qtd_exec}\n")
print(f"Probabilidade do C vencer as etapas {cont_vitorias_C/qtd_exec}\n")








