#include <stdio.h>
#include <stdlib.h>



int main(void){

    int **v;


    v = (int**)malloc(3*sizeof(int*));

    for(int i = 0; i < 3; i++){

        *v[i] = (int*)malloc(3*sizeof (int));
    }

    return 0;

}
