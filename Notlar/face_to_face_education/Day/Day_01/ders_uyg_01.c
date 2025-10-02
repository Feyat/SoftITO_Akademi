/*
    Pointerlar: 
        - Nesnelerin adresini tutan varlıklardır.
        - type *nesnead;

        - int *ptr;
        - int * ptr; int türden nesnelerin adresini tutar
        - Adres opartörü :  & 

    Pointer Operatörler:
        - * indirection operator. --> referans 
        - & adres operatörü
        - [] index opeatörü
        - -> arrow operatörü

    Call by Value: 

    Call by Reference:  

    
    Const:
        Bu değişken değişemez 

        int x = 10;
        const int y = 20;

        int main(){
            x = 20; 
            y = 10;
            
        }

        salt okuma amaçlı 
            void foo(const int *ptr);
            void foo2(int *ptr2);

    Pointer aritmetiği: 
        - bayt olarak artırıyor.

        // *(ptr+1) = ptr[i]
        // (ptr+i) = &ptr[i]
*/


#include  <stdio.h>

int main(){
    int x = 10, y = 20;
    int *ptr = &x; // x'in adresini tutar.  ptr is pointer to int variable.
    double dval = 15.3;
    int *ptr2 = ptr;
    int a[5] = {1, 2, 3, 4, 5};

    int *ptr3 = &a[2];  // bu dizinin 2 elemanın adresini tutar.
    int *p3 = a;  // array to pointer conversion(array to decay) dizinin adını yazarsanız. 
    // dizinin ilk elemanın adresini tutar. 

    printf("ptr = %p, \n &y = %p\n", ptr, &x);

    printf("ptr = %p,\n &x = %p\n", ptr, &y);
    printf("&x = %p, &y = %p, ptr2 = %p, ptr=%p\n", &x, &y, ptr2, ptr);
    printf("a[0]= %p, p3 = %p", a, p3);

}
