# 2) Você é responsável pela manutenção de um equipamento que opera 24 horas por dia. Um componente crítico
# desse equipamento se desgasta com o tempo e precisa ser substituído quando atinge o fim da vida útil. A cada hora
# de operação, existe uma chance de ocorrer uma falha total inesperada do componente, que causa sua substituição
# imediata com custo elevado. Além disso, a cada hora de operação, o componente sofre um tipo de desgaste aleatório.
# O componente começa com vida útil = 1.0 e, a cada hora, ele sofre um dos seguintes desgastes:

# Tipo    Redução Probabilidade Custo de substituição
#         de vida 
#         útil 
# Leve     0.01       70%         R$ 400
# Moderado 0.03       20%         R$ 500
# Severo   0.07       10%         R$ 700

# Em qualquer hora, pode ocorrer uma falha total aleatória, com probabilidade de 0,2% (0.002), e, nesse caso, o
# componente é substituído imediatamente e o custo é fixo de R$ 2.000. Quando a vida útil chega a 0 ou menos, o
# componente é substituído imediatamente, com o custo dependendo do tipo de desgaste que causou a falha. Após
# cada substituição (por falha total ou desgaste), a vida útil do componente reinicia em 1.0.
# Usando o gerador de números aleatórios padrão do R ou Python e a semente 123, simule esse processo por 1.000
# execuções (cada uma com 720 horas) e, ao final, calcule:

# a) A média de substituições por simulação.
# b) O custo médio total por simulação.
# c) O número médio de falhas totais aleatórias.

import random

random.seed(123)

qtd_simulacoes = 1000
horas = 720

vida_util = 1.0

custo_total = 0
cont_substituicoes = 0
cont_falhas_totais = 0
custo_subs = 0

for i in range(qtd_simulacoes):

    vida_util = 1.0
    for j in range(horas):
    
        
        danos = ["Leve", "Moderado", "Severo"]
        falha_total = [None, "Falha Total"]

     
        falha = random.choices(falha_total, weights=[0.998, 0.002])[0]

        if falha == "Falha Total":
            vida_util = 1.0
            custo_subs += 2000
            cont_falhas_totais+=1
            cont_substituicoes += 1

        dano = random.choices(danos, weights=[0.7, 0.2, 0.1])[0]

        if dano == "Leve":
            vida_util -= 0.01
        elif dano == "Moderado":
            vida_util -= 0.03
        elif dano == "Severo":
            vida_util -= 0.07

        if vida_util <= 0:

            if dano == "Leve":
                custo_subs += 400
            elif dano == "Moderado":
                custo_subs += 500
            elif dano == "Severo":
                custo_subs += 700
            
            vida_util = 1.0
            cont_substituicoes += 1





print(f"média de substituição por simulação: {cont_substituicoes/qtd_simulacoes}\n")
print(f"custo médio total por simulação: {custo_subs/qtd_simulacoes}\n")
print(f"média de falhas totais aleatórias: {cont_falhas_totais/qtd_simulacoes}\n")

