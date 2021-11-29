#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "projeto.h"
#include "matriz.h"

// clear && gcc -o main projeto.c main.c matriz.c -lm && ./main


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

    double tol = 0.0000001;
    // ----------------------- teste newton_raphson -----------------------
    // double x0 = 10.0;
    // printf("x= %.9g\n", newton_raphson(x0, f1, f_derivada1, tol, 50));
    // printf("x= %.9g\n", newton_raphson(x0, f2, f_derivada2, tol, 50));
    // --------------------------------------------------------------------


    double* x_vertices = criavet(4);
    double* y_vertices = criavet(4);

    x_vertices[0] = 2.0;
    x_vertices[1] = -2.0;
    x_vertices[2] = 2.0;
    x_vertices[3] = -2.0;
    
    y_vertices[0] = 2.0;
    y_vertices[1] = 2.0;
    y_vertices[2] = -2.0;
    y_vertices[3] = -2.0;
    
    double x = 1.5;
    double y = 1.5;
    
    calc_coord_parametricas(x, y, x_vertices, y_vertices, tol, 50);

    return 0;
}