#include <stdio.h>
#include <stdlib.h>

void llegeixmatriu(int dim,double[]);
void sumamatrius(int dim,double[],double[],double[]);
void multiplicaciomatrius(int dim,double[],double[],double[]);
void imprimeixmatriu(int dim,double[]);
int main(){
    int dim;
    printf("De quina dimensió són les matrius? ");
    scanf("%d",&dim);
    double *A,*B;
    double sum[dim*dim],mult[dim*dim];

    A=(double *) malloc(dim*dim*sizeof(double));
    B=(double *) malloc(dim*dim*sizeof(double));
    if(A==NULL || B==NULL){
        printf("Ha fallat l'assignació.\n");
        return 1;
    }
    puts("Entrem la matriu A:");
    llegeixmatriu(dim,A);
    puts("Entrem la matriu B:");
    llegeixmatriu(dim,B);
    puts("La suma de les matrius és:");
    sumamatrius(dim,A,B,sum);
    imprimeixmatriu(dim,sum);
    puts("La multiplicació de les matrius");
    multiplicaciomatrius(dim,A,B,mult);
    imprimeixmatriu(dim,mult);
    return 0;
}

void llegeixmatriu(int dim,double A[]){
    for(int i=0;i<dim;i++){
        for(int j=0;j<dim;j++){
            printf("a(%d%d)= ",i+1,j+1);
            scanf("%lf",&A[i*dim+j]);
        }
    }
}

void sumamatrius(int dim,double A[],double B[],double sum[]){
    for(int i=0;i<dim*dim;i++){
        sum[i]=A[i]+B[i];
    }
    return;
}

void multiplicaciomatrius(int dim,double A[],double B[],double mult[]){
    for(int i=0;i<dim;i++){
        for(int j=0;j<dim;j++){
            for(int k=0;k<dim;k++){
                if(k==0){
                    mult[i*dim+j]=0;
                }
                mult[i*dim+j]+=A[i*dim+k]*B[k*dim+j];
            }
        }
    }
    return;
}

void imprimeixmatriu(int dim,double A[]){
    for(int i=0;i<dim;i++){
        for(int j=0;j<dim;j++){
            printf("%g\t",A[i*dim+j]);
        }
        puts(" ");
    }
    return;
}
