/*

    typedef bildirimler

        typedef unsigned int uint32_t;

        // unsigned long demekmiş 
        size_t --> %zu  size; --> size_t parametresini kullanmak daha efektif olur

        what is the format specifier for size_t --> format bildirimlerini öğrenmek için kullanırız.


        storage türü ifade ederken size_t kullanılır.

        tane adet ilişkisi ifade ederken kullanılır. 

        size_t;
        ptrdiff_t;

        size_t;
        ptrdiff_t;

    null(NULL) pointer --> başarıssızlık durumunda kullanılır.
        fopen  --> NULL pointer döndürür.
        strchr --> NULL pointer döndürür.
        const ifadesi bir değişim yapmayacağız anlamına gelir. 

*/

#include <stdint.h>
#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>

/*

    Bir dizi yazın aranan eleman var mı varsa o elemanın adresini 
    döndüren yoksa null pointer döndüren fonksiyonu yazın.

    (ptr+i) = &ptr[i];  --> adres tutar
    ptr[i] = *(ptr+i);  --> değer tutar

*/

int *search(int *ptr, const int search_t, size_t size){
    for(int i=0;i<size;i++){
        if(*(ptr+i)==search_t){
            return (ptr+i);
        }
    }
    return NULL;
}

int main(){
    int array[5] = {2, 3, 4, 5, 6};

    int size = sizeof(array)/sizeof(array[0]);
    int *ptr = array;
    int search_t;
    printf("Aradığınız sayıyı giriniz: ");
    scanf("%d", &search_t);

    int *search_find = search(ptr, search_t, size);

    if(search_find == NULL)
        printf("Null değer döndü");

    else 
        printf("Sayımızın indexi = %ld'dir", (search_find-array));

}


/*

    Bir diziyi istenen eleman sayısı kadar diğer diziye kopyalıyan fonksiyonu yaz.

*/



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