def lcg(x0, a, c, M, n):
    """
    Gerador Congruente Linear (LCG).
    Recebe a semente x0 e os parametros a, c, M, e devolve uma lista
    com n valores u_k (uniformes entre 0 e 1).
    """
    x = x0
    valores = []
    for _ in range(n):
        x = (a * x + c) % M      # gera o proximo inteiro "pseudo-aleatorio"
        u = x / M                # normaliza para o intervalo [0, 1)
        valores.append(u)
    return valores


# a) Supondo que em uma determinada partida do jogo 10 novos personagens precisam ser criados, utilize o algoritmo
#    LCG, com os parâmetros fornecidos, para definir aleatoriamente as características de cada um.

class Personagem:

    def __init__(self, forca, agilidade, inteligencia):
        self.forca = forca  # Atributo de instância
        self.agilidade = agilidade  # Atributo de instância
        self.inteligencia = inteligencia

    forca: int
    agilidade: int
    inteligencia: int 

a = 39373
c = 0
M = ((2**31) - 1)
x_0 = 3

personagens:list[Personagem]

for i in range(10):

    
    


        
    forca = lcg(a,c,M,x_0)

    personagem = Personagem()