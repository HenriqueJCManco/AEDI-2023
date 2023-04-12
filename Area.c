#include <stdio.h>
#include <math.h> 

int main (){

    double area, Raio, pi;
    pi = 3.14159;

    scanf("%lf", &Raio);

    area = pi * pow(Raio,2);

    printf("A=%.4lf\n", area);

    return 0;
}