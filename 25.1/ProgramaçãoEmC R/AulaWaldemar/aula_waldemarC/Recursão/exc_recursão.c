#include <stdio.h>


//Fatorial

int fatorial(int a){

    if(a == 0){
        return 1;
    }
    else{

        return a * fatorial(a-1);

    }
}


int mdc(int a, int b){ //Máximo divisor comum é o maior número que divide dois números. Nesse caso o resto de a/b tem que ser dividido por b até que o resto seja 0.

    if(b==0){
        return a;
    }
    else{
        return mdc(b, a%b);
    }
}


int loop(int n){ /*Loop que ajuda a deixar a sequencia de fibonacci na ordem*/

    for(int i = 0; i <= n; i++){
        printf("%d ", fibonacci(i));
    }

}

int fibonacci(int n){

    if(n==0){
        return 0;
    }
    else if(n==1){
        return 1;
    }
    else{
        int a =  fibonacci(n-1) + fibonacci(n-2);
        return a;
    }
}


int main(void){

    int n = 4;

    loop(n);

    return 0;

}