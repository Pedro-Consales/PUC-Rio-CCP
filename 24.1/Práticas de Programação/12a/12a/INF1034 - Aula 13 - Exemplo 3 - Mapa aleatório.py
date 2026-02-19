# Exemplo 3 - Mapa aleatório
import pygame
import random

width = 30 * 20  
height = 30 * 14
mapa = []
cor = {'0':(255,0,0), '1':(0,255,0), '2':(0,0,255), '3':(255,255,0)}

def load():
    global clock, mapa
    clock = pygame.time.Clock() 
    for i in range(14):    #Gera aleatoriamente uma matriz 14 x 20 
        mapa.append('')
        for j in range(20):
            mapa[i]+=random.choice('0123')
        print(mapa[i])

def update(dt):
    pass

def draw_screen(screen):
    screen.fill((255,255,255))
    for i in range(14): #Percorre a matriz e desenha quadrados coloridos 
        for j in range(20):
            color = cor[mapa[i][j]]          
            pygame.draw.rect(screen, color, ((j * 30), (i * 30), 30, 30))


#####################################################
# A PRINCIPIO NÃO PRECISA ALTERAR DAQUI PRA BAIXO   #
#####################################################
def main_loop(screen):  
    global clock
    running = True
    while running:
        for e in pygame.event.get(): 
            if e.type == pygame.QUIT: # fechamento do prog
                running = False
                break

        # Define FPS máximo
        clock.tick(60)
        # Tempo transcorrido desde a última atualização 
        dt = clock.get_time()
        # Atualiza posição dos objetos
        update(dt)
        # Desenha objetos
        draw_screen(screen)
        # Pygame atualiza a visualização da tela
        pygame.display.update()

# Programa principal
pygame.init()
screen = pygame.display.set_mode((width, height))
load()
main_loop(screen)
pygame.quit()