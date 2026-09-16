set.seed(123)

n_exec <- 10000

qtd_EE <- 25
qtd_SE <- 20
qtd_CE <- 15
qtd_ALI <- 12
qtd_AIE <- 8


cont_PF_total <- 0
cont_semanas_total <- 0
cont_custo_total <- 0
cont_menor_que_280mil <- 0
cont_menor_que_60semanas <- 0
for(k in 1:n_exec){

    soma_EE <- 0
    for(k in 1:qtd_EE){
        prob_complexidade <- sample(c(3,4,6), size = 1, prob = c(0.3,0.5,0.2))
        soma_EE <- soma_EE + prob_complexidade
    }

    soma_SE <- 0
    for(k in 1:qtd_SE){
        prob_complexidade <- sample(c(4,5,7), size = 1, prob = c(0.25,0.60,0.15))
        soma_SE <- soma_SE + prob_complexidade
    }

    soma_CE <- 0
    for(k in 1:qtd_CE){
        prob_complexidade <- sample(c(3,4,6), size = 1, prob = c(0.4,0.4,0.2))
        soma_CE <- soma_CE + prob_complexidade
    }


    soma_ALI <- 0
    for(k in 1:qtd_ALI){
        prob_complexidade <- sample(c(7,10,15), size = 1, prob = c(0.2,0.5,0.3))
        soma_ALI <- soma_ALI + prob_complexidade
    }

    soma_AIE <- 0
    for(k in 1:qtd_AIE){
        prob_complexidade <- sample(c(5,7,10), size = 1, prob = c(0.35,0.45,0.20))
        soma_ALI <- soma_ALI + prob_complexidade
    }

    soma_PF_naoajustado <- soma_EE + soma_SE + soma_CE + soma_ALI + soma_AIE
    
    print(paste("PF NÃO ajustado: ", soma_PF_naoajustado))
    

    fa <- sample(c(1.05, 1.15, 1.25), size = 1, prob = c(0.2, 0.6, 0.2))

    print(paste("FA: ", fa))

    PF <- soma_PF_naoajustado * fa 

    produtividade <- sample(c(4,5,6), size = 1, prob = c(0.2, 0.6, 0.2))

    print(paste("Produtividade: ", produtividade))

    custo_hora <- sample(c(80,100,120), size = 1, prob=c(0.2, 0.6, 0.2))

    print(paste("Custo/Hora", custo_hora))

    qtd_hotas_total = produtividade * PF
    semanas = qtd_hotas_total/40

    cont_PF_total <- cont_PF_total + PF
    cont_semanas_total <- cont_semanas_total + semanas

    custo_total_sistema <- custo_hora * qtd_hotas_total
    cont_custo_total <- cont_custo_total + custo_total_sistema

    if(custo_total_sistema < 280000){
        cont_menor_que_280mil <- cont_menor_que_280mil + 1
    }

    if(semanas < 60){
        cont_menor_que_60semanas <- cont_menor_que_60semanas + 1
    }
    
    print("\n\n")
}

  print("\n\n\n\n ========= \n\n\n\n")

print(paste("Valor médio PF: ", (cont_PF_total/n_exec), "\n" ))
print(paste("Tempo médio em semanas: ", (cont_semanas_total/n_exec), "\n"))
print(paste("Custo médio do sistema: ", (cont_custo_total/n_exec), "\n"))
print(paste("Probalidade custo ser < 280.000,00: ", (cont_menor_que_280mil/n_exec), "\n"))
print(paste("Probalidade qtd de semanas < 60: ", (cont_menor_que_60semanas/n_exec), "\n"))
