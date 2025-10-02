
#include <stdio.h>

#define    SIZE    10


int main(){
    int a[10] = {2, 4, 6, 8, 10, 12, 14, 16, 18, 20};
    int b[10] = {1, 3, 5, 7, 9, 11, 13, 15, 17, 19}; 
    int *ptr = a;

    for(int i = 0; i<SIZE; i++){
        printf("%d ", *(ptr+i));
    }
}