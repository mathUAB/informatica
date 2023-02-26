#include <stdio.h>
#include <string.h>

char *strnchr(char *ca,char,int);//la funció és un puntuer perquè retorna un punter. Però quan es declara al main no es posa el &.
int main(){
    char cadena[]="Hola a tothom";

    printf("%s\n",strnchr(&cadena,'o',3));
    return 0;
}
char *strnchr(char *ca,char c,int n){
    for(int i=0;i<n;i++){
        ca=strchr(ca,c);
        ca=ca+1;
    }
    ca=ca-1;
    return ca;
}
