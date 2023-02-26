#include <stdio.h>
#include <stdlib.h>
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
    struct punt2D *pts2D;
    punt3D *pts3D;
    pts2D=(struct punt2D *) malloc(3*sizeof(struct punt2D));
    if(pts2D==NULL){
        printf("No s’ha pogut reservar la memoria.\n");
        return 1;
    }
    pts3D=(punt3D *) malloc(sizeof(punt3D));
    if(pts3D==NULL){
        printf("No s’ha pogut reservar la memoria\n");
        return 1;
    }
    pts2D->x =0.1;
    pts2D->y =1.34;
    printf("El punt2D %d val (%g,%g)\n",0,pts2D->x,pts2D->y);
    (pts2D+1)->x =1.4;
    (pts2D+1)->y=23.2;
    printf("El punt2D %d val (%g,%g)\n",1,(pts2D+1)->x,(pts2D+1)->y);
    (pts2D+2)->x =2.4;
    (pts2D+2)->y=31.2;
    printf("El punt2D %d val (%g,%g)\n",2,(pts2D+2)->x,(pts2D+2)->y);
    pts3D->x=0.2;
    pts3D->y=1.3;
    pts3D->z=2.5;
    printf("El punt3D %d val (%g,%g,%g)\n",0,pts3D->x,pts3D->y,pts3D->z);
    free (pts2D);
    free (pts3D);
    return 0;
}
