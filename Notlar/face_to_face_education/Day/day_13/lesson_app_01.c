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

int main(){
    char name[33] = "Ahmet";
    char surname[34] = "Korkmaz";
    char fullname[199];

    strcat(strcat(strcpy(fullname, name), " "), surname);
    puts(fullname);
    printf("%ld ", strchr(name, 'm')-name);
    strcat(strcat(name, " "), surname);
    puts(name);

}