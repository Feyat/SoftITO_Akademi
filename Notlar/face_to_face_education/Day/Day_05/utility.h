#ifndef UNTITLED_UTILITY_H


#define UNTITLED_UTILITY_H
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
void printarray(const int *pa, int size){
    while(size--)
        printf("%d ", *pa++);
    
}

void bp(uint8_t val);

#endif //UNTITLED_UTILITY_H