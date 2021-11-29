#include "matriz.h"
#include <stdlib.h>
#include <stdio.h>
#include <math.h>


void print_vetor(const double* v, int n) {
    printf("[");
    for (int i = 0; i < n; i++) {
        printf("%9g   ", v[i]);
    }
    printf("]");
}

void print_mat(const double** M, int m, int n) {
    for (int i = 0; i < m; i++) {
        print_vetor(M[i], n);
        printf("\n");
    }
}

double* criavet (int n)
{
  double* v = (double*)malloc(n*sizeof(double));
  return v;
}
void liberavet (double* v)
{
  free(v);
}
double escalar (int n, double* v, double* w)
{
  double s = 0;
  for (int i=0; i<n; ++i)
    s += v[i]*w[i];
  return s;
}
double norma2 (int n, double* v)
{
  double s = escalar(n,v,v);
  return sqrt(s);
}

void multvs (int n, double* v, double s, double* w)
{
  for (int i=0; i<n; ++i)
    w[i] = v[i]*s;
}

double** criamat (int m, int n)
{
  double** A = (double**) malloc(m*sizeof(double*));
  for (int i=0; i<m; ++i)
    A[i] = (double*) malloc(n*sizeof(double));
  return A;
}

void liberamat (int m, double** A)
{
  for (int i=0; i<m; ++i)
    free(A[i]);
  free(A);
}

void transposta (int m, int n, double** A, double** T)
{
  for (int i=0; i<m; ++i)
    for (int j=0; j<n; ++j)
      T[j][i] = A[i][j];
}
  
void multmv (int m, int n, double** A, double* v, double* w)
{
  for (int i=0; i<m; ++i) {
    w[i] = 0.0;
    for (int j=0; j<n; ++j)
      w[i] += A[i][j] * v[j];
  }
}
  
void multmm (int m, int n, int q, double** A, double** B, double** C)
{
  for (int i=0; i<m; ++i) {
    for (int k=0; k<q; ++k) {
      C[i][k] = 0.0;
      for (int j=0; j<n; ++j) 
        C[i][k] += A[i][j] * B[j][k];
    }
  }
}
  
