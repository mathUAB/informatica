#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int contadorlinies(char *fitxer);
int longitudlinies(char *fitxer);
void joc_de_la_vida(int N,char mat[N][N]);
int veins_vius(int i,int j,int N,char mat[N][N]);
int mod(int a,int m);
void printMatrix(int n,char A[n][n]);

int main(int argc,char *argv[]){
    FILE *fitxer;
    int i,j,c,f;
    int N=10;
    char mat[N][N];
    fitxer=fopen(argv[1],"r");
    if(fitxer==NULL){
        fprintf(stderr,"Error en el fitxer d'entrada.\n");
        return 1;
    }

    /*En el fitxer escriu una matriu de caracters seguits " " o "o" de tamany <10*/
    c=longitudlinies(argv[1]);
    f=contadorlinies(argv[1]);
    /*Creem la matriu*/
    for(i=0;i<N;i++){
        for(j=0;j<N;j++){
            if(i<f && j<c)
                mat[i][j]=fgetc(fitxer);
            else
                mat[i][j]=' ';
        }
        fgetc(fitxer); //Ho faig perquè em detecti ara el caracter '\n'.
    }
    fclose(fitxer);
    do{
        system("cls");
        printMatrix(N,mat);
        joc_de_la_vida(N,mat);
        printf("Prem Intro per la seguent generacio; Ctrl-C (en Windows) per acabar.\n");
    }while(getchar()!= EOF);
}

int contadorlinies(char *fitxer){
    FILE *doc;
    int c='\0',pc='\n';
    unsigned int linies=0;

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

int longitudlinies(char *fitxer){
    FILE *doc;
    int c='\0';
    unsigned int len=0;

    doc=fopen(fitxer,"r");
    if(doc==NULL)
        return 0;
    while(c=fgetc(doc),c!='\n')
        len++;
    fclose(doc);
    return len;
}

void joc_de_la_vida(int N,char mat[N][N]){
    int canviats[N*N][2]; //Emmagatzemo les parelles (i,j) que he de canviar de la matriu.
    int cnt=0,vei,i,j;
    /*Miro quins elements cal canviar*/
    for(i=0;i<N;i++){
        for(j=0;j<N;j++){
            vei=veins_vius(i,j,N,mat);
            if((mat[i][j]=='o' && (vei<2 || vei>3)) || (mat[i][j]==' ' && vei==3)){
                canviats[cnt][0]=i;
                canviats[cnt][1]=j;
                cnt++;
            }
        }
    }
    /*Canvio els elements*/
    for(i=0;i<cnt;i++){
        if(mat[canviats[i][0]][canviats[i][1]]=='o')
            mat[canviats[i][0]][canviats[i][1]]=' ';
        else
            mat[canviats[i][0]][canviats[i][1]]='o';
    }
}

int veins_vius(int i,int j,int N,char mat[N][N]){
    /*Treballem mòdul 10 per fer l'univers (matriu) infinit.*/
    int veins=0;
    for(int k=i-1;k<=i+1;k++){
        if(mat[mod(k,10)][mod(j-1,10)]=='o')
            veins++;
        if(mat[mod(k,10)][mod(j+1,10)]=='o')
            veins++;
    }
    if(mat[mod(i-1,10)][j]=='o')
        veins++;
    if(mat[mod(i+1,10)][j]=='o')
        veins++;
    return veins;
}

int mod(int a,int m){
    /*retorna a mod m, positiu*/
    int b=a%m;
    if(b<0)
        return m+b;
    return b;
}

void printMatrix(int n,char A[n][n]){
    int j;
    for(j=0;j<n;j++)
        printf(" -");
    printf("\n");
    for(int i=0;i<n;i++){
        for(j=0;j<n;j++)
            printf("|%c",A[i][j]);
        printf("|\n");
        for(j=0;j<n;j++)
            printf(" -");
        printf("\n");
    }
}
