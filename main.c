#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "projeto.h"

// clear && gcc -o main projeto.c main.c -lm && ./main


double f1 (double x) {
    return x*x*x-3*x*x+7;
}

double f_derivada1 (double x) {
    return 3*x*x-3*x;
}
double f2 (double x) {
    return x*x;
}

double f_derivada2 (double x) {
    return 2*x;
}

int main(){
    double x0 = 10.0;
    double tol = 0.0000001;
    printf("x= %.9g\n", newton_raphson(x0, f2, f_derivada2, tol, 50));

    return 0;
}