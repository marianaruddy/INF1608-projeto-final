#include <stdio.h>
#include <math.h>
#include "matriz.h"

double u (double x, double s, double t, double* x_vertices) {
    double f = ( (1.0-s)*(1.0-t)*x_vertices[0] + (1.0-s)*(1.0+t)*x_vertices[1] + (1.0+s)*(1.0+t)*x_vertices[2] + (1.0+s)*(1.0-t)*x_vertices[3] ) / 4.0;
    return x - f;
}

double v (double y, double s, double t, double* y_vertices) {
    double g = ( (1.0-s)*(1.0-t)*y_vertices[0] + (1.0-s)*(1.0+t)*y_vertices[1] + (1.0+s)*(1.0+t)*y_vertices[2] + (1.0+s)*(1.0-t)*y_vertices[3] ) / 4.0;
    return y - g;
}

double calc_duds (double t, double* x_vertices) {
    double duds = - ( ((-1.0+t)*x_vertices[0]) + ((-1.0-t)*x_vertices[1]) + ((1.0+t)*x_vertices[2]) + ((1.0-t)*x_vertices[3]) ) / 4.0;
    return duds;
}

double calc_dudt (double s, double* x_vertices) {
    double dudt = - ( ((-1.0 + s) * x_vertices[0]) + ((1.0 - s) * x_vertices[1]) + ((1.0+s)*x_vertices[2]) + ((-1.0-s)*x_vertices[3]) ) / 4.0;
    return dudt;
}

double calc_dvds (double t, double* y_vertices) {
    double dvds = - ( (-1.0+t)*y_vertices[0] + (-1.0-t)*y_vertices[1] + (1.0+t)*y_vertices[2] + (1.0-t)*y_vertices[3] ) / 4.0;
    return dvds;
}

double calc_dvdt (double s, double* y_vertices) {
    double dvdt = - ( (-1.0+s)*y_vertices[0] + (1.0-s)*y_vertices[1] + (1.0+s)*y_vertices[2] + (-1.0-s)*y_vertices[3] ) / 4.0;
    return dvdt;
}

void calc_jacobiana (double** jacobiana, double s, double t, double* x_vertices, double* y_vertices) {
    double duds = calc_duds(s, x_vertices);
    double dudt = calc_dudt(t, x_vertices);
    double dvds = calc_dvds(s, y_vertices);
    double dvdt = calc_dvdt(t, y_vertices);

    jacobiana[0][0] = duds;     jacobiana[0][1] = dudt;
    jacobiana[1][0] = dvds;     jacobiana[1][1] = dvdt;
}

void calc_jacobiana_inversa (double** jacobiana, double** jacobiana_inversa) {
    double denominador = jacobiana[0][1] * jacobiana[1][0] - jacobiana[1][1]  * jacobiana[0][0];
    if(denominador == 0) {
        printf("MATRIZ NAO INVESIVEL\n");
        return;
    }
    jacobiana_inversa[0][0] = -jacobiana[1][1] / denominador;       jacobiana_inversa[0][1] = jacobiana[0][1] / denominador;
    jacobiana_inversa[1][0] = jacobiana[1][0] / denominador;        jacobiana_inversa[1][1] = -jacobiana[0][0] / denominador;
}

void calc_coord (double s, double t, double x, double y, int n, double** jacobiana, double tol, int num_max_iter, double* x_vertices, double* y_vertices) {
    double** jacobiana_inversa = criamat(n, n);
    double new_s, new_t, u_valor, v_valor;
    
    u_valor = u(x, s, t, x_vertices);
    v_valor = v(y, s, t, y_vertices);

    printf("s inicial  = %f e t inicial  = %f\n", s, t);
    printf("u_valor inicial = %f\n", u_valor);
    printf("v_valor inicial = %f\n", v_valor);

    for(int i = 0; i < num_max_iter; i++) 
    {
        calc_jacobiana(jacobiana, s, t, x_vertices, y_vertices);
        calc_jacobiana_inversa(jacobiana, jacobiana_inversa);

        new_s = s - (jacobiana_inversa[0][0] * u_valor + jacobiana_inversa[0][1] * v_valor);
        new_t = t - (jacobiana_inversa[1][0] * u_valor + jacobiana_inversa[1][1] * v_valor);

        s = new_s;
        t = new_t;
        
        u_valor = u(x, s, t, x_vertices);
        v_valor = v(y, s, t, y_vertices);


        if (fabs(u_valor) < tol || fabs(v_valor) < tol) {

            printf("\n[%d] s = %g \t t = %g\n", i, s, t);
            return;
        }
    }
    printf("\n[NAO CONVERGE]\n");
}

void calc_coord_parametricas (double x, double y, double s0, double t0, double* x_vertices, double* y_vertices, double tol, double num_max_iter ) {
    int n = 2;
    double** jacobiana = criamat(n, n);
    double** jacobiana_inversa = criamat(n, n);
    double s = s0;
    double t = t0;
    calc_coord(s, t, x, y, n, jacobiana_inversa, tol, num_max_iter,x_vertices, y_vertices);
}



