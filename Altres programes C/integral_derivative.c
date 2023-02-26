#include <stdio.h>
#include <math.h>

double f(double x);
double riemann_integral(double a,double b);
double derivative(double a);
double max_function(double a,double b,unsigned int N);
double mid_function(double a,double b);

int main(){

    printf("%.15lf,%.15lf",riemann_integral(0,5),derivative(4));

    return 0;
}

double f(double x){
    return exp(x);
}

double riemann_integral(double a,double b){
    unsigned int N=100000;
    double riemann_sum=0;
    for(int k=0;k<N;k++)
        riemann_sum+=mid_function(a+(b-a)*k/N,a+(b-a)*(k+1)/N)*(b-a)/N;
    return riemann_sum;
}

double derivative(double a){
    double h=1e-6;
    return (f(a+h)-f(a))/h;
}

double max_function(double a,double b,unsigned int N){
    double max=f(a);
    double y;
    for(double k=a;k<=b;k+=(b-a)/N){
        y=f(k);
        if(y>max)
            max=y;
    }
    return max;
}

double mid_function(double a,double b){
    return f((a+b)/2);
}

