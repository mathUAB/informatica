#include <stdio.h>

int main(){
    double a[2][3],b[2][3];
    int i,j;
    printf("Escriu els coeficient aij de la primera matriu:\n");
    for(i=0;i<2;i++){
        for(j=0;j<3;j++){
            printf("a%i%i= ",i+1,j+1);
            scanf("%lf",&(a[i][j]));
        }
    }
    printf("Escriu els coeficient bij de la segona matriu:\n");
    for(i=0;i<2;i++){
        for(j=0;j<3;j++){
            printf("b%i%i= ",i+1,j+1);
            scanf("%lf",&(b[i][j]));
        }
    }
    for(i=0;i<2;i++){
        for(j=0;j<3;j++){
            printf("%g\t",a[i][j]+b[i][j]);
        }
        printf("\n");
    }

    return 0;
}

