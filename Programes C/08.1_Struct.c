#include <stdio.h>
#include <math.h>

struct punt2D{
    double x;
    double y;
};

typedef struct{
    double x;
    double y;
    double z;
}punt3D;

int main(){
    struct punt2D p2D;
    struct punt2D ps2D [10];
    punt3D p3D;
    punt3D ps3D[4][4];
    int i,j;

    printf("Entra un valor per la coordenada x de p2D: ");
    scanf("%lf",&p2D.x);
    printf("Entra un valor per la coordenada y de p2D: ");
    scanf("%lf",&p2D.y);

    printf("p té coordenades (%g,%g)\n",p2D.x,p2D.y);

    for (i=0;i<10;i++){
        ps2D[i].x =1/(i+1.);
        ps2D[i].y=sin(ps2D[i].x)/ps2D[i].x;
    }
    for(i=0;i<10;i++)
        printf("ps2D[%d] te coordenades (%g,%g)\n",i,ps2D[i].x,ps2D[i].y);

    printf("Entra un valor per la coordenada x de p3D: ");
    scanf("%lf",&p3D.x);
    printf("Entra un valor per la coordenada y de p3D: ");
    scanf("%lf",&p3D.y);
    printf("Entra un valor per la coordenada z de p3D: ");
    scanf("%lf",&p3D.z);
    printf("p3D te coordenades (%g,%g,%g)\n",p3D.x,p3D.y,p3D.z);

    for(i=0;i<4;i++){
        for(j=0;j<4;j++){
            ps3D[i][j].x=(double) i;
            ps3D[i][j].y=(double) j;
            ps3D[i][j].z=(double) i*i+j*j;
        }
    }
    for(i=0;i<4;i++){
        for(j=0;j<4;j++)
            printf("ps3D[%d] te coordenades (%g,%g,%g)\n",i,ps3D[i][j].x,ps3D[i][j].y,ps3D[i][j].z);
    }
    return 0;
}
