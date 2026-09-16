
import random


numrodadas = 1000

jogadores = [
    "Maria",
    "Gustavo",
    "Jorge"
]

qtdMaria = 150
qtdGustavo = 70
qtdJorge = 240

for i in range(numrodadas):

    vendedorRodada = random.choices(jogadores, weights=[0.3, 0.4, 0.3], k=1)[0]

    if vendedorRodada == "Maria":
        qtdMaria += 2
        qtdGustavo -= 1
        qtdJorge -= 1

    elif vendedorRodada == "Gustavo":
        qtdGustavo += 2
        qtdMaria -= 1
        qtdJorge -= 1

    else:
        qtdJorge += 2
        qtdMaria -= 1
        qtdGustavo -= 1

    if qtdMaria == 0 or qtdGustavo == 0 or qtdJorge == 0:
        print(f"Jogo encerrado. Um dos jogadores ficou sem dólares na rodada {i+1}")
        break

print(f"Quantidade final de dólares:")
print(f"Maria: {qtdMaria}")
print(f"Gustavo: {qtdGustavo}")
print(f"Jorge: {qtdJorge}")



