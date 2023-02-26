#include <stdio.h>
#include <math.h>
#define KMAX 10
#define TOL 1.e-6

void eval(double,double *,double *);
int main(){
    int k=0;
    double x,fx,dfx,d;

    printf("Valor de x: ");
    scanf("%lf",&x);
    printf("1-Interaccio: x=%lf\n",x);
    do{
        eval(x,&fx,&dfx);
        d=fx/dfx;
        x-=d;
        k++;
        printf("%d-Interaccio: x=%lf\n",k,x);
    }while((k<<KMAX) && (fabs(d)>=TOL));

    if(k>KMAX){
        printf("Problemes de convergencia:\n");
        printf("El metode no ha convergit en %d iteracions amb tolerancia %f.\n",KMAX,TOL);
    }else{
        printf("La solucio es: %lf.\nEl metode ha convergit en %d iteracions amb tolerancia %le.\n",x,k,fabs(d));
    }
    return 0;
}

void eval(double x,double *pfx,double *pdfx){
    *pfx=exp(-x)-sqrt(x);
    *pdfx=-exp(-x)-1/(2*sqrt(x));
}
