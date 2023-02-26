#include <stdio.h>
#include <math.h>


int numcomb(int m, int n);

int main(){
    int m,n,r;

    printf("Escriu dos valors enters m i n amb m>=n: ");
    scanf("%i%i",&m,&n);
    if (m<n){
        printf("Error!");
    }
    if(m<=2*n){
        printf("El nombre combinatori de m i n és: %i",numcomb(m,n));
    }
    else{
        printf("El nombre combinatori de m i n és: %i",numcomb(m,m-n));
    }
    return 0;
}

int numcomb(int m, int n){
    int i,comb=1;
    for(i=0;i<=m-n-1;i++){
        comb*=(m-i)/(m-n-i);
    }
    return comb;
}
