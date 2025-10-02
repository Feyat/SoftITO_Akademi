// strlen fonksiyonu modelle 
// strcat --> İki yazıyı birleştir.
// strcpy --> Bir yazıyı diğer yere kopyalar ilk dest --> döndüreceği değer sonra src göndereceğiz
// strcmp --> Yazılar aynı mı?
// strchr --> bir karakter var mı yok mu?
// index bulma  --> 
// strstr --> Bir string içinde başka string var mı?
// strncat --> n tane kelimeyi ekliyor?
// putchar --> standar output tek karakter yazdırma function 
// getchar --> tek karakter okuma

#include <stdio.h>
#include <string.h>

char *myputs(char *str){
    while(*str != '\0'){
        putchar(*str);
        str++;
    }
    return str;
}
int main(){
    char name[100] = "Samet";
    printf("\n%ld ", myputs(name)-name);
}