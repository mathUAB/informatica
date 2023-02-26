/**IMPRIMEIX FINS EL TERME n-ESSIM DE LA SUCCIESSIO DE CONWAY COM PUGUI.**/
#include <stdio.h>
#include <stdlib.h>

int main(int argc,char *argv[]){
    if(argc!=2){
        printf("S'ha d'especificar un nombre per el qual calcular el n-essim terme de la successió de Conway.\n");
        return 1;
   	}
    int n=atoi(argv[1]);

    char *an=(char *)malloc(2);
    char *am=(char *)malloc(2),*aux,c;
    int len=0,cnt,i;
    an[0]='1';
    an[1]='\0';
    if(n>=1)
        printf("a(1)=%s\n",an);
    for(i=2;i<=n && n>1 && (am=(char *)realloc(am,2*len+2));i++){
        /*aux apunta a an*/
        aux=an;
        /*Bucle per crear el a(n+1) terme*/
        for(len=0,cnt=1;(c=*an);){
            if(c==*++an)
                cnt++;
            else if(c){
                len+=sprintf(am+len,"%d%c",cnt,c);
                cnt=1;
            }
        }
        /*an apunta, ara, a am*/
        an=am;
        /*am apunta, ara, on apuntava al princip an (a aux)*/
        am=aux;
        printf("a(%d)=%s\n",i,an);
        /*Reservo 2*len(a(n-1))+2 (estrictament hauria de ser CONWAY*len+2 on CONWAY=1.303577269034) (el "+2" és per corregir l'error en els primers termes) unitats de memoria.*/
        /*en la posició que abans ocupava an (aux)*/
    }
    if(i!=n+1)
        printf("Només hi ha hagut memòria per imprimir fins el %d-essim terme de la successio de Conway.\n",i);
    free(am);
    free(an);
    return 0;
}
