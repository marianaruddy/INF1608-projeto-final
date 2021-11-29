#include <stdio.h>
#include <math.h>

double newton_raphson(double x, double f (double x), double f_derivada (double x), double tol, int num_max_iter) {
    for(int i = 0; i < num_max_iter; i++) {
        double fx = f(x);
        double dfx = f_derivada(x);
        double deltax = -fx/dfx; 
        x += deltax;
        if (fabs(dfx) < tol || fabs(fx) < tol) {
            return x;
        }
    }
    printf("\nNAO CONVERGE\n");
}