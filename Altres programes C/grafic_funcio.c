#include <stdio.h>
#include <math.h>
#define TOL 0.005
#define pixels 10240

double f(double x);
int main(){
    FILE *fitxer;
    double ax=-1,bx=1,fa=-1,fb=1,x,y;
    double incrX=(bx-ax)/pixels,incrY=(fb-fa)/pixels;
    unsigned char negre[]={0,0,0};
    unsigned char blanc[]={255,255,255};
    fitxer=fopen("funcio.ppm","wb");
    fprintf(fitxer,"P6\n#f(x)=x^2\n%d\n%d\n%d\n",pixels,pixels,255);
    if(fitxer==NULL){
        fprintf(stderr,"Error en el fitxer de sortida.\n");
        return 1;
    }
    for(y=fb;y>fa;y-=incrY){
        for(x=ax;x<bx;x+=incrX)
            if(fabs(y-f(x))<TOL)
                fwrite(negre,3,1,fitxer);
            else
                fwrite(blanc,3,1,fitxer);
    }
    fclose(fitxer);
    return 0;
}

double f(double x){
    return sin(1/x);
}
