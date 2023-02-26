#include <stdio.h>
#include <math.h>
#include <stdlib.h>

double trassa(int n,double[][n]);
void matriuhilbert(int n,double[][n]);
int main(){
    int n=1;
    do{
        double (*A)[n];
        A=(double(*)[n]) malloc(n*n*sizeof(double));
        if(A==NULL){
            printf("No hi ha suficient memoria per una matriu de dimensió %dx%d.",n,n);
            return 1;
        }
        matriuhilbert(n,A);
        printf("La traça de la matriu de Hilbert de dimensió %d és %lf.\n",n,trassa(n,A));

        n*=3;
        free(A);
    }while(1>0);

    return 0;
}

double trassa(int n,double A[][n]){
    double trassa=0;
    for(int i=0;i<n;i++){
        trassa+=A[i][i];
    }
    return trassa;
}

void matriuhilbert(int n,double A[][n]){
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            A[i][j]=1./(i+j+1.);
        }
    }
    return;
}
