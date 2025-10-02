
#include <stdio.h>

void copyArray(const int *ptr_one, int *ptr_two, int count, const size_t size_array_two){
    
    for(int i=0;i<count;i++)
        *(ptr_two+i) = *(ptr_one+i); 
    for(int i=count;i<size_array_two;i++)
        *(ptr_two+i) = 0; 
    
}

int main(){

    int count = 0;
    int array_one[5] = {1, 2, 3, 4, 5};
    int array_two[5];
    int *ptr_one = array_one;
    int *ptr_two = array_two;

    printf("How many elements do you want to copy from the array one: ");
    scanf("%d", &count);
    
    size_t size_array_two = sizeof(array_two) / sizeof(array_one[0]);
    copyArray(ptr_one, ptr_two, count, size_array_two);
    for(int i=0;i<size_array_two; i++){
        printf("%d ", array_two[i]);
    }
}