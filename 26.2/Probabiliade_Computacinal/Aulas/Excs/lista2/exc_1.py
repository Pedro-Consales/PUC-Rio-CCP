# Em todos os exercícios utilize 123 como semente.
# 1) Uma empresa de software realizou a contagem não ajustada de 3500 pontos de função para um sistema a ser
# desenvolvido. Como parte do processo de Análise de Pontos de Função (APF), o valor deve ser ajustado conforme as
# 14 características gerais do sistema, que recebem notas de 0 a 5.
# O Fator de Ajuste (FA) é dado por:
# 𝐹𝐴 = 0.65 + 0.01 × 𝑆𝑜𝑚𝑎 𝑑𝑎𝑠 14 𝑐𝑎𝑟𝑎𝑐𝑡𝑒𝑟í𝑠𝑡𝑖𝑐𝑎𝑠
# e o total de Pontos de Função (PF) ajustado é dado por:
# 𝑃𝐹𝑎𝑗𝑢𝑠𝑡𝑎𝑑𝑜 = 𝑃𝐹𝑛ã𝑜−𝑎𝑗𝑢𝑠𝑡𝑎𝑑𝑜 × 𝐹𝐴
# As características do sistema não são conhecidas com certeza e, por isso, foram atribuídas probabilidades fixas para
# cada uma delas:
# • Distribuição de dados: 2 (20%), 3 (60%), 4 (20%)
# • Requisitos de desempenho: 3 (10%), 4 (70%), 5 (20%)
# • Reusabilidade: 1 (10%), 2 (70%), 3 (20%)
# • Complexidade de processamento: 2 (10%), 3 (60%), 4 (20%), 5 (10%)
# • Outras 10 características: 1 (20%), 2 (60%), 3 (20%)
# Além disso, há incerteza nos parâmetros de produtividade e custo:
# • Produtividade (h/PF): 4h (20%), 5h (70%), 6h (10%)
# • Custo por hora (R$): 80 (20%), 100 (60%), 120 (20%)
# Com base no que foi exposto e usando simulação (10.000 execuções), pede-se:
# a) O valor médio esperado de 𝑃𝐹𝑎𝑗𝑢𝑠𝑡𝑎𝑑𝑜.
# b) O tempo médio em semanas (40h/semana) para o desenvolvimento.
# c) O custo médio do sistema.
# d) A probabilidade de o custo ser menor que R$ 1.500.000,00.
# e) A probabilidade de o tempo ser menor que 450 semanas.
# f) Represente graficamente, por histogramas, as distribuições simuladas de 𝑃𝐹𝑎𝑗𝑢𝑠𝑡𝑎𝑑𝑜, tempo (semanas) e custo (R$).




import random
import numpy as np
# import matplotlib.pyplot as plt

random.seed(123)

MOSTRAR_DETALHES = False  # True -> imprime as 3 primeiras iteracoes para conferir os calculos

def FA(soma_das_notas: int) -> float:
    return 0.65 + (0.01 * soma_das_notas)

def PF_AJUSTADO(PF_nao_ajustado, fator_de_ajuste):
    return PF_nao_ajustado * fator_de_ajuste


valor_total_pf_ajustado = 0
cont_semanas_pTermino = 0
cont_custoTotal = 0
cont_custo_menor_que_1M_500MIL = 0
cont_menor_que_450_semanas = 0

# Listas com os 10.000 valores individuais -> sao elas que alimentam os histogramas do item (f).
# Os acumuladores acima guardam so a soma, e com a soma nao da para desenhar uma distribuicao.
lista_pf_ajustado = []
lista_semanas = []
lista_custos = []


n_execucoes = 10000
notas_possiveis = [1, 2, 3, 4, 5]
horas_possiveis = [4, 5, 6]
custos_possiveis = [80, 100, 120]
for i in range(n_execucoes):

    detalhar = MOSTRAR_DETALHES and i < 3  # sem isso seriam 10.000 blocos de print
    if detalhar: print("\n\n=======\n\n")

    distribuicao_dados = random.choices(notas_possiveis, weights=[0, 0.2, 0.6, 0.2, 0])[0]
    requisitos_desempenho = random.choices(notas_possiveis, weights=[0, 0, 0.1, 0.7, 0.2])[0]
    reusabilidade = random.choices(notas_possiveis, weights=[0.1, 0.7, 0.2, 0, 0])[0]
    complexidade_processamento = random.choices(notas_possiveis, weights=[0, 0.1, 0.6, 0.2, 0.1])[0]

    notas = [distribuicao_dados, requisitos_desempenho, reusabilidade, complexidade_processamento]

    for j in range (10):
        outra_funcionalidade = random.choices(notas_possiveis, weights=[0.2, 0.6, 0.2, 0, 0])[0]
        notas.append(outra_funcionalidade)

    soma_notas_funcionalidades:int = sum(notas)
    if detalhar: print(f"Soma notas funcionalidaes: {soma_notas_funcionalidades}\n") #Obs: A soma máxima possível é 47 e a minima é 18 então o valor tem que ficar nessa faixa. A faixa mais comum que deve aparecer é ~32

    FatorAjuste:float = FA(soma_notas_funcionalidades)
    PF_ajustado:float = PF_AJUSTADO(3500, FatorAjuste) #3500 vem da questão que fala que o Pf nao ajustado é 3500


    valor_total_pf_ajustado += PF_ajustado
    if detalhar:
        print("===")
        print(f"FA: {FatorAjuste}")
        print(f"PF AJUSTADO: {PF_ajustado}") #-> Só para ver se estava calculando certo (Está!)
        print("===\n\n")
        print("===")

    # AGORA AQUI EU VOU COMECAR A CALUCLAR PRODUTIVIDADE E CUSTO
    horas_por_PF = random.choices(horas_possiveis, weights=[0.2, 0.7, 0.1])[0] #horas por ponto de funcao. Ou seja se 4 horas -> 4 hroas - 1 PF / 8 horas - 2 PF ...
    #print(f"Horas por PF {horas_por_PF}")
    horas_totais_para_terminar_PF = horas_por_PF * PF_ajustado
    if detalhar: print(f"Horas totais para terminar os PF: {horas_totais_para_terminar_PF}")
    semanas_para_terminar = horas_totais_para_terminar_PF/40 # dividio por 40 pq 40 horas equivales a uma semana de trabalho
    if(semanas_para_terminar < 450):
        cont_menor_que_450_semanas += 1
    if detalhar: print(f"Semanas totais para terminar os PF: {semanas_para_terminar}")
    cont_semanas_pTermino += semanas_para_terminar


    valor_custo_hora = random.choices(custos_possiveis, weights=[0.2, 0.6, 0.2])[0]
    if detalhar: print(f"Valor Custo por Hora: {valor_custo_hora}")

    custo_total = valor_custo_hora*horas_totais_para_terminar_PF
    if(custo_total < 1500000):
        cont_custo_menor_que_1M_500MIL +=1
    cont_custoTotal += custo_total
    if detalhar:
        print(f"Custo total para terminar nas determinadas horas: {custo_total}")
        print("===")

    # guarda os valores desta iteracao para os histogramas
    lista_pf_ajustado.append(PF_ajustado)
    lista_semanas.append(semanas_para_terminar)
    lista_custos.append(custo_total)


print("\n\nResultados =========== \n ")

media_pf = valor_total_pf_ajustado/n_execucoes
media_semanas = cont_semanas_pTermino/n_execucoes
media_custo = cont_custoTotal/n_execucoes
prob_custo = (cont_custo_menor_que_1M_500MIL/n_execucoes)*100
prob_tempo = (cont_menor_que_450_semanas/n_execucoes)*100

print(f"Valor médio PF ajustado: {media_pf}")
print(f"Tempo média em semanas: {media_semanas}")
print(f"Custo medio: {media_custo}")
print(f"Probabilidade de ser menor que 1.500.000: {prob_custo}%")
print(f"Probabiliade do tempo ser menor que 450 semanas: {prob_tempo}%")


# # ============================================================
# # f) HISTOGRAMAS
# # ============================================================
# # Um histograma pega a lista com os 10.000 valores, divide o intervalo em faixas ("bins")
# # e desenha uma barra cuja altura e quantos valores cairam em cada faixa.
# # Ou seja: mostra a DISTRIBUICAO inteira, e nao so a media dos itens (a), (b) e (c).

# # uma figura com 3 graficos lado a lado (1 linha x 3 colunas)
# fig, (ax_pf, ax_tempo, ax_custo) = plt.subplots(1, 3, figsize=(16, 5))
# fig.suptitle("Simulação APF — 10.000 execuções (semente 123)", fontsize=14)

# # --- PF ajustado ---
# # O PF ajustado so pode dar valores de 35 em 35 (3500 x 0.01 por ponto na soma das notas),
# # entao os bins sao alinhados nesse passo: cada barra = exatamente um valor possivel.
# # Com bins genericos apareceriam barras vazias intercaladas, o famoso efeito "pente".
# bins_pf = np.arange(min(lista_pf_ajustado) - 17.5, max(lista_pf_ajustado) + 35, 35)
# ax_pf.hist(lista_pf_ajustado, bins=bins_pf, color="#4C78A8", edgecolor="white")
# ax_pf.axvline(media_pf, color="black", linestyle="--", label=f"média = {media_pf:.1f}")
# ax_pf.set_title("(a) PF ajustado")
# ax_pf.set_xlabel("Pontos de Função ajustados")
# ax_pf.set_ylabel("Frequência (nº de execuções)")
# ax_pf.legend()

# # --- Tempo em semanas ---
# # A linha vermelha e o limite do item (e): tudo a ESQUERDA dela sao os 88,72%.
# ax_tempo.hist(lista_semanas, bins=40, color="#54A24B", edgecolor="white")
# ax_tempo.axvline(media_semanas, color="black", linestyle="--", label=f"média = {media_semanas:.1f}")
# ax_tempo.axvline(450, color="red", linewidth=2, label=f"450 sem. → {prob_tempo:.2f}% à esquerda")
# ax_tempo.set_title("(b) Tempo de desenvolvimento")
# ax_tempo.set_xlabel("Semanas (40h/semana)")
# ax_tempo.set_ylabel("Frequência (nº de execuções)")
# ax_tempo.legend()

# # --- Custo ---
# # Mesma ideia: a linha vermelha e o limite do item (d), R$ 1.500.000.
# ax_custo.hist(lista_custos, bins=40, color="#E45756", edgecolor="white")
# ax_custo.axvline(media_custo, color="black", linestyle="--", label=f"média = R$ {media_custo:,.0f}")
# ax_custo.axvline(1_500_000, color="red", linewidth=2, label=f"R$ 1,5 mi → {prob_custo:.2f}% à esquerda")
# ax_custo.set_title("(c) Custo do sistema")
# ax_custo.set_xlabel("Custo (R$)")
# ax_custo.set_ylabel("Frequência (nº de execuções)")
# ax_custo.legend()

# plt.tight_layout()
# plt.savefig("exc_1_histogramas.png", dpi=150)  # salva a imagem para colar no trabalho
# print("\nHistogramas salvos em exc_1_histogramas.png")
# plt.show()  # abre a janela com os graficos