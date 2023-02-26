#include <stdio.h>
void calculs(double x,double y,double *suma,double *resta,double *prod,double *quoc);

int main(){
    double x,y;
    double suma,resta,prod,quoc;

    printf("Entra x i y separats per una coma: ");
    scanf("%lf,%lf",&x,&y);

    calculs(x,y,&suma,&resta,&prod,&quoc);

    printf("La suma es: %lf\n",suma);
    printf("La resta es: %lf\n",resta);
    printf("El producte es: %lf\n",prod);
    printf("El quocient es: %lf\n",quoc);

    return 0;
}

void calculs(double x,double y,double *suma,double *resta,double *prod,double *quoc){
    *suma=x+y;
    *resta=x-y;
    *prod=x*y;
    *quoc=x/y;
}
