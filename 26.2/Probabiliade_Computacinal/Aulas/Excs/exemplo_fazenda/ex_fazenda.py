import random

qtd_testes = 100000
cont_dentro = 0

for i in range(qtd_testes):

    x = random.random()
    y = random.random()

    eq_circuloA = x**2 + y**2 #Tem que estar dentro do círculo A que está centrado na origem (0,0) e tem raio 1 
    eq_circuloC = (x-1)**2 + (y-1)**2 #Tem que estar dentro do círculo B que está centrado no ponto (1,1) e tem raio 1


    if eq_circuloA <= 1 and eq_circuloC <= 1: #Se ambos estão dentro das circunfetencias ao mesmo tempo, então o ponto está na interseção
        print(f"({x},{y}) está na interseção")
        cont_dentro += 1

area_estimada = cont_dentro / qtd_testes

print(f"Área estimada da interseção: {area_estimada}")

#Ele quer prescisa de 200 kg de adubo por kmˆ2 POR MES ou seja a quantidade por mes vai ser
qtd_adubo_por_mes = area_estimada * 200

print(f"Quantidade de adubo necessária por mês: {qtd_adubo_por_mes} kg")

qtd_adubo_por_ano = qtd_adubo_por_mes * 12
print(f"Quantidade de adubo necessária por ano: {qtd_adubo_por_ano} kg")