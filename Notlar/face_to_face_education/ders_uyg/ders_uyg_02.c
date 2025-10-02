#include <stdio.h>

void strcann(char *pname, char *poyad){
    while(*pname!='\0')
        pname++;

    *pname = ' ';
    pname++;
    while(*poyad!='\0'){
        *pname = *poyad;
        pname++;
        poyad++;
    }
    pname++;
    *pname = '\0';
}

int main(){
    char name[30] = "Feyat";
    char soyad[30] = "Turkmen";

    char *pname = name;
    char *poyad = soyad;
    strcann(pname, poyad);
    puts(name);
}