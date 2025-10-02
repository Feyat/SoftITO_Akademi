// Ders Uygulamaları 

#include <stdio.h>

/*
int main(){
    int x = 10, y = 30;
    int *ptr = &x;

    *ptr = 20;    // ptr x gösteriyor  *ptr x'in kendisine erişmiş oluyorum

    ptr = &y;
    *ptr = 300;
    printf("x = %d, y = %d, ptr = %d", x, y, *ptr);
}

*/

/*
int main(){
    int x = 10, y = 20, z = 30;
    int *p1 = &x, *p2 = p1, *p3 = p2;
    
    ++*p1;
    ++*p2;
    ++*p3;
    // ptr x gösteriyor  *ptr x'in kendisine erişmiş oluyorum.

    printf("x = %d, y = %d, z = %d", x, y, z);
}

int main(){
    int a[5] = {3, 6, 9, 12, 15};
    int *ptr = a;
    // ptr x gösteriyor  *ptr x'in kendisine erişmiş oluyorum.

    *ptr = 30;
    ptr++;
    *ptr = 50;
    
    for(int i =0;i<5; i++){
        printf("%d\n", a[i]);
    }
}




// call by value
void foo(int x){
    x = 200;
}

// call by referance
void bar(int *x){
    *x = 100;
}

int main(){
    int x = 500;
    foo(x);
    printf("x = %d\n", x);

    bar(&x);
    printf("x = %d\n", x);
    return 0;
}

*/


/*

    Dairenin alanını hesaplayan function yaz.

*/


#define  PI   3.1415

int circleArea(int r){
    double alan;
    alan = PI*(r*r);
    return alan;
}

int main(){
    int r;

    printf("Alanı öğrenmek istediğiniz dairenin yarıçapını giriniz: ");
    scanf("%d", &r);

    printf("alan = %ld \n", circleArea(r));
}

/*

    İki fonksiyonu swap eden function yaz.

*/


void swap(int *x, int *y){
    
    int temp = *x;
    *x = y; 
    y = temp;
    
}

int main(){
    

    int x = 20, y = 10;
    int temp;
    swap(&x, &y);

    printf("x = %d, y = %d\n", x, y);

    //  Murat Hazıroğlu --> murat@murat.gen.tr


}

#define  PI   3.1415

void circleAreaPerimeter(int r, double *area, double *perimeter){
    *area = PI*(r*r);
    *perimeter = PI*r*2;
}

int main(){
    int r;
    double *area;
    double *perimeter;

    printf("Alanı öğrenmek istediğiniz dairenin yarıçapını giriniz: ");
    scanf("%d", &r);

    circleAreaPerimeter(r , &area, &perimeter);

    printf("area = %p, perimeter= %p", area, perimeter);
}


void swap(int *x, int *y){
    int temp = *x;
    *x = *y;
    *y = temp;
}

int main(){
    int a[10] = {2, 4, 6, 8, 10, 12, 14, 16, 18, 20};
    int b[10] = {1, 3, 5, 7, 9, 11, 13, 15, 17, 19}; 

    int *ptr = a;

    swap(a, b);
}

/*

    Pointer aritmetiği

*/

#define    SIZE    10


void swap(int *x, int *y){
    int temp = *x;
    *x = *y;
    *y = temp;
}

int main(){
    int a[10] = {2, 4, 6, 8, 10, 12, 14, 16, 18, 20};
    int b[10] = {1, 3, 5, 7, 9, 11, 13, 15, 17, 19}; 

    // int *ptr = a;

    // swap(a, b);
    int *ptr = a+3;
    *ptr = 300;
    ++ptr;
    *ptr = 200;
    ptr = b + SIZE -3;
    *ptr = 500;
    ++ptr;
    *ptr = 1000;

    for(int i = 0; i<SIZE; i++){
        printf("%d ", a[i]);
    }

     for(int i = 0; i<SIZE; i++){
        printf("%d ", b[i]);
    }

}

#include <stdio.h>


#define  PI   3.1415

void circleAreaCevre(int r, double *area, double *cevre){
    *area = PI*(r*r);
    *cevre = PI*r*2;
}

int main(){
    int r;
    double area, cevre; 

    printf("Alanini ve cevresini ögrenmek istediginiz dairenin yaricapini giriniz: ");
    scanf("%d", &r);
    r = 3;

    circleAreaCevre(r , &area, &cevre);
    printf("%f %f", area, cevre);
}


/*

    Değişken eleman sayısına sahip bir diziyi yazan function yazınız.
    Herhangi bir diziyi alıp display eden fonksiyonu yazınız.

*/

#include <stdio.h>

void display(const int *ptr, int boyut){
    for(int i=0;i<boyut;i++){
        printf("%d ", *(ptr+i));
    }
}

int main(){

    int a[10] = {2, 4, 6, 8, 10, 12, 14, 16, 18, 20};
    int boyut = sizeof(a)/sizeof(a[0]);
    int *ptr = a;
    display(ptr, boyut);
}


/*

    While yapma...

*/
#include <stdio.h>

void display(const int *ptr, int boyut){
    int i = 0;
    while(i<boyut){
        printf("%d ", *(ptr+i));
        i++;
    }
}

int main(){

    int a[10] = {2, 4, 6, 8, 10, 12, 14, 16, 18, 20};
    int boyut = sizeof(a)/sizeof(a[0]);
    int *ptr = a;
    display(ptr, boyut);
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