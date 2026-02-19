#include <stdio.h>


int main(void){

    char operador;

    int n1, n2;

    printf("Digite uma conta (+, -, *, /): ");
    scanf("%d%c%d",&n1, &operador, &n2);

    int resultado;
    if(operador == '+'){
        resultado = n1 + n2;
    }
    else if(operador == '-'){
        resultado = n1 - n2;
    }
    else if(operador == '*'){
        resultado = n1 * n2;
    }
    else if(operador == '/'){
        resultado = n1 / n2;
    }
    else{
        printf("Operador invalido");
        return 1;
    }

    printf("Resultado: %d%c%d = %d",n1,operador,n2, resultado);

    return 0;

    //Ou podemos utilizar o swtichwdnf 

    switch(operador){
        case '+':
            resultado = n1 + n2;
        break;

        case '-':
            resultado = n1 + n2;
        break;

        case '*':
            resultado = n1 + n2;
        break;

        case '/':
            resultado = n1 + n2;
        break;
    }
}