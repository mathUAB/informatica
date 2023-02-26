/**Programa per simular un joc d'atzar. El jugador aposta "APOSTA" unitats de "capital" inicials.
Si guanya s'enporta la unitat que ha apostat + un premi de la mateixa quantitat que s'ha apostat.
Si perd, ha perdut només el què ha apostat.**/
#include <stdio.h>
#include <stdlib.h>

#define APOSTA 1

int apostar(int capital);
void imprimeixvector(int n,int v[]);

int main(){
    int capitalinicial=100,capital;
    int partides=1000;
    int guanyats=0,perduts=0;

    for(int i=0;i<partides;i++){
        capital=capitalinicial;
        do{
            capital=apostar(capital);
        }while(capital<1000 && capital>0);
        if(capital==0)
            perduts++;//Ha perdut.
        else
            guanyats++;//Ha guanyat.
    }
    printf("Partides guanyades: %d\nPartides perdudes: %d\n",guanyats,perduts);

    return 0;
}

int apostar(int capital){
    capital-=APOSTA;
    if((double)rand()/RAND_MAX>=0.5) //El jugador guanya.
        capital+=2*APOSTA;
    return capital;
}

void imprimeixvector(int n,int v[]){
    for(int i=0;i<n;i++)
        printf("%d",v[i]);
    printf("\n");
}
