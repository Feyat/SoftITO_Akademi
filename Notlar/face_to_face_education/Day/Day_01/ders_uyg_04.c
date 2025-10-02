#include <stdio.h>
#include <time.h>
#include <stdlib.h>



void display(int *ptr, int boyut){
    int i = 0;
    while(i<boyut){
        *(ptr+i) = rand()%100+1;
        i++;
    }
}

int main(){
    srand(time(NULL));
    int a[10] = {2, 4, 6, 8, 10, 12, 14, 16, 18, 20};
    int boyut = sizeof(a)/sizeof(a[0]);
    int *ptr = a;
    display(ptr, boyut);
    for(int i=0;i<boyut;i++){
        printf("%d ", a[i]);
    }
}