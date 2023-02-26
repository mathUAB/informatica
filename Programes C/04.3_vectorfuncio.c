#include <stdio.h>
#define DIMENSIO 2

void imprimeixvector(double *,int);
void llegeixvector(double *,int);
int main(){
    double v[DIMENSIO];

    puts("Entrem el vector");
    llegeixvector(v,DIMENSIO);
    puts("Ara l'imprimim:");
    imprimeixvector(v,DIMENSIO);
    return 0;
}

void llegeixvector(double *vect,int dim){
    int i;
    for(i=0;i<dim;i++,vect++){
        printf("v(%d)= ",i+1);
        scanf("%lf",vect);
    }
    return;
}

void imprimeixvector(double *vect,int dim){
    int i;
    for(i=0;i<dim;i++,vect++)
        printf("%g\n",*vect);
    return;
}
