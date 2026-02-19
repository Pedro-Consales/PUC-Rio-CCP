# Exemplo 5 - Mapa com imagens
import pygame
width = 50 * 14 
height = 50 * 10
mapa = []
tile={'0': ((0, 50), (0, 50)), '1': ((150, 200), (50, 100)), '2': ((150, 200), (200, 300))}

def load_mapa(filename):    #Lê o conteúdo do arquivo para a matriz
    global mapa
    file = open(filename,"r")
    for line in file.readlines():
        mapa.append(line)
    file.close()

def load():
    global clock, tile_sand, tile_grass, tile_water, tile
    clock = pygame.time.Clock() 
    load_mapa("mapa.txt")
    tile['0'] = pygame.image.load("sprite.png")
    tile['1'] = pygame.image.load("sprite.png")
    tile['2'] = pygame.image.load("sprite.png")

def update(dt):
    pass

def draw_screen(screen):
    screen.fill((255,255,255))
    for i in range(10): #Percorre a matriz e desenha quadrados coloridos 
        for j in range(14):
            screen.blit(tile[mapa[i][j]], ((j * 50), (i * 50)))

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