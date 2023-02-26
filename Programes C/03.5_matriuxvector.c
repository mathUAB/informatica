#include <stdio.h>

void llegeixvector(int dim,int,double[][dim]);
void matriuxvector(int dim,double[],double[][dim],double[]);
void imprimeixvector(int dim,double vect[]);
int main(){
    int i,j,dim;
    printf("De quina dimensió són la matriu i el vector? ");
    scanf("%d",&dim);
    double vect[dim];
    double mat[dim][dim];
    double resul[]={0,0,0};

    puts("Entrem el vector:");
    llegeixvector(dim,0,vect);
    puts("Entrem la matriu:");
    for(j=0;j<dim;j++){
        llegeixvector(dim,j,mat);
    }
    matriuxvector(dim,vect,mat,resul);
    imprimeixvector(dim,resul);
    return 0;
}

void llegeixvector(int dim,int j,double mat[][dim]){
    int i;
    for(i=0;i<dim;i++){
        printf("a(%d%d)= ",j+1,i+1);
        scanf("%lf",&(mat[j][i]));
    }
    return;
}

void matriuxvector(int dim,double vect[],double mat[][dim],double resul[]){
    int i,j;
    for(i=0;i<dim;i++){
        for(j=0;j<dim;j++){
            resul[i]+=mat[i][j]*vect[j];
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


