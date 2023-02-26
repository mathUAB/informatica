#include <stdio.h>
#include <math.h>

double a(int n);

int main(){
    int n;

    printf("Entern the n-th term of the successions: ");
    scanf("%d",&n);

    for(int i=1;i<=n;i++)
        printf("an=%.15lf\n",a(i));

    return 0;
}

double a(int n){
    double an;
    double prod=1.;

    for(int k=1;k<=n;k++)
        prod*=pow(1+k,k/n);
    an=prod/(pow(n,(n+1)/2));
    return an;
}
