#include <stdio.h>
/*recebe o vetor e retorna valores nao nulos e positivos*/
void removerN( int Y[], int n){
  int i;
  
  for ( i = 0; i < n ; i++){
    
    if (Y[i] <= 0) Y[i] = 1;
  
  }
}

int main(void) {
  int X[10], j, p;
  
  for ( p = 0; p < 10 ; p++){
    scanf("%d", &X[p]); 
  }
  
  removerN(X,10);
    
  for ( j = 0  ; j < 10 ; ++j){
      printf("X[%d] = %d\n", j, X[j]);
    }
  
  return 0;
}