#include <stdio.h>

#define   ASIZE  3


int main(void){

    int x = 20;
    int y = 30;
    int z = 10;

    int* PArray[ASIZE] = {&x, &y, &z};

    for(int i = 0; i<ASIZE; i++){
   
        printf("%p ", (PArray+i));
        printf("%p \n", *(PArray+i));
    }
}