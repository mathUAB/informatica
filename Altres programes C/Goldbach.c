#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#define TOL 1.e-6

int is_prime(int n);
int next_prime(int n);
int Goldbach(int n,int (*v)[2]);

int main(){
    int n=34, (*v)[2];
    v=(int(*)[2])malloc(2*sizeof(int));
    if(v==NULL)
        return 1;
    int gold=Goldbach(n,v);

    for(int i=0;i<gold;i++)
        printf("%d=%d+%d\n",n,v[i][0],v[i][1]);
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
int Goldbach(int n,int (*v)[2]){
    int count=0;
    int i=3;
    while(i<=(int)n/2){
        if(is_prime(n-i)==1 && (n-i)!=2){
            count++;
            v=(int(*)[2])realloc(v,(count+1)*2*sizeof(int));
            if(v==NULL)
                return 0;
            v[count-1][0]=i;
            v[count-1][1]=n-i;
        }
        i=next_prime(i);
    }
    return count;
}
