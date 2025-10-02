#include <stdio.h>


// // Null karakter koyulmamış dest'in sonuna her zaman doğru çalışmıyor.Algoritma fena degil.  tüm white space karakterleri ele alınsa daha güzel olur
// \t gibi. 
void trim(char *dest,const char *src){

    while(*src){
        if(*src == ' ')
            src++;
        else{
            *dest = *src;
            dest++;
            src++;
        }
    }
}

#define         ASIZE        100
int main(){
    char name[ASIZE] =  " Ahmmett ";
    char sname[ASIZE];
    trim(sname, name);
    puts(sname);

}