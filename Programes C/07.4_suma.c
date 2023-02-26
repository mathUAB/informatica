#include <stdio.h>

int main(int argc,char *argv[]){
    FILE *fitxer;
    double a,b,c,d;
    double sum1=0,sum2=0,sum3=0,sum4=0;
    fitxer=fopen("4columnes.dat","r");
    if(fitxer==NULL){
        fprintf(stderr,"ERROR: El fitxer 'columnes.dat' no es pot obrir...\n\n");
        return 1;
    }
    while(EOF!=fscanf(fitxer,"%lf%lf%lf%lf",&a,&b,&c,&d)){
        sum1+=a;
        sum2+=b;
        sum3+=c;
        sum4+=d;
    }
    printf("%g %g %g %g\n",sum1,sum2,sum3,sum4);
    fclose(fitxer);
    return 0;
}
