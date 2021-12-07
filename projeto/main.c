#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include "projeto.h"
#include "matriz.h"

// clear && gcc -o main projeto.c main.c matriz.c -lm && ./main

int main(){

    double tol = 0.0000001;
    double* x_vertices = criavet(4);
    double* y_vertices = criavet(4);

    // x_vertices[0] = 2.0;
    // x_vertices[1] = -2.0;
    // x_vertices[2] = 2.0;
    // x_vertices[3] = -2.0;
    
    // y_vertices[0] = 2.0;
    // y_vertices[1] = 2.0;
    // y_vertices[2] = -2.0;
    // y_vertices[3] = -2.0;

    x_vertices[0] = -2.0;
    x_vertices[1] = 2.0;
    x_vertices[2] = 2.0;
    x_vertices[3] = -20.0;
    
    y_vertices[0] = -2.0;
    y_vertices[1] = -2.0;
    y_vertices[2] = 2.0;
    y_vertices[3] = 20.0;
    
    double x = 1.5;
    double y = 1.5;

    double s0 = 0.0;
    double t0 = 0.0;
    
    printf("\ncaso estimativa inicial (%f, %f) = (0, 0):\n", s0, t0);
    
    calc_coord_parametricas(x, y, s0, t0, x_vertices, y_vertices, tol, 50);
    
    printf("\ncaso estimativa inicial aleatoria:\n");
    
    srand( (unsigned)time(NULL) );

    s0 = (rand() % 101)/100.0;
    t0 = (rand() % 101)/100.0;

    printf("\ts0=%g \tt0=%g", s0, t0);
    
    calc_coord_parametricas(x, y, s0, t0, x_vertices, y_vertices, tol, 50);
    
    printf("\ncaso coordenadas parametricas estao no intervalo [−2, 2]tb x=y=2.5:\n");

    s0 = 0.0;
    t0 = 0.0;
    
    calc_coord_parametricas(2.5, 2.5, s0, t0, x_vertices, y_vertices, tol, 50);

    printf("\ncaso celulas degeneradas (dois pontos coincidentes):\n");

    x_vertices[1] = x_vertices[0];
    
    y_vertices[1] = y_vertices[0];
    calc_coord_parametricas(x, y, s0, t0, x_vertices, y_vertices, tol, 50);

    printf("\ncaso celulas degeneradas (todos os pontos coincidentes):\n");

    x_vertices[2] = x_vertices[0];
    x_vertices[3] = x_vertices[0];
    
    y_vertices[2] = y_vertices[0];
    y_vertices[3] = y_vertices[0];
    // calc_coord_parametricas(x, y, s0, t0, x_vertices, y_vertices, tol, 50);

    printf("\ncaso 3d:\n");

    return 0;
}