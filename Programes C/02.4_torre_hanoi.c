# include <stdio.h>

int torre_hanoi(int n,int passos,char origen,char desti,char aux);

int main(){
    unsigned int n,passos=0;

    printf("Quants discs te la teva Torre de Hanoi?\n");
    scanf("%u",&n);

    passos=torre_hanoi(n,passos,'A','C','B');
    printf("\n\nHe resolt el problema en %d passos.\n",passos);
    return 0;
}

int torre_hanoi(int n,int passos,char origen,char desti,char aux){
    if(n==1){
        passos++;
        printf("\nPas %d: mou el disc 1 de %c a %c",passos,origen,desti);
        return passos;
    }
    passos=torre_hanoi(n-1,passos,origen,aux,desti);
    passos++;
    printf("\nPas %d: mou el disc %d de %c a %c",passos,n,origen,desti);
    passos=torre_hanoi(n-1,passos,aux,desti,origen);

    return passos;
}
