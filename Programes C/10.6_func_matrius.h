#ifndef FUNC_MATRIUS_H // El que ve a sota només val si NO s'ha fet abans.
#define FUNC_MATRIUS_H

void llegeixvector(int n,double v[n]);
void llegeixmatriu(int m,int n,double A[m][n]);
void matriuxvector(int m,int n,double vect[n],double mat[m][n],double resul[m]);
void imprimeixvector(int n,double v[n]);
void copyvector(double u[],double v[],int dim);

#endif
