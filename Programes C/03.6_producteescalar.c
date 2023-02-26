#include <stdio.h>

void llegeixvector(int,double[]);
void imprimeixvector(int,double vect[]);
int main(){
    int i,j,dim;
    printf("De quina dimensio son la matriu i el vector? ");
    scanf("%d",&dim);
    double v[dim],u[dim],prod=0;

    printf("Escriu els components del primer vector:\n");
    llegeixvector(dim,v);
    printf("Escriu els components del segon vector:\n");
    llegeixvector(dim,u);

    for (i=0;i<dim;i++){
        prod+=v[i]*u[i];
    }
    printf("El producte escalar dels dos vectors es %g",prod);

    return 0;
}

void llegeixvector(int dim,double vect[]){
    int i;
    for(i=0;i<dim;i++){
        printf("a(%d)= ",i+1);
        scanf("%lf",&(vect[i]));
    }
    return;
}


