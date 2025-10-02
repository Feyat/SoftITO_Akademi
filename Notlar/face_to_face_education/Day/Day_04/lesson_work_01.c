#include <stdio.h>
#include <stdlib.h>
#include <time.h>


void max_min_find(const int *ptr, int *p_max, int *p_min, size_t size){
    *p_max = *ptr;
    *p_min = *ptr;

    for(size_t i=0;i<size; i++){
        if(*(ptr+i) > *p_max)
            *p_max = *(ptr+i);
        else if(*(ptr+i)<*p_min)
            *p_min = *(ptr+i);
    }
}

void swap(int *p_x, int *p_y){
    int temp;
    temp = *p_x;
    *p_x = *p_y;
    *p_y = temp;
}

void sum_array(const int *ptr, int *sum, size_t size){
    for(size_t i=0;i<size; i++)
        *sum += *(ptr+i);
}

void random_array(int *ptr, size_t size){
    srand(time(NULL));
    for(size_t i = 0; i<size; i++)
        *(ptr+i) = rand()%100+1;
}

int main(){
    int array[8] = {1, 43, 34, 23, 654, 2323, 454, 34};
    int r_array[10] = {0};
    int *ptr = array;
    int max, min, sum; 
    size_t size = sizeof(array)/sizeof(array[0]);
    size_t r_size = sizeof(r_array)/sizeof(r_array[0]);
    max_min_find(ptr, &max, &min, size);
    printf("Array max = %d, Array min = %d", max, min);

    int x = 20, y = 34;
    printf("\nX sayısı = %d, Y sayısı = %d", x, y);
    swap(&x, &y);
    printf("\nX sayısı = %d, Y sayısı = %d", x, y);

    sum_array(ptr, &sum, size);

    printf("\nArray sum = %d\n", sum);

    for(size_t i=0;i<r_size;i++)
        printf("%d ", r_array[i]);
    printf("\n");
    random_array(r_array, r_size);

    for(size_t i=0;i<r_size;i++)
        printf("%d ", r_array[i]);
    
}




