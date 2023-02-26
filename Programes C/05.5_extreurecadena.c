# include <stdio.h>
# include <string.h>

void extreurecadena (char *,int,int,char *);
int main(){
    char cadena[]="Hola a tothom!",cadena1[strlen(cadena)+1];
    int n,m;

    printf("Escriu dos nombres, n i m, separats per una coma, menors que %d i que compleixin n<m: ",strlen(cadena));
    scanf("%d,%d",&n,&m);
    strcpy(cadena1,cadena+(n-1));
    char result[m-n+1];
    if(n>m){
        printf("Error! n ha de ser mes petit que m!");
    }
    else{
        extreurecadena(&cadena1,n,m,&result);
        printf("Els %d caracters seleccionats de \"%s\" son: \"%s\"",m-n+1,cadena,result);
    }

    return 0;
}
void extreurecadena (char *c,int n,int m,char *r){
    for(int i=n;i<=m;i++){
        *r=*c;
        *c++;
        *r++;
    }
    *r=0;
}

