#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define TOL 1.e-6
#define pixels 1024

int main(){
    system("chcp 65001 > nul");
    FILE *fitxer,*grafic;
    double (*mat)[6];
    double p,c,beta,T,mu,d,e,B,b;
    fitxer=fopen("sir.csv","w");
    if(fitxer==NULL){
        fprintf(stderr,"Error en el fitxer de sortida.\n");
        return 1;
    }
    mat=(double(*)[6])malloc(6*sizeof(double));
    if(mat==NULL){
        printf("No1 hi ha suficient memòria.\n");
        return 1;
    }
    //Columna 0: nascuts (Immunes).
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
    double N;     //Població (no constant).
    p=0.05;       //probabilitat en que en una trobada entre dos indivius (un contagiat i l'altre no) es produeixi el contagi.
    d=10.;         //nombre mitjà de trobades d'un indiviu/dia.
    T=15.;         //temps que dura la infecció.
    d=30.;         //temps mitjà d'immunitat.
    mu=0.05;      //probabilitat de què un infectat mori a causa de la malaltia.
    e=0.3;        //proporcio d'individus no infecciosos que passen a ser infecciosos/dia.
    B=10.5;       //Taxa de naixements (en tant per 1000).
    b=60.;         //Temps prommig d'immunitat infantil.
    double (*aux)[6];
    aux=mat;
    mat[0][0]=0.;
    mat[0][1]=600.;
    mat[0][2]=0.;
    mat[0][3]=1.;
    mat[0][4]=0.;
    mat[0][5]=0.;
    int t=0;

N=mat[t][0]+mat[t][1]+mat[t][2]+mat[t][3]-mat[t][4]+mat[t][5];
        printf("%.0lf,",N);
        c=0.5*d*N;       //nombre mitjà de trobades entre indivius de tota la població/dia.
        beta=c*p;
    /*Faig la taula de valors.*/
    while(mat[t][3]>N*0.01 || t<30){//s'acabarà quan només 0,0001% de la població estigui infectada.
        aux=(double(*)[6])realloc(aux,(t+2)*6*sizeof(double));
        if(aux==NULL){
            printf("No hi ha suficient memòria.\n");
            return 1;
        }
        mat=aux;


        mat[t+1][0]=mat[t][0]+B*N/(1000*365.24)-mat[t][0]/b;
        mat[t+1][1]=mat[t][1]+mat[t][0]/b-beta*mat[t][1]*mat[t][3]/(N*N)+mat[t][5]/d;
        mat[t+1][2]=mat[t][2]+beta*mat[t][1]*mat[t][3]/(N*N)-e*mat[t][2];
        mat[t+1][3]=mat[t][3]+e*mat[t][2]-mat[t][3]/T;
        mat[t+1][4]=mat[t][4]+mu*mat[t][3]/T;
        mat[t+1][5]=mat[t][5]+(1-mu)*mat[t][3]/T-mat[t][5]/d;
        t++;
    }
    for(int i=0;i<t;i++)
        //printf("%.2lf   %.2lf   %.2lf   %.2lf   %.2lf   %.2lf\n",mat[i][0],mat[i][1],mat[i][2],mat[i][3],mat[i][4],mat[i][5]);
        fprintf(fitxer,"%.0lf;%.0lf;%.0lf;%.0lf;%.0lf;%.0lf\n",mat[i][0],mat[i][1],mat[i][2],mat[i][3],mat[i][4],mat[i][5]);
    fclose(fitxer);
    /*Creo la gràfica.*/
    /*grafic=fopen("sir.ppm","wb");
    fprintf(grafic,"P6\n%d\n%d\n%d\n",pixels,pixels,255);
    if(grafic==NULL){
        fprintf(stderr,"Error en el fitxer de sortida.\n");
        return 1;
    }
    double N0=mat[0][0]+mat[0][1]+mat[0][2]+mat[0][3];
    double x,y;
    double incrX=1.*t/pixels,incrY=N0/pixels;
    unsigned char vermell[]={255,0,0};
    unsigned char verd[]={0,255,0};
    unsigned char groc[]={255,255,0};
    unsigned char negre[]={0,0,0};
    unsigned char blanc[]={255,255,255};
    for(y=N0;y>TOL;y-=incrY){
        for(x=0;x<t-TOL;x+=incrX){
            if(fabs(y-mat[(unsigned int) x][1])<N0/100)
                fwrite(groc,3,1,grafic);
            else if(fabs(y-mat[(unsigned int) x][3])<N0/100)
                fwrite(vermell,3,1,grafic);
            else if(fabs(y-mat[(unsigned int) x][4])<N0/100)
                fwrite(negre,3,1,grafic);
            else if(fabs(y-mat[(unsigned int) x][5])<N0/100)
                fwrite(verd,3,1,grafic);
            else
                fwrite(blanc,3,1,grafic);
        }
    }
    fclose(grafic);*/
    free(mat);
    return 0;
}

