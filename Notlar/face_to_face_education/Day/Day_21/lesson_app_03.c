#include <stdio.h>
#include <string.h>
#define    ASIZE     5

int main(){
    const char *pA[ASIZE] = {"Kerem", "Selami", "Hatun", "Kehribar", "Guvec"};
    char data[100];
    int dat = 0;

    printf("Bulmak istediğiniz veriyi giriniz: ");
    scanf("%s", data);

    for(int i = 0; i<ASIZE; i++){
        size_t size = sizeof(pA[i]);
        printf("%zu ", size);
        printf("%c%c ", pA[i][0], (pA[i]+size-1)[0]);
    }


    for(int i=0;i<ASIZE;i++){
        size_t size = sizeof(pA[i]);
        for(int j=0;j<size; j++){
            if(pA[i][j] == data[j]){
                dat = 0;
            }
            else 
                dat = 1; break;
        }
        if(dat == 0)
            break;
    }

    if(dat == 0)
        printf("Var...");
}