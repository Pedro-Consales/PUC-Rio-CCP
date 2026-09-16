

cont_distintos = 0

i = 0
while(i <= 999):

    found_iguais = False
    algarismos_distintos = False
    print(f"Numero da vez: {i}\n")
    if(i/100 < 1): #Caso que não tem 3 algarismos
        print("Não tem 3 algarismos\n")
        i+=1
        continue

    print(f"Tem 3 algarismos: \n\n")

    numero_str = str(i)
    print(f"Numero a ser verificado {numero_str} - {type(numero_str)}\n")

    algarismos_distintos = True 
    for j in range(len(numero_str)):
        algarismo = numero_str[j]
        print(f"Algarismo j({j})): {algarismo}\n\n")

        for k in range(len(numero_str)):
            numero_atual = numero_str[k]
            print(f"Algarismo k({k})): {numero_atual}\n\n")

            if algarismo == numero_atual:
                print(f"São iguais")

                if(k == j):
                    print("Mas estão na mesma pos, então é o mesmo numero, pula!")
                    continue
                else:
                    
                    found_iguais = True
                    algarismos_distintos = False
                    print(f"Não estão na mesma pos, incoerente!!! Ecnontrou iguais {found_iguais}")
                    break

        if found_iguais:
            print("Trocando de número já que tem algarismos iguais\n\n\n")
            found_iguais = False
            break
        else:
            algarismos_distintos = True

    if algarismos_distintos:
        print("Os algarismos são distintos\n\n\n")
        cont_distintos +=1


    i+=1
##Código ta meio cagado! ainda tem que filtrar os pares...

print(cont_distintos)

            