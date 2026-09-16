teto = 5000
piso = 1000

buff_num = piso

# lista_buff_num = [2345, 1005, 2525, 4233]
# buff_num = 2345

is_mult_5 = False
has_algarismos = True


cont_satisfeitos = 0

while(buff_num <= teto):
# while(i<len(lista_buff_num)):

    # buff_num = lista_buff_num[i]
    print(buff_num)
    if (buff_num % 5 == 0):
        is_mult_5 = True
    else:
        print("Deu merda! Não é multiplo")

    print(f"É divisível por 5?: {is_mult_5}")

    str_buff_num = str(buff_num)
    print(f"Transformando em str: {str_buff_num} - {type(str_buff_num)}")
    for algarismo in str_buff_num:
        print(f"Algarismo da vez: {algarismo}")
        if(algarismo == '2' or algarismo == '3' or algarismo == '4' or algarismo == '5'):
            has_algarismos = True
            print("Tem o algarismo")
            continue

        has_algarismos = False
        print("Deu merda! Não tem o algarismo")
        break


    if has_algarismos and is_mult_5:
        cont_satisfeitos += 1
        print(f"Satisfeitos até agora: {cont_satisfeitos}")

    buff_num += 1
    has_algarismos = False
    is_mult_5 = False




print(f"cont satisfeitos: {cont_satisfeitos}")

