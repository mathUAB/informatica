#include <stdio.h>
#include <math.h>
#include <time.h>
#define step 1.e-2
#define max 1
#define zero 1.e-6

void readpoly(int deg,double v[deg+1]);
double evaluatepoly_normal(int deg,double v[deg+1],double a);
double evaluatepoly_horner(int deg,double v[deg+1],double a);

int main(){
    int n;
    clock_t t0,t1,t2;
    printf("Grau de polinomi: ");
    scanf("%d",&n);
    double v[n+1];
    readpoly(n,v);
    t0=clock();
    for(double i=-max;i<=max+zero;i+=step){
        printf("%g\t %g\n",i,evaluatepoly_normal(n,v,i));
    }
    t1=clock();
    printf("\n");
    for(double i=-max;i<=max+zero;i+=step){
        printf("%g\t %g\n",i,evaluatepoly_horner(n,v,i));
    }
    t2=clock();
    printf("\nTemps execucio normal: %lf segons\n",(double)(t1-t0)/CLOCKS_PER_SEC);
    printf("Temps execucio horner: %lf segons\n",(double)(t2-t1)/CLOCKS_PER_SEC);
    return 0;
}

void readpoly(int deg,double v[deg+1]){
    for(int i=0;i<=deg;i++){
        printf("a%d= ",i);
        scanf("%lf",&v[i]);
    }
}

double evaluatepoly_normal(int deg,double v[deg+1],double a){
    double p_a=0;
    for(int i=0;i<=deg;i++)
        p_a+=v[i]*pow(a,i);
    return p_a;
}

double evaluatepoly_horner(int deg,double v[deg+1],double a){
    double p_a=v[deg];
    for(int i=deg;i>0;i--)
        p_a=v[i-1]+a*p_a;
    return p_a;
}
