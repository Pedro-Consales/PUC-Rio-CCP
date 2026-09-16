import random

n_equipamentos = 1000000


cont_defeito = 0

cont_tem_manutencao = 0
cont_nao_tem_manutencao = 0


cont_tem_defeito_com_manutencao = 0
cont_tem_defeito_sem_manutencao = 0

contC1 = 0
contC3 = 0


for i in range(n_equipamentos):

    c1 = random.choices([True, None], weights=[4/100, 96/100])[0]
    c2 = random.choices([True, None], weights=[4/100, 96/100])[0]

    porcentagem_equipamentos_com_manutencao = 40
    if random.randint(1,100) > porcentagem_equipamentos_com_manutencao:  # 60% de NÃO ter manutenção

        c3 = random.choices([True, None], weights=[6/100, 94/100])[0]
        c4 = random.choices([True, None], weights=[6/100, 94/100])[0]

        if c1 or c2 or c3 or c4:
            cont_tem_defeito_sem_manutencao += 1

        cont_nao_tem_manutencao += 1

    else: #Se teve manutenção a chance de ter defeito c3 e c4 é menor em 50%


        c3 = random.choices([True, None], weights=[3/100, 97/100])[0]
        c4 = random.choices([True, None], weights=[3/100, 97/100])[0]

        if c1 or c2 or c3 or c4:
            cont_tem_defeito_com_manutencao += 1

        cont_tem_manutencao += 1

        if c1:
            contC1 += 1
        if c3:    
            contC3 += 1

    if c1 or c2 or c3 or c4:
        # print("Tivemos um defeito na produção!")
        cont_defeito += 1



print(f"Total de equipamentos COM DEFEITO: {cont_defeito} -> probabilidade: {cont_defeito/n_equipamentos}\n\n")
print(f"Total de equipamentos COM DEFEITO e SEM MANUTENÇÃO: {cont_tem_defeito_sem_manutencao} -> probabilidade: {cont_tem_defeito_sem_manutencao/cont_nao_tem_manutencao}\n\n")
print(f"Total de equipamentos COM DEFEITO e COM MANUTENÇÃO: {cont_tem_defeito_com_manutencao} -> probabilidade: {cont_tem_defeito_com_manutencao/cont_tem_manutencao}\n\n")

print(f"No universo que TEM manutenção, a probabilidade de ter defeito C1 é: {contC1/cont_tem_manutencao}")
print(f"No universo que TEM manutenção, a probabilidade de ter defeito C3 é: {contC3/cont_tem_manutencao}")