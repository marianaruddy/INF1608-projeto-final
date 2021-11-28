#include <stdio.h>
#include <math.h>

// double newton_raphson(double x0, double f (double x), double f_derivada (double x), double tol, int num_max_iter) {
//     double x = x0;
//     double delta = f(x)/f_derivada(x); 
//     for(int i = 0 ; i < 50; i++) {
//         x = x - f(x)/f_derivada(x);
//         printf("\nx[%d] = %g", i, x);
//     }
//     printf("\nNAO CONVERGE\n");
// }

double newton_raphson(double x, double f (double x), double f_derivada (double x), double tol, int num_max_iter) {
    for(int i = 0; i < num_max_iter; i++) {
        double fx = f(x);
        double dfx = f_derivada(x);
        double deltax = -fx/dfx; 
        x += deltax;
        if (fabs(deltax) < tol || fx < tol) {
            return x;
        }
    }
    printf("\nNAO CONVERGE\n");
}