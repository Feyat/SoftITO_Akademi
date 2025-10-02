#include <stdio.h>

#define   ASIZE   10  



void function(char **pa, char size){
    while(size == 0){
        printf("%d ", **pa);
        size--;
        (**pa)++;
    }
}
int main(){

    const char* pa[ASIZE] = {"Kerem", "Ali", "Yakup"};

    function(pa, ASIZE);
}


