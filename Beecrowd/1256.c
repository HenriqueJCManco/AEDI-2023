#include <stdio.h>
#include <string.h>

int vHash(char string[], int posicao){
  int i,hash =0;
  int len = strlen(string);

  for ( i = 0; i < len; i++){
    hash += (string[i] - 65) + i + posicao;
  }

  return hash;
}

int main(){
  int casos, linha, i, j, hashTotal;
  char string[51];
  scanf("%d", &casos);

  while (casos > 0){
    scanf("%d", &linha);
    hashTotal = 0;

    for(i = 0; i < linha; i++){
      scanf("%s", string);
      hashTotal += vHash(string, i);
    }
    printf("%d\n", hashTotal);
    casos--;
  }
  return 0;
}
