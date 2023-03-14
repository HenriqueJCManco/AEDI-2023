#include <stdio.h>

int main (){
    float area, raio, Raio, pi;
    Raio = 0;
    area =0;
    pi = 3.14159;
    scanf("%f", &raio);
    Raio = raio * raio;
    area = pi * Raio;
    printf("A=%.4f", area);
}