#include <stdio.h>
#include <math.h>

#define PI 3.1415926535897932384626433

double f(double x);
double simpson(double a,double b);
double simpsoncompost(double a,double b,int n);

int main(){
    double a=0,b=2;

    printf("Valor aproximat: %lf\n",simpson(a,b));
    printf("Valor aproximat2: %lf\n",simpsoncompost(a,b,2));
    printf("Valor aproximat3: %lf\n",simpsoncompost(a,b,50));
    printf("Valor real: %lf",5*PI);
    return 0;
}

double simpson(double a,double b){
    return (b-a)/6*(f(a)+4*f((a+b)*0.5)+f(b));
}
double simpsoncompost(double a,double b,int n){
    double integral=0;
    double h=(b-a)/n;
    for(int i=0;i<n;i++)
        integral+=simpson(i*h,(i+1)*h);
    return integral;
}
double f(double x){
    return sqrt(100-25*x*x);
}
