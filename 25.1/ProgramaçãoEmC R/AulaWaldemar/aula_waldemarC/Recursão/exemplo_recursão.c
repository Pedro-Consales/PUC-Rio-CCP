#include <stdio.h>


void fun(int n){

    if(n>=0){
        printf("%d ",n);
        fun(n-1);
    }
    return;
}

void func1(int n){

    if(n>=0){
        printf("%d ",n);
        func1(n-1); /*depois da chamada da função tudo aparece junto pois estamos chamando a função novamente então ele não chega até o pritf("* ")*/
        printf("* ");
    }
    return;
}

void func2(int n){

    if(n>=0){
        printf("%d ",n);
        printf("* ");
        func2(n-1); 
    }
    return;
}

void func3(int n){

    if(n>=0){
        func3(n-1);
        printf("%d ",n); /*[  [  [  [  [    ] 0 ] 1 ] 2 ] 3 ]4 */
    }
    return;
}

int main(void){

    int n = 4;

    fun(n);

    printf("\n");

    func1(n);

    printf("\n");

    func2(n);

    printf("\n");

    func3(n);

}