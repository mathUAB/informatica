#include <stdio.h>

int main(){
    double a[2][2]={{1,-2},{3,-1}};

    printf("El determinant és %g \n",a[0][0]*a[1][1]-a[0][1]*a[1][0]);
    return 0;
}
