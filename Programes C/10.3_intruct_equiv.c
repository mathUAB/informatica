#include <stdio.h>
#include <math.h>
int main(){
    double x,incr,decr,prod;

    printf("Escriu un nombre real: ");
    scanf("%lf",&x);
    incr=x+1;
    decr=x-1;
    prod=incr*decr;
    printf("\n(%g-1)(%g+1)=%g\n",x,x,prod);
    prod=(incr=x+1)*(incr-2);
    printf("\n(%g-1)(%g+1)=%g\n",x,x,prod);

    short int z=12789,y;
    y=(z/255)+(z&255);
    printf("\n%d\n",y);
    return 0;
}
