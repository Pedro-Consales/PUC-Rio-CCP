import random
from time import sleep
# 5) Em um campeonato, um programador é desafiado a criar um programa que simule o comportamento do Pac-Man
# em um labirinto simples com 11 linhas e 11 colunas. O objetivo é determinar a probabilidade do Pac-Man coletar toda
# as pastilhas (pontos) antes de ser capturado por um fantasma. A cada partida o Pac-Man começa no canto superior
# esquerdo (posição [1,1] ou melhor [0][0] na lista) e seu objetivo é coletar todas as 4 pastilhas espalhadas aleatoriamente (duas pastilhas não
# podem ocupar o mesmo lugar) pelo labirinto. 

# Existem 3 fantasmas em movimento que começam em posições fixas
# (canto superior direito, canto inferior esquerdo, posição oposta ao Pac-Man) e patrulham o labirinto de maneira
# aleatória. Regras do Jogo: em cada passo, Pac-Man pode se mover para uma das quatro direções (cima, baixo,
# esquerda ou direita, com a mesma probabilidade), desde que não ultrapasse os limites do labirinto; pastilhas não
# podem ocupar a posição [1,1]; Pac-Man coleta uma pastilha ao entrar na célula onde a pastilha está localizada; cada
# fantasma também se move aleatoriamente seguindo as mesmas regras de movimentação do Pac-Man; um fantasma
# pode ocupar a mesma célula de uma pastilha ou de outro fantasma; Pac-Man é capturado se um fantasma entrar na
# mesma célula em que Pac-Man está; a partida termina quando Pac-Man coleta todos as pastilhas (prioridade sobre a
# captura do Pac-Man pelos fantasmas) ou é capturado por um fantasma. Usando simulação (1.000 execuções e
# semente 123) estime a probabilidade de vitória do Pac-Man.

#pac man = 1
#pastilha = 2
#fantasma = 3
#espaço vazio = 0

def andaPacman(pacman):

    while True:
        direcoes = ["U","D","L","R"]

        direcao_escolhida = random.choice(direcoes)
        print(f"\n\nPacman anda para a direção {direcao_escolhida}:{type(direcao_escolhida)}\n")

        linha = pacman[0]
        coluna = pacman[1]
        print(f"posição antiga {pacman}") 

        if direcao_escolhida == "D":
            linha += 1
        elif direcao_escolhida == "U":
            linha -= 1
        elif direcao_escolhida == "L":
            coluna -= 1
        elif direcao_escolhida == "R":
            coluna += 1
            
        print(f"---- candidato a posicao nova [{linha},{coluna}]\n")
        if (linha >= 1 and linha <= 11) and (coluna >= 1 and coluna <= 11): #Se está dentro dos valores permitidos ai sim faz a troca
            pacman[0] = linha
            pacman[1] = coluna
            print(f"posição é valida -> aletrando, agora pacman é {pacman}\n\n")
            return
        print("posição é inválida. buscando outra..\n\n")



def andaFantasma(fantasmas):
    for fantasma in fantasmas:

        print(f"\n\nFantasma atual: {fantasma}")

        while True:
            direcoes = ["U","D","L","R"]
        
            direcao_escolhida = random.choice(direcoes)
            print(f"Fantasma anda para a direção {direcao_escolhida}:{type(direcao_escolhida)}\n")

            linha = fantasma[0]
            coluna = fantasma[1]
            print(f"posição antiga {fantasma}")

            if direcao_escolhida == "D":
                linha += 1
            elif direcao_escolhida == "U":
                linha -= 1
            elif direcao_escolhida == "L":
                coluna -= 1
            elif direcao_escolhida == "R":
                coluna += 1

            print(f"---- candidato a posicao nova [{linha},{coluna}]")
            if (linha >= 1 and linha <= 11) and (coluna >= 1 and coluna <= 11): #Se está dentro dos valores permitidos ai sim faz a troca
                print("posição é valida\n\n")
                fantasma[0] = linha
                fantasma[1] = coluna
                print(f"aletrando, agora fantasma é {fantasma}")
                break
            print("posição é inválida. buscando outra..\n\n")



#======= main

random.seed(123)

n_jogadas = 1000


cont_partidas_ganhas = 0
cont_partidas_perdidas = 0
for curr_game_num in range(n_jogadas):

    print(f"Jogo {curr_game_num+1}: \n\n")
    pacman = [1,1]
    fantasmas = [[1,11], [11,1], [11,11]]


    cont_pastilhas = 0
    qtd_pastilhas = 4
    pastilhas = []
    while cont_pastilhas < qtd_pastilhas:

        i = random.randint(1,11)
        j = random.randint(1,11)

        pastilha_atual = [i,j]

        if((i == 1 and j == 1) or (pastilha_atual in pastilhas)): #Está no pac man e então tem que gerar outro numero
            continue

        pastilhas.append(pastilha_atual)

        cont_pastilhas+=1

    venceu = False
    while True:

        andaPacman(pacman)
        andaFantasma(fantasmas)

        if pacman in pastilhas:
            #pegou uma pastilha
            for pastilha in pastilhas:
                if pacman == pastilha:
                    pastilhas.remove(pastilha)
                    #consome a pastilha
                    if not pastilhas:
                        #pastilhas acamabaram
                        print("Venceu o jogo! Comeu todas as patilhs")
                        cont_partidas_ganhas+=1
                        venceu = True

        if venceu:
            break

        if pacman in fantasmas:
            #pedeu o jogo
            print(f"Perdeu o jogo, fantasma capturou")
            cont_partidas_perdidas+=1
            break

        


print(f"probabilidade: {cont_partidas_ganhas / n_jogadas}")

