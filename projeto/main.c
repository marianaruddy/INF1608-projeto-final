#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "projeto.h"
#include "matriz.h"

// clear && gcc -o main projeto.c main.c matriz.c -lm && ./main

int main(){

    double tol = 0.0000001;
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