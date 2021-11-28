#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "projeto.h"

// clear && gcc -o main projeto.c main.c -lm && ./main


double f (double x) {
    return x*x;
}

double f_derivada (double x) {
    return 2*x;
}

int main(){
    double x0 = 10.0;
    double tol = 0.0000001;
    printf("x= %g\n", newton_raphson(x0, f, f_derivada, tol, 50));

    return 0;
}