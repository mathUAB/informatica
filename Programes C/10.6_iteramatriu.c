#include <stdio.h>
#include "func_matrius.h"

int main(){
    int n,k;
    printf("Escriu les dimensions de la matriu: ");
    scanf("%d",&n);
    double A[n][n],v[n],u[n];
    puts("Escriu la matriu: ");
    llegeixmatriu(n,n,A);
    puts("Escriu el vector: ");
    llegeixvector(n,v);
    printf("Escriu un enter: ");
    scanf("%d",&k);
    puts("El vector introduit es:\n");
    imprimeixvector(n,v);
    for(int i=0;i<k;i++){
        matriuxvector(n,n,v,A,u);
        copyvector(u,v,n);//Copia el vector u al vector v de dimensions n.
    }
    printf("El vector resultant de calcular (A^%d)v es:\n",k);
    imprimeixvector(n,v);
    return 0;
}
