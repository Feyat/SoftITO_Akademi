/*

https://cppcon.org/
    Bjarne Stroustrup --> C++ Programming Language, The : Stroustrup, Bjarne:

*/

#include <stdio.h>

void max_min_find(const int *ptr, int *p_max, int *p_min, size_t size){
    for(int i=0;i<size;i++){
        if(*(ptr+i) < *p_min)
            *p_min = *(ptr+i);
        else if(*(ptr+i) > *p_max)
            *p_max = *(ptr+i);
    }
}

int main(){
    int array[6]= {1, 6, 3, 4, 5, };
    size_t size = 0;
    int max;
    int min;

    size = sizeof(array) / sizeof(array[0]);
    max_min_find(array, &max, &min, size);
    printf("Array pmax = %d \nArray pmin = %d", max, min);
}