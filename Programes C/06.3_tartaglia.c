#include <stdio.h>
#include <stdlib.h>

int main(){
    int i,j,fila,fila1=0;
    int *T=NULL,*aux;

    printf("Quantes files del triangle de Tartaglia es volen calcular? ");
    scanf("%d",&fila);
    do{
        fila+=fila1;
        for(i=fila1+1;i<=fila;i++){
        aux=(int *) realloc(T,i*sizeof(int));
        if(aux==NULL){
            printf("Ha fallat la reassignació.\n");
            exit(1);
        }
        T=aux;
        for(j=i-1;j>=0;j--){
            if((j==0) || (j==i-1))
                T[j]=1;
            else
                T[j]+=T[j-1];
            printf ("%d\t",T[j]);
        }
        printf ("\n");
        }
        fila1=fila;
        printf("Quantes files més del triangle de Tartaglia es volen calcular? ");
        scanf("%d",&fila);
    }while(fila!=0);
    free(T);
    return 0;
}
