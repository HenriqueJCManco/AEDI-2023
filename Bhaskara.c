#include <stdio.h>
#include <math.h>

void bhaskara(float a, float b, float c) {
  float delta = b*b - 4*a*c; 
  if (delta < 0) { 
    printf("Impossivel calcular\n");
  }
  else if (delta == 0) { 
    float x = -b / (2*a); 
    printf("R1 = %.5f\n", x);
  }
  else { 
    float x1 = (-b + sqrt(delta)) / (2*a); 
    float x2 = (-b - sqrt(delta)) / (2*a); 
    printf("R1 = %.5f \n R2 = %.5f\n", x1, x2);
  }
}

int main() {
  float a, b, c; 
  scanf("%f %f %f", &a, &b, &c); 
  bhaskara(a,b,c); 
}