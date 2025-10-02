#include <stdio.h>
#include <string.h>


int main(){
    char name[30] = "samet";
    char *pname = name;
    pname += strlen(name);  
    *pname = 'X'; pname++; *pname = '\0'; 
    puts(name);
}