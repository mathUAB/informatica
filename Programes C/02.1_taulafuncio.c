#include <stdio.h>
#include <math.h>
#define step 1.e-2
#define max 30
#define zero 1.e-6

double f(double i);

int main(){
    double i;

    for(i=-max;i<=max+zero;i=i+step){
        printf("%g\t %g\n",i,f(i));
    }
}

double f(double i){
    return (sin(i)+10.0)/(i*i+1.0);
}
