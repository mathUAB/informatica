#include <stdio.h>

int main(){
    FILE *fitxer;
    double a,b,c,d;
    fitxer=fopen("4columnes.dat","r");
    if(fitxer==NULL){
        fprintf(stderr,"ERROR: El fitxer '4columnes.dat' no es pot obrir...\n\n");
        return 1;
    }
    printf("\n");
    while(EOF!=fscanf(fitxer,"%lf%lf%lf%lf",&a,&b,&c,&d))
        printf("%.6lf\t%.6lf\t%.6lf\t%.6lf\n",1/a,1/b,1/c,1/d);
    fclose(fitxer);
    return 0;
}
