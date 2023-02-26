#include <stdio.h>
#include <stdlib.h>

int main(){
    long long unsigned int n;
    int i;
    double sum=0;
    double *v;

    printf("Quants nombres es volen sumar? ");
    scanf("%llu",&n);

    v=(double *) malloc(n*sizeof(double));
    if(v==NULL){
        printf("No hi ha prou memòria a l'ordinador per %llu components.",n);
        return 1;
    }
    for(i=0;i<n;i++){
        printf("Escriu el nombre %d: ",i+1);
        scanf("%lf",&v[i]);
        sum+=v[i];
    }
    printf("Nombres entrats: ");
    for(i=0;i<n;i++){
        printf("%g  ",v[i]);
    }
    printf("\nSuma: %g",sum);
    free(v);
    return 0;
}
