#include <stdio.h>
#include "func_matrius.h"

void llegeixvector(int n,double v[n]){
    for(int i=0;i<n;i++){
        printf("a(%d)= ",i+1);
        scanf("%lf",&(v[i]));
    }
}
void llegeixmatriu(int m,int n,double A[m][n]){
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            printf("a(%d,%d)= ",i+1,j+1);
            scanf("%lf",&A[i][j]);
        }
    }
}
void matriuxvector(int m,int n,double vect[n],double mat[m][n],double resul[m]){
    for(int i=0;i<m;i++){
        resul[i]=0;
        for(int j=0;j<n;j++)
            resul[i]+=mat[i][j]*vect[j];
    }
}
void imprimeixvector(int n,double v[n]){
    for(int i=0;i<n;i++)
        printf("a(%d)=%g\n",i+1,v[i]);
}
void copyvector(double u[],double v[],int dim){
    //Copiar el vector u al vector v.
    for(int i=0;i<dim;i++)
        v[i]=u[i];
}
