# Exemplo 6 - Textura Atlas Colisão

# Use as teclas WASD para mover o jogador
import pygame, sys
from pygame.locals import QUIT

clock = pygame.time.Clock()
width = 800 
height = 600
tileset = None
pos_x = 0
pos_y = 0
vel = 0.1
mapa_plataforma = [
  "XXXXXXXXXXXXXX",
  "XXXXXXXXXXXXXX",
  "XXXXXXXXXXXXXX",
  "XXXXXXXXXXXXXX",
  "XXXXXXXXXXXXXX",
  "XXXBXXXXXXXXXX",
  "XXBBBXXXXXXXXX",
  "GGGGGGGAAGGGGG",
  "TTTTTTTPPTTTTT",
  "TTTTTTTPPTTTTT",
]


def load():
  global tileset, collider_jogador, collider_mapa
  tileset = pygame.image.load("platform_tileset.png")
  collider_mapa = pygame.Rect(0, 450, 800, 100)

def update(dt):
  global pos_x, pos_y, collider_jogador, vel
  old_x, old_y = pos_x, pos_y

  keys = pygame.key.get_pressed()
  if keys[pygame.K_w]:
    pos_y = pos_y - vel*dt
  elif keys[pygame.K_s]:
    pos_y = pos_y + vel*dt
  elif keys[pygame.K_d]:
    pos_x = pos_x + vel*dt
  elif keys[pygame.K_a]:
    pos_x = pos_x - vel*dt

  collider_jogador = pygame.Rect(pos_x, pos_y, 32, 32)

  if collider_jogador.colliderect(collider_mapa):
    pos_x = old_x
    pos_y = old_y

def draw_screen(screen):
  screen.fill((152,209,250))
  # Mapa plataforma
  for i, linha in enumerate(mapa_plataforma):
    for j, char in enumerate(linha):
      if char == "B":
        screen.blit(tileset, (j*64, i*64), (0, 128, 64, 64))
      elif char == "G":
        screen.blit(tileset, (j*64, i*64), (0, 0, 64, 64))
      elif char == "T":
        screen.blit(tileset, (j*64, i*64), (64, 0, 64, 64))
      elif char == "A":
        screen.blit(tileset, (j*64, i*64), (128, 0, 64, 64))
      elif char == "P":
        screen.blit(tileset, (j*64, i*64), (128, 64, 64, 64))

  # Desenhando o personagem
  pygame.draw.rect(screen, (255, 0, 0), (pos_x, pos_y, 32, 32))
  # Collider personagem
  pygame.draw.rect(screen, (0, 255, 0), (collider_jogador.x, collider_jogador.y, collider_jogador.width, collider_jogador.height), 2)
  # colider mapa
  pygame.draw.rect(screen, (0, 255, 0), (collider_mapa.x, collider_mapa.y , collider_mapa.width, collider_mapa.height), 2)


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