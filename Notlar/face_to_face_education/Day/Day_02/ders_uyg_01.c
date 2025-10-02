/*

    Bir function oluşturun bir dizideki elemanları rastgele atama yapsın.

*/

#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include "utility.h"

void display(int *ptr, int size){

}

int main(){
    int array[10] = {2, 3, 4, 5, 6, 7, 8, 9, 10, 1};
    int size = sizeof(array) / sizeof(array[0]);
    int *pa = array;
    printarray(pa, size);
    
}

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


/*

    Sum array function yazın.

*/

#include <stdio.h>


int sumArray(const int *ptr, const int size){
    int i = 0;
    int sum = 0;
    while(i<size){
        sum += *(ptr+i);
        i++;
    }
    return sum;
}

int main(){
    int a[10] = {2, 4, 6, 8, 10, 12, 14, 16, 18, 20};
    int size = sizeof(a)/sizeof(a[0]);
    int *ptr = a;
    int sum = sumArray(ptr, size);
    printf("%d", sum);
}

/*

    

*/