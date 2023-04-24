#include <string.h>
#include <stdio.h>

int vogal(char letra){
    char vogais[] = {'a', 'e', 'i', 'o', 'u'};

    for(int i = 0; i < 5; i++){
        if(letra == vogais[i]){
            return 1;
        }
    }

    return 0;
}
 

int main(){
    int i, f;
    int engracada;
    char risada[51];

    scanf("%s", &risada);

    i = 0;
    f = strlen(risada) - 1;
    engracada = 1;
    while(i < f){
        if(vogal(risada[i]) && vogal(risada[f])){
            if(risada[i] != risada[f]){
                engracada = 0;
                break;
            }
            ++i;
            --f;
        }else{
            if(!vogal(risada[i]))   ++i;
            if(!vogal(risada[f]))   --f;
        }
    }

    printf("%c\n", engracada ? 'S' : 'N');

    return 0;
}
