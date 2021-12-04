#include "matriz.h"

double u (double x, double s, double t, double* x_vertices);

double v (double y, double s, double t, double* y_vertices);

double calc_duds (double t, double* x_vertices);

double calc_dudt (double s, double* x_vertices);

double calc_dvds (double t, double* y_vertices);

double calc_dvdt (double s, double* y_vertices);

void calc_jacobiana (double** jacobiana, double s, double t, double* x_vertices, double* y_vertices);

void calc_jacobiana_inversa (double** jacobiana, double** jacobiana_inversa);

void calc_coord (double s, double t, double x, double y, double** jacobiana_inversa, double tol, int num_max_iter, double* x_vertices, double* y_vertices);

void calc_coord_parametricas (double x, double y, double s0, double t0, double* x_vertices, double* y_vertices, double tol, double num_max_iter);


