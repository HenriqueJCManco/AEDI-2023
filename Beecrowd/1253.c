#include <stdio.h>

int main() {
    
    char mensagem[51];
    
    int deslocamento, numero;
    
    scanf("%d", &numero);
    
    for ( int i = 0 ; i < numero ; ++i){

        scanf("%[^\n]\n", &mensagem);
        scanf("%d\n", &deslocamento);

        for( int j = 0; j < strlen(mensagem); ++j){

            mensagem[j] = ((mensagem[j] - 'A' - deslocamento + 25) % 25) + 'A';
        }

        printf("%s\n", mensagem);
    }
    return 0;
}
