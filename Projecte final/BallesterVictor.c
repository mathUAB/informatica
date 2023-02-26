#include <stdio.h>
#include <math.h>
#include <stdlib.h>

#define PI 3.141592653589793
#define TOL 1.e-6

typedef struct{
    unsigned int *vect;
    unsigned int long_vect;
}llista;

void alliberar_memoria(double v1[][3],llista *v2,llista *v3);
void afegeix(int n,llista *list);
int contadorlinies(char *fitxer);
void copiarvector(double u[],double v[]);
double producteescalar(double u[],double v[]);
double norma(double u[]);
double det(double u[],double v[],double w[]);
double base(double u[],double v[],double w[]);/*No necessària per al programa*/
double Angle(double u[],double v1[],double v2[]);
double perpendiculars(double u[],double v[]);/*No necessària per al programa*/
void projeccioortogonal(double u[],double v[],double w[]);
void ortonormalgramschmidt(double u[],double v[],double w[]);/*No necessària per al programa*/
void productevectorial(double u[],double v[],double w[]);
int projectacon(int n,double u[],double v[][3],double proj[][3]);
int tipus2d(double v[][3],int n,double u[],llista *vmin);
int tipus3d(double v[][3],int n,llista *vmin);

int main(int argc,char *argv[]){
    //system("chcp 65001 > nul"); //Per corregir els accents en Windows.
    FILE *entrada,*sortida;
    int i=0,n;
    double (*v)[3];
    llista *vmin;
    /*Obro el fitxer d'entrada.*/
    entrada=fopen(argv[1],"r");
    if(entrada==NULL){
        fprintf(stderr,"Error en el fitxer d'entrada.\n");
        return 1;
    }
    n=contadorlinies(argv[1]);
    /*Reservo memòria per v (on emmagatzerem tots els vectors).*/
    v=(double(*)[3])malloc(n*3*sizeof(double));
    if(v==NULL){
        printf("No hi ha suficient memòria per %d vectors.\n",n);
        return 1;
    }
    /*LLegeixo els vectors del fitxer d'entrada.*/
    while(EOF!=fscanf(entrada,"%lf,%lf,%lf",&v[i][0],&v[i][1],&v[i][2])){
        if(v[i][0]==0 && v[i][1]==0 && v[i][2]==0){
            printf("Els vectors han de ser no nuls!\n");
            free(v);
            return 1;
        }
        i++;
    }
    fclose(entrada);
    /*Reservo memòria per vmin (on emmagatzerem els índexs dels vectors minimals).*/
    vmin=(llista *)calloc(1,sizeof(llista));
    vmin->vect=(unsigned int *)malloc(n*sizeof(unsigned int));
    if(vmin==NULL || vmin->vect==NULL){
        printf("No hi ha suficient memòria per %d vectors.\n",n);
        free(v);
        return 1;
    }
    printf("S'ha llegit un con generat per %d vectors no nuls.\n",n);
    int tip=tipus3d(v,n,vmin);
    switch(tip){
        case 0:
            printf("És l'espai {0}.\nNo hi ha un sistema minimal de vectors.");
            alliberar_memoria(v,vmin,NULL); //NULL no fa res (és com si no hi hagués aquest paràmetre).
            return 0;
        case 1:
            printf("És una semirecta.");
            break;
        case 2:
            printf("És una recta.");
            break;
        case 3:
            printf("És un angle de pla.");
            break;
        case 4:
            printf("És un semiplà.");
            break;
        case 5:
            printf("És un pla.");
            break;
        case 6:
            printf("És un con polièdric amb %u arestes.",vmin->long_vect);
            break;
        case 7:
            printf("És un angle dièdric.");
            break;
        case 8:
            printf("És un semiespai.");
            break;
        case 9:
            printf("És tot l'espai.");
            break;
        default:        //És necessari per l'assignació de memòria a la funció tipus3d, ja que retorna l'enter 10.
            alliberar_memoria(v,vmin,NULL); //NULL no fa res (és com si no hi hagués aquest paràmetre).
            return 1;
    }
    /*Escric els resultat per pantalla.*/
    printf("\nUn sistema minimal de vectors és: ");
    for(i=0;i<vmin->long_vect;i++){
        printf("v_%u",vmin->vect[i]+1);     //Els vectors comencen numerats des de 1, i.e., (v1,v2,...)
        if(i!=vmin->long_vect-1)
            printf(", ");
    }
    printf("\n");
    /*Obro el fitxer de sortida.*/
    sortida=fopen(argv[2],"w");
    if(sortida==NULL){
        fprintf(stderr,"Error en el fitxer de sortida. No s'imprimiran els vectors en un fitxer.\n");
        alliberar_memoria(v,vmin,NULL); //NULL no fa res (és com si no hi hagués aquest paràmetre).
        return 1;
    }
    /*Escric els resultat al fitxer de sortida.*/
    for(i=0;i<vmin->long_vect;i++)
        fprintf(sortida,"%lf, %lf, %lf\n",v[vmin->vect[i]][0],v[vmin->vect[i]][1],v[vmin->vect[i]][2]);
    fclose(sortida);
    alliberar_memoria(v,vmin,NULL); //NULL no fa res (és com si no hi hagués aquest paràmetre).
    return 0;
}
void alliberar_memoria(double v1[][3],llista *v2,llista *v3){
    /*Funció per alliberar memòria.*/
    free(v1);
    free(v2);
    free(v3);
}
void afegeix(int n,llista *list){
    /*Afegeix l'elelment "n" a la llista "list".*/
    list->vect[list->long_vect]=n;
    list->long_vect++;
}
int contadorlinies(char *fitxer){
    FILE *doc;
    int c='\0',pc='\n';
    int linies=0;

    doc=fopen(fitxer,"r");
    if(doc==NULL)
        return 0;
    while(c=fgetc(doc),c!=EOF){
        if(c=='\n' && pc!='\n')
            linies++;
        pc=c;
    }
    if(pc!='\n')//Això ho faig perquè a vegades no es clica intro a l'última línia.
        linies++;
    fclose(doc);
    return linies;
}
void copiarvector(double u[],double v[]){
    //Copiar el vector u al vector v.
    for(int i=0;i<3;i++)
        v[i]=u[i];
}
double producteescalar(double u[],double v[]){
    double prod=0;
    for(int i=0;i<3;i++)
        prod+=u[i]*v[i];
    return prod;
}
double norma(double u[]){
    return sqrt(producteescalar(u,u));
}
double det(double u[],double v[],double w[]){
    //Regla de Cramer.
    return u[0]*v[1]*w[2]+u[1]*v[2]*w[0]+u[2]*v[0]*w[1]-u[2]*v[1]*w[0]-u[1]*v[0]*w[2]-u[0]*v[2]*w[1];
}
double base(double u[],double v[],double w[]){
    //Regla de Cramer. Retorna 1 si formen base i 0 si no la formen.
    if(det(u,v,w)==0)
        return 0;
    else
        return 1;
}
double Angle(double u[],double v1[],double v2[]){
    //Retorna l'angle ente v1 i v2 en radians amb signe positiu o negatiu segons el signe del determinant dels vectors u,v1,v2 escrits en columna.
    double ang=producteescalar(v1,v2)/(norma(v1)*norma(v2));
    if(ang<-1)
        ang=-1;
    else if(ang>1)
        ang=1;
    ang=acos(ang);
    if(ang<TOL)
        ang=0;
    if(det(u,v1,v2)<0)
        return -ang;
    else
        return ang;
}
double perpendiculars(double u[],double v[]){
    //Retorna 1 si els vectors són perpendiculars i 0 si no ho són.
    if(fabs(producteescalar(u,v))<TOL)
        return 1;
    else
        return 0;
}
void projeccioortogonal(double u[],double v[],double w[]){
    //Projeccio ortogonal de u i v emmagatzemat a w si u no és el vector zero.
    for(int i=0;i<3;i++)
        w[i]=v[i]-producteescalar(u,v)*u[i]/producteescalar(u,u);
}
void ortonormalgramschmidt(double u[],double v[],double w[]){
    //S'entren tres vectors que formen basi i es retorna la base ortonormal de Gram-Schmidt.
    int i;
    double u1[3],u2[3],u3[3],u31[3];
    if(base(u,v,w)==0){
        printf("Els vectors no formen base.");
        return;
    }
    projeccioortogonal(u,v,u2);
    projeccioortogonal(u,w,u3);
    projeccioortogonal(u2,w,u31);

    for(i=0;i<3;i++){
        u3[i]=u3[i]+u31[i]-w[i];
        u1[i]=u[i];
    }

    for(i=0;i<3;i++){
        u[i]=u1[i]/norma(u1);
        v[i]=u2[i]/norma(u2);
        w[i]=u3[i]/norma(u3);
    }
}
void productevectorial(double u[],double v[],double w[]){
    //Producte vectorial de u i v emmagatzemat a w.
    w[0]=u[1]*v[2]-u[2]*v[1];
    w[1]=u[2]*v[0]-u[0]*v[2];
    w[2]=u[0]*v[1]-u[1]*v[0];
}
int projectacon(int n,double u[],double v[][3],double proj[][3]){
    int k=0;
    for(int i=0;i<n;i++){
        projeccioortogonal(u,v[i],proj[i-k]);
        if(fabs(proj[i-k][0])<TOL && fabs(proj[i-k][1])<TOL && fabs(proj[i-k][2])<TOL)
            k++;
    }
    return n-k;
}
int tipus2d(double v[][3],int n,double u[],llista *vmin){
    int i,j;
    int dr,esq;
    double anglemax;
    vmin->long_vect=0;
    if(n==0)
        return 0; //{0}.
    if(n==1){
        afegeix(0,vmin);
        return 1; //Semirecta.
    }
    double (*angle)[n];
    /*Reservo memòria*/
    angle=(double(*)[n])malloc(n*n*sizeof(double));
    if(angle==NULL){
        printf("No hi ha suficient memòria per %d vectors.\n",n);
        return 10;
    }
    /*Miro quin és l'angle maxim entre totes les parelles de vectors.*/
    dr=0;
    esq=1;
    anglemax=Angle(u,v[0],v[1]);
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            angle[i][j]=Angle(u,v[i],v[j]);
            if(angle[i][j]>anglemax){
                dr=i;
                esq=j;
                anglemax=angle[i][j];
            }
        }
    }
    if(anglemax==0){
        afegeix(0,vmin);
        free(angle);
        return 1; //Semirecta.
    }
    afegeix(dr,vmin);
    if(anglemax<PI-TOL){
        afegeix(esq,vmin);
        for(i=0;i<n;i++){
            if(angle[dr][i]<0){
                afegeix(i,vmin);
                free(angle);
                return 5; //Pla.
            }
        }
        free(angle);
        return 3; //Angle de pla.
    }
    //if anglemax==PI
    for(i=0;i<n;i++){
        if(angle[dr][i]!=0 && fabs(angle[dr][i])<PI-TOL){ //El "vmin->long_vect<3" és perquè només entri una vegada al bucle.
            afegeix(i,vmin);
            for(j=0;j<n;j++){
                if(angle[dr][i]*angle[dr][j]<0 && fabs(angle[dr][j])<PI-TOL){//Han de tenir signe contrari.
                    afegeix(j,vmin);
                    if(fabs(angle[i][j]-PI)<TOL && fabs(angle[dr][i]-PI/2)<TOL)
                        afegeix(esq,vmin);
                    free(angle);
                    return 5; //Pla.
                }
            }
            break;
        }
    }
    free(angle);
    afegeix(esq,vmin);
    if(vmin->long_vect==3)          //i.e. si ha entrat al bucle anterior...retorna 4.
        return 4; //Semiplà.
    return 2; //Recta.
}
int tipus3d(double v[][3],int n,llista *vmin){
    int i,j,m,tip;
    int repetit;
    double perp[3];
    if(n==0)
        return 0;//{0}.
    if(n==1){
        afegeix(0,vmin);
        return 1;//Semirecta.
    }
    double (*w)[3];
    llista *wmin,*vcares;
    /*Reservo memòria*/
    /*Inicialitzo les variables de longitud a 0 amb calloc*/
    w=(double(*)[3])malloc(n*3*sizeof(double));
    wmin=(llista *)calloc(1,sizeof(llista));
    wmin->vect=(unsigned int *)malloc(3*sizeof(unsigned int));
    vcares=(llista *)calloc(1,sizeof(llista));
    vcares->vect=(unsigned int *)malloc(n*sizeof(unsigned int));
    if(w==NULL || wmin==NULL || wmin->vect==NULL || vcares==NULL || vcares->vect==NULL){
        printf("No hi ha suficient memòria per %d vectors.\n",n);
        return 10;
    }
    vmin->long_vect=0;
    m=projectacon(n,v[0],v,w);                  //Projecció ortogonal sobre v[0]. Els w's son perpendiculars a v[0].
    if(m==0){
        for(i=0;i<n;i++){
            if(producteescalar(v[0],v[i])<0){   //i.e. si els vectors tenen sentits oposats.
                afegeix(0,vmin);
                afegeix(i,vmin);
                alliberar_memoria(w,wmin,vcares);
                return 2;//Recta.
            }
        }
        afegeix(0,vmin);
        alliberar_memoria(w,wmin,vcares);
        return 1;//Semirecta.
    }
    tip=tipus2d(w,m,v[0],wmin);                 //Com a molt tip=2 en el cas que sigui el con sigui de 2D.
    if(tip==10){             //No hi ha hagut memòria.
        alliberar_memoria(w,wmin,vcares);
        return 10;
    }
    if(tip<3){
        productevectorial(v[0],w[0],perp);
        alliberar_memoria(w,wmin,vcares);
        return tipus2d(v,n,perp,vmin);
    }
    //Con de dimensió 3:
    for(i=0;i<n;i++){
        m=projectacon(n,v[i],v,w);
        tip=tipus2d(w,m,v[i],wmin);
        /*Sabem que si tip= 3->v[i] és un aresta
                          = 4->v[i] és una cara*/
        if(tip==3){
            //Si l'aresta no l'havíem afegit a vmin l'afegim, ja que segur que serà un vector minimal.
            repetit=0;
            for(j=0;j<vmin->long_vect;j++){
                if(Angle(v[i],v[i],v[vmin->vect[j]])==0) //El determinant (calculat dins la funció Angle) donarà 0 i, per tant, ens retornarà l'angle positiu.
                    repetit=1;
            }
            if(repetit==0)
                afegeix(i,vmin);
        }
        if(tip==4)
            afegeix(i,vcares);
        if(tip==10){             //No hi ha hagut memòria.
            alliberar_memoria(w,wmin,vcares);
            return 10;
        }
    }
    if(vmin->long_vect>2){
        alliberar_memoria(w,wmin,vcares);
        return 6; //Con polièdric.
    }
    if(vmin->long_vect==2){ //Els dos vectors de vmin són vectors oposats.
        /*Cal agafar dos vectors de vcares que no pertanyin a la mateixa cara.*/
        copiarvector(v[vmin->vect[0]],perp); //El vector vmin->vect[0] és perpendicular a qualsevol vector cara.
        afegeix(vcares->vect[0],vmin);
        projeccioortogonal(perp,v[vcares->vect[0]],w[0]);
        for(i=1;i<vcares->long_vect;i++){
            projeccioortogonal(perp,v[vcares->vect[i]],w[1]);
            if(Angle(w[0],w[0],w[1])!=0){ //El determinant (calculat dins la funció Angle) donarà 0 i, per tant, ens retornarà l'angle positiu.
                afegeix(vcares->vect[i],vmin);
                alliberar_memoria(w,wmin,vcares);
                return 7; //Con dièdric.
            }
        }
    }
    if(vcares->long_vect>0){
        j=n-1;
        for(i=0;i<vcares->long_vect;i++){
            copiarvector(v[vcares->vect[i]],w[i]);
            if(Angle(w[0],w[0],w[i])>0 && Angle(w[0],w[0],w[i])<PI-TOL) //El determinant (calculat dins la funció Angle) donarà 0 i, per tant, ens retornarà l'angle positiu.
                productevectorial(w[0],w[i],perp);
            if(j==n-1 && vcares->vect[i]>i)
                j=i; //Vector interior al con.
        }
        tip=tipus2d(w,vcares->long_vect,perp,wmin); //Obtenim els generados del pla i els coleccionem dins vmin.
        if(tip==10){             //No hi ha hagut memòria.
            alliberar_memoria(w,wmin,vcares);
            return 10;
        }
        for(i=0;i<vcares->long_vect;i++)
            afegeix(vcares->vect[wmin->vect[i]],vmin); //Col·loquem bé els vectors.
        afegeix(j,vmin); //Afegim el vector interior al con.
        alliberar_memoria(w,wmin,vcares);
        return 8; //Semiespai.
    }
    for(i=0;i<n-1;i++)
        copiarvector(v[i+1],w[i]);//Copio tots els vectors de v menys el primer a w.
    i=0;
    while(tipus3d(w,n-1,vmin)<9){//No es pot treure v[i].
        copiarvector(v[i],w[i]);//Ara el vector v[i+1] no està a w.
        i++;
        if(i==n){
            afegeix(n-1,vmin);
            alliberar_memoria(w,wmin,vcares);
            return 9;//Tot l'espai.
        }
    }
    for(j=i;j<vmin->long_vect;j++) //Es comença des de j=i, perquè a partir de la posició i-essima els vectors estan desplaçats una posició cap endavant.
        vmin->vect[j]++; //Col·loco bé els vectors.
    alliberar_memoria(w,wmin,vcares);
    return 9;//Tot l'espai.
}
