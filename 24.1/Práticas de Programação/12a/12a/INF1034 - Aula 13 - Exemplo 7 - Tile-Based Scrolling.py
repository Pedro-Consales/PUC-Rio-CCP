# Exemplo 7 - Tile-based Scrolling

# Use as teclas de setas para direita e esquerda para mover o mapa
import pygame
import math

tile_size = 64
width = tile_size * 14 
height = tile_size * 10
mapa = []
tile_quads = []
tiles_pattern = ["G", "F", "B", "T", "R", "B", "A", "P", "S"]

mapa_config = {   #configurações do tamanho da fase
    "mapaSize_x": 28,
    "mapaSize_y": 10,
    "mapaDisplay_x": 14,
    "mapaDisplay_y": 10
}

camera = {        #posição da camera
    "pos_x": 0,
    "pos_y": 0,
    "speed": 0.120
}

def load_mapa(filename):
    global mapa
    file = open(filename,"r")
    i = 0    
    for line in file.readlines():
        mapa.append(line)
    file.close()

def load_tiles(filename, nx, ny):
    global tileset_image, tile_quads
    tileset_image = pygame.image.load(filename)
    for i in range(nx):
        for j in range(ny):
            tile_quads.append((i * tile_size , j * tile_size, tile_size, tile_size))

def load():
    global clock, plataform_tileset
    clock = pygame.time.Clock() 
    load_mapa("platform_map.txt")
    load_tiles("platform_tileset.png", 3, 3)

def update(dt):
    global camera
    keys = pygame.key.get_pressed()
    #movimenta a camera
    if keys[pygame.K_RIGHT]:
        camera["pos_x"] = camera["pos_x"] + (camera["speed"] * dt)
    elif keys[pygame.K_LEFT]:
        camera["pos_x"] = camera["pos_x"] - (camera["speed"] * dt)

    #verifica os limites da fase e trava a camera
    if camera["pos_x"] < 0: 
        camera["pos_x"] = 0
    elif camera["pos_x"] > (mapa_config["mapaSize_x"] - mapa_config["mapaDisplay_x"]) * tile_size:
        camera["pos_x"] = (mapa_config["mapaSize_x"] - mapa_config["mapaDisplay_x"])  * tile_size

def draw_screen(screen):
    screen.fill((152,209,250))
    offset_x = math.floor(camera["pos_x"] % tile_size)
    first_tile_x = math.floor(camera["pos_x"] / tile_size)
    range_x = mapa_config["mapaDisplay_x"]

    # antes do fim da fase - mostrar um tile a mais
    if first_tile_x != mapa_config["mapaSize_x"] - mapa_config["mapaDisplay_x"]:
        range_x = mapa_config["mapaDisplay_x"] + 1

    for y in range(mapa_config["mapaDisplay_y"]):
        for x in range(range_x):
            if mapa[y][x + first_tile_x] in tiles_pattern:
                pos = ((x * tile_size) - offset_x,(y * tile_size))
                pattert_index = tiles_pattern.index(mapa[y][x + first_tile_x])
                screen.blit(tileset_image, pos, tile_quads[pattert_index])



# ... programa principal


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