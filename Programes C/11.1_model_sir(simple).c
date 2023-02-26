#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define TOL 1.e-8
#define pixels 1024

int main(){
    system("chcp 65001 > nul"); //Accents windows.
    FILE *fitxer,*grafic;
    double (*mat)[3];
    double p,c,B,T;
    fitxer=fopen("simple.csv","w");
    if(fitxer==NULL){
        fprintf(stderr,"Error en el fitxer de sortida.\n");
        return 1;
    }
    mat=(double(*)[3])malloc(3*sizeof(double));
    if(mat==NULL){
        printf("No1 hi ha suficient memòria.\n");
        return 1;
    }
    double (*aux)[3];
    aux=mat;
    mat[0][0]=7500000.;
    mat[0][1]=30.;
    mat[0][2]=0.;
    //Columna 1: susceptibles.
    //Columna 2: infectats no infecciosos (he suposat que necessàriament han de passar per l'estat de "infectats infecciosos" abans de morir o curar-se).
    //Columna 3: infectats infecciosos.
    //Columna 4: morts.
    //Columna 5: curats.
    /*printf("Introdueix el nombre de persones susceptibles inicials, el nombre de persones infectades inicials: ");
    scanf("%u%u",&mat[0][0],&mat[0][1]);
    //Reiterats, morts i curats inicials.
    mat[0][2]=0;
    mat[0][3]=0;
    mat[0][4]=0;
    printf("Introdueix la probabilitat que entre una trobada de dues persones (una infectada i l'altra no) es produeixi contagi: ");
    scanf("%lf",&p);
    printf("Introdueix el nombre mitjà de trobades entre individus per dia: ");
    scanf("%lf",&c);
    B=c*p;
    printf("Introdueix el temps mitjà d'infecció (en dies i major a 1): ");
    scanf("%lf",&T);
    if(mat[0][0]<0 || mat[0][1]<0 || mat[0][2]<0 || T<=1 || B<0 ||B>=mat[0][0]+mat[0][1]+mat[0][2]){
        printf("Error en la introducció de les dades.");
        return 1;
    }*/
    double N=mat[0][0]+mat[0][1]+mat[0][2];
    p=0.05;      //probabilitat en que en una trobada entre dos indivius (un contagiat i l'altre no) es produeixi el contagi.
    c=0.5*10*N;  //nombre mitjà de trobades entre indivius de tota la població/dia.
    B=p*c;
    T=15;        //temps que dura la infecció.
    int t=0;
    while(mat[t][1]>N*1.e-6 || t<100){//s'acabarà quan només 0,0001% de la població estigui infectada.
        aux=(double(*)[3])realloc(aux,(t+2)*3*sizeof(double));
        if(aux==NULL){
            printf("No hi ha suficient memòria.\n");
            return t+1;
        }
        mat=aux;
        mat[t+1][0]=mat[t][0]-B*mat[t][0]*mat[t][1]/(N*N);
        mat[t+1][1]=mat[t][1]+B*mat[t][0]*mat[t][1]/(N*N)-mat[t][1]/T;
        mat[t+1][2]=mat[t][2]+mat[t][1]/T;
        t++;
    }
    for(int i=0;i<t;i++)
        fprintf(fitxer,"%.0lf;%.0lf;%.0lf\n",mat[i][0],mat[i][1],mat[i][2]);
    fclose(fitxer);
    grafic=fopen("sir7.ppm","wb");
    fprintf(grafic,"P6\n%d\n%d\n%d\n",3*pixels,pixels,255);
    if(grafic==NULL){
        fprintf(stderr,"Error en el fitxer de sortida.\n");
        return 1;
    }
    double N0=mat[0][0]+mat[0][1]+mat[0][2];
    double x,y;
    double incrX=1.*t/(3*pixels),incrY=N0/pixels;
    unsigned char vermell[]={255,0,0};
    unsigned char verd[]={0,255,0};
    unsigned char groc[]={255,255,0};
    unsigned char blanc[]={255,255,255};
    for(y=N0;y>TOL;y-=incrY){
        for(x=0;x<t-TOL;x+=incrX){
            if(fabs(y-mat[(unsigned int) x][0])<N0/100)
                fwrite(groc,3,1,grafic);
            else if(fabs(y-mat[(unsigned int) x][1])<N0/100)
                fwrite(vermell,3,1,grafic);
            else if(fabs(y-mat[(unsigned int) x][2])<N0/100)
                fwrite(verd,3,1,grafic);
            else
                fwrite(blanc,3,1,grafic);
        }
    }
    fclose(grafic);
    free(mat);
    return 0;
}
