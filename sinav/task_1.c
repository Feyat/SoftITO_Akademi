#include <stdio.h>

// GERÇEK STRCPY. fonksiyonunda. char* döner.   ch
void mystrcpy(char *dest,const char *src){

    while(*src){
        *dest = *src;
        dest++;
        src++;  
    }
    // NULL karakter koyulmamış
}

#define         ASIZE        100
int main(){
    char name[ASIZE] =  "Ahmmett";
    char cp[ASIZE];
    mystrcpy(cp, name);
    puts(cp);

}