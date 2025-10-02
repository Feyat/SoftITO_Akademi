#include <stdio.h>

int main(){
    int x = 163;
    x |= (1<<4);
    x |= (1<<3);
    x |= (1<<2);
    x ^= ~(1<<1);
    x ^= ~(1<<0);
    printf("%d ", x);
}