set.seed(123)



p <- list(

    c(0.6,0.3,0.1),

    c(0.2, 0.5, 0.3),

    c(0.1, 0.3, 0.6)
)

estados <- c("E1", "E2", "E3")

estado_atual <- 2 #indicie na lista em R começa em 1 mesmo, diferente do python

freq_estado1 <- 0 
freq_estado2 <- 1 #começa no estado 2
freq_estado3 <- 0

n_exec <- 1000
for(k in 1:n_exec){


    valores_estado_atual <- p[[estado_atual]]

    novo_estado <- sample(estados, size=1, prob = valores_estado_atual)

    if(novo_estado == "E1"){
        estado_atual <- 1
        freq_estado1 = freq_estado1 + 1
    }

    if(novo_estado == "E2"){
        estado_atual <- 2
        freq_estado2 = freq_estado2 + 1
    }

    if(novo_estado == "E3"){
        estado_atual <- 3
        freq_estado3 = freq_estado3 + 1
    }

}

print(freq_estado1)
print(freq_estado2)
print(freq_estado3)