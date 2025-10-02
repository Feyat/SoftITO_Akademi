#include <stdio.h>
#include <string.h>

#define   ASIZE  5


int main(void){


    size_t sizeArr[ASIZE];
    const char* pa[ASIZE] ={"Ahmet", "Artı", "Eksi", "Hata", "Doğru"};
    char source[ASIZE][2];
    for(int i = 0;i<ASIZE;i++){
        printf("%s ", *(pa+i));
        sizeArr[i] = strlen(*(pa+i));
    }

    for(int i = 0; i < ASIZE; i++){
        printf("%zu ", sizeArr[i]);
    }

    for(int i = 0; i<ASIZE; i++){
        int art = 0;
        for(int j = 0; j<sizeArr[i]; j++){
            if(j == 0 || j == sizeArr[i]-1){
                printf("%c", pa[i][j]);
                source[i][art] = pa[i][j];
                art++;
            }
        }
        printf("\n");
    }

    for(int i = 0; i < ASIZE; i++){
        for(int j = 0; j<2; j++)
            printf("%c", source[i][j]);
        printf("\n");
    }
}