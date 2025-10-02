#include <stdio.h>


// fonksiyon ismi kötü,  ve bu tarz. fonksiyonlar genelde. char* döner  .    veli..txt olursa patlar ama sorun yok :)
void myuzan(char *dest,const char *src){

    while(*dest != '.'){
        dest++; 
    }
    dest++;
    while(*src){
        *dest = *src;
        src++;
        dest++;
    }
}

#define         ASIZE        100
int main(){
    char fname[ASIZE] =  "task..txt";
    char uzan[ASIZE];
    printf("Istediginiz uzantıyı giriniz: ");
    scanf("%s", uzan);
   
    myuzan(fname, uzan);
    puts(fname);

}