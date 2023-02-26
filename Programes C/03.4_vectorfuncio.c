#include <stdio.h>
#define DIMENSIO 2

void imprimeixvector(double [],int);
void llegeixvector(double [],int);
int main(){
    double v[DIMENSIO];
    int i;

    puts("Entrem el vector");
    llegeixvector(v,DIMENSIO);
    puts("Ara l'imprimim:");
    imprimeixvector(v,DIMENSIO);
    return 0;
}

void llegeixvector(double vect[],int dim){
    int i;
    for(i=0;i<dim;i++){
        printf("v(%d)= ",i+1);
        scanf("%lf",&(vect[i]));
    }
    return;
}

void imprimeixvector(double vect[],int dim){
    int i;
    for(i=0;i<dim;i++){
        printf("%g\n",vect[i]);
    }
    return;
}
