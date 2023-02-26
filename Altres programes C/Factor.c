#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int is_prime(int n);
int next_prime(int n);
int *factor(int n,int *count);
void imprimeixvector(int dim,int v[]);

int main(int argc,char *argv[]){
    if(argc!=2){
        printf("Error en la lectura.\n");
        return 1;
    }
    int n=atoi(argv[1]), count=0, *v=factor(n,&count);

    imprimeixvector(count,v);

    return 0;
}

int is_prime(int n){ //Retorna 1 si és primer i 0 si no ho és.
    for(int i=2;i<n;i++){
        if(n%i==0)
            return 0;
    }
    return 1;
}
int next_prime(int n){
    int p=n+2;
    while(is_prime(p)!=1)
        p++;
    return p;
}
int *factor(int n,int *count){
    int *v,N=n;
    v=(int*)malloc(sizeof(int));
    int i=2;
    while(i<N+1){
        if(is_prime(n)==1){
            v[*count]=n;
            (*count)++;
            return v;
        }else if(n%i==0){
            v=(int*)realloc(v,((*count)+1)*sizeof(int));
            v[*count]=i;
            (*count)++;
            n/=i;
        }else
            i=next_prime(i);
    }
    return v;
}
void imprimeixvector(int dim,int v[]){
    for(int i=0;i<dim;i++)
        printf("%d\n",v[i]);
}
