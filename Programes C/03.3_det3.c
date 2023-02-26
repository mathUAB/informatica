#include <stdio.h>
#include <math.h>

int main(){
    double a[3][3],det,c1,c2,c3;
    int i,j;
    printf("Escriu els coeficient aij de la matriu:\n");
    for(i=0;i<3;i++){
        for(j=0;j<3;j++){
            printf("a%i%i= ",i+1,j+1);
            scanf("%lf",&(a[i][j]));
        }
    }
    c3=a[1][0]*a[2][1]-a[2][0]*a[1][1];
    c2=a[1][0]*a[2][2]-a[2][0]*a[1][2];
    c1=a[1][1]*a[2][2]-a[2][1]*a[1][2];
    det=a[0][0]*c1-a[0][1]*c2+a[0][2]*c3;
    printf("El determinant de la matriu és %g.\n",det);
    if(det>0){
        printf("Log(det)=%g",log(det));
    }
    return 0;
}
