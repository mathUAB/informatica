#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#define TOL 1.e-6

int is_prime(int n);
int next_prime(int n);
int Goldbach(int n);

int main(){
    for(int k=3;k<2000;k++)
        printf("%d\t%d\n",k,Goldbach(2*k));
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
int Goldbach(int n){
    int count=0;
    int i=3;
    while(i<=(int)n/2){
        if(is_prime(n-i)==1 && (n-i)!=2)
            count++;
        i=next_prime(i);
    }
    return count;
}
