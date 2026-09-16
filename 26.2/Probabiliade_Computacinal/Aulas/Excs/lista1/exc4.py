# 4) Uma companhia aérea opera 20 voos diários em uma determinada rota, usando aeronaves com capacidade para
# 180 passageiros. Para maximizar a receita vende 190 passagens por voo, adotando a prática de overbooking. Cada
# passageiro tem uma chance entre 90% e 95% de comparecer ao embarque, refletindo perfis diferentes (executivo,
# lazer, conexão, etc.). Quando o total de passageiros que comparecem ultrapassa a capacidade da aeronave, a
# companhia adota a seguinte estratégia: passageiros que não embarcaram em um voo devido ao excesso (passageiros
# excedentes), entram em fila de espera (realocação) sendo priorizados para embarcar no voo seguinte e nunca são
# forçados a sair novamente; 25% dos passageiros excedentes aceitam voluntariamente não embarcar em troca de uma
# compensação de R$ 1.000,00; o restante dos excedentes é forçado a não embarcar e recebe uma compensação maior
# de R$ 2.500,00; tanto voluntários quanto forçados entram na fila de espera para embarcar no próximo voo, com
# prioridade sobre os passageiros originais do voo. Simule essa operação ao longo de 100 dias (semente 123),
# considerando os 20 voos diários, 

# e calcule: a taxa média de overbooking; o custo total e o custo médio diário das
# compensações; quantos passageiros foram realocados voluntariamente e quantos foram forçados.


import random
import time


random.seed(123)

qtd_dias = 100
qtd_voos_dia = 20

passagens_vendidas = 190
capacidade_aeronave = 180
qtd_passageiros_presentes = 0

vai_comparecer = [True, False]

cont_overbooking = 0
custo_compensacao = 0
cont_volunatriados = 0
cont_forcados = 0

total_passageiros_excedentes = 0
passageiros_excedentes = 0

for i in range(qtd_dias):


    for j in range(qtd_voos_dia):

        total_passageiros_excedentes += passageiros_excedentes
        qtd_passageiros_presentes = passageiros_excedentes
        #print(f"Embarque começa com {qtd_passageiros_presentes} passageiros - provavelmente vieram do overbooking do voo anterior")

        deu_overbooking = False

        for k in range(passagens_vendidas):


            probabilidade_comparecer = random.uniform(0.90, 0.95)

            compareceu = random.choices(vai_comparecer, weights=[probabilidade_comparecer, (1-probabilidade_comparecer)])[0] #Entre Comparecer ou Não Comparecer (true, false) ela tem uma probailidade DE COMAPRECER entre 0.90 e 0.95 e de não comparecer de entre [ (1 - 0.90), (1 - 0.95)]


            if compareceu:
                qtd_passageiros_presentes += 1
                #print(f"Passageiros presentes: {qtd_passageiros_presentes}\n")

                if qtd_passageiros_presentes > capacidade_aeronave:
                    deu_overbooking = True

            # else:
            #     print(f"!!!!! Passageiro {qtd_passageiros_presentes} não compareceu !!!!!! \n")

        if deu_overbooking:
            #print(f"Deu overbooking:\n {qtd_passageiros_presentes}/{capacidade_aeronave} passageiros\n\n")
            passageiros_excedentes = qtd_passageiros_presentes-capacidade_aeronave
            cont_overbooking += 1
            #print(f"Quantos passageiros ficaram sobrando: {passageiros_excedentes}")
        else:
            passageiros_excedentes = 0
        
        for k in range(passageiros_excedentes):

            eh_voluntariado = random.choices([True, False], weights=[0.25, 0.75])[0]

            if eh_voluntariado:
                custo_compensacao += 1000
                cont_volunatriados += 1
            else:
                custo_compensacao += 2500
                cont_forcados += 1

        

print(f"Total de OverBooking: {cont_overbooking}")
print(f"Taxa média de overbooking {cont_overbooking/qtd_dias}\n\n")

print(f"Total de passageiros Exedentes: {total_passageiros_excedentes}")
print(f"Total Volunarios {cont_volunatriados}")
print(f"Total Forcados {cont_forcados}\n\n")

print(f"Custo total: {custo_compensacao}\n")

print(f"Media de custo por dia {custo_compensacao/qtd_dias}")

print(f"Realocados voluntariamente: {cont_volunatriados} / Realocados forcadamente: {cont_forcados}")