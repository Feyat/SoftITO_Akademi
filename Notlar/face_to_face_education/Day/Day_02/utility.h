#ifndef UNTITLED_UTILITY_H


#define UNTITLED_UTILITY_H
#include <stdio.h>
void printarray(const int *pa, int size){
    while(size--)
        printf("%d ", *pa++);
}

#endif //UNTITLED_UTILITY_H