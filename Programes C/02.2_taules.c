#include <stdio.h>
#include <math.h>


void taula(int n);

int main(){
    int n;

    for (n=1;n<=10;n++){
        taula(n);
        printf("\n");
    }
    return 0;
}

void taula(int n){
    int j;
    for (j=0;j<=10;j++){
        printf("%ix%i=%i\n",n,j,n*j);
    }
}
