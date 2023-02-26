#include <stdio.h>
#include <stdlib.h>

void llegeixvector(int dim,double[]);
void llegeixmatriu(int dim,double[]);
void matriuxvector(int dim,double[],double[],double[]);
void imprimeixvector(int dim,double vect[]);
int main(){
    int dim;
    printf("De quina dimensió són la matriu i el vector? ");
    scanf("%d",&dim);
    double vect[dim];
    double *A;
    double resul[]={0,0,0};

    A=(double *) malloc(dim*dim*sizeof(double));
    if(A==NULL){
        printf("Ha fallat l'assignació.\n");
        return 1;
    }
    puts("Entrem el vector:");
    llegeixvector(dim,vect);
    puts("Entrem la matriu:");
    llegeixmatriu(dim,A);
    matriuxvector(dim,vect,A,resul);
    imprimeixvector(dim,resul);
    return 0;
}

void llegeixvector(int dim,double v[]){
    int i;
    for(i=0;i<dim;i++){
        printf("a(%d)= ",i+1);
        scanf("%lf",&(v[i]));
    }
    return;
}

void llegeixmatriu(int dim,double A[]){
    int i,j;
    for(i=0;i<dim;i++){
        for(j=0;j<dim;j++){
            printf("a(%d%d)= ",i+1,j+1);
            scanf("%lf",&A[i*dim+j]);
        }
    }
}

void matriuxvector(int dim,double vect[],double A[],double resul[]){
    int i,j;
    for(i=0;i<dim;i++){
        for(j=0;j<dim;j++){
            resul[i]+=A[i*dim+j]*vect[j];
        }
    }
    return;
}

void imprimeixvector(int dim,double vect[]){
    int i;
    printf("El producte de la matriu per el vector és el vector\n");
    for(i=0;i<dim;i++){
        printf("a(1%d)=%g\n",i+1,vect[i]);
    }
    return;
}
