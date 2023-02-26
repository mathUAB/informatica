#include <stdio.h>
#include <complex.h>
#include <tgmath.h>
#include <math.h>
#define maxiter 200

int main(){
    double xmin,xmax,ymin,ymax;
    unsigned int pixels;
    printf("Escriu l'interval de la part real del nombre complex: ");
    scanf("%lf%lf",&xmin,&xmax);
    printf("Escriu l'interval de la part imaginaria del nombre complex: ");
    scanf("%lf%lf",&ymin,&ymax);
    printf("Escriu la quantitat de pixels en que es divideix el rectangle: ");
    scanf("%u",&pixels);
    double increment=(xmax-xmin)/pixels;
    complex double w,z;
    double x,y;
    int k;
    char *nomfitxer="Julia.ppm";
    FILE *fitxer=fopen(nomfitxer,"wb");
    unsigned char negre[]={0,0,0};
    fprintf(fitxer," P6\n# Conjunt de Mandelbrot \n%d\n%d\n%d\n",pixels,pixels,255);
    for(y=ymax;y>ymin;y-=increment){
        for(x=xmin;x<xmax;x+=increment){
            w=x+y*I;
            z=w;
            for(k=1;k<maxiter && (cabs(z)<2.0);k++){
                z=exp(z*z*z)-0.59;
            }
            unsigned char color[]={255*sqrt(k)/sqrt(200),255*sqrt(k)/sqrt(200),255};
            if(k>=maxiter)
                fwrite(negre,3,1,fitxer);
            else
                fwrite(color,3,1,fitxer);
        }
    }
    fclose(fitxer);
    return 0;
}
