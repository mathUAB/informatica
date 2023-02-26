#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define NALUM 5

typedef struct{
    char *nom,*cognom;
}alu;
typedef struct{
    alu alumne;
    double nota;
}notes;
int main (){
    char nom[30],cognom[30];
    notes llista[NALUM];
    printf("\tNOTES ALUMNES\n");
    for(int i=0;i<NALUM;i++){
        printf("Escriu el nom de l'alumne %d: ",i+1);
        scanf("%30s",nom);
        llista[i].alumne.nom=(char*)malloc(strlen(nom)+1);
        printf("Escriu el cognom de l'alumne %d: ",i+1);
        scanf("%30s",cognom);
        llista[i].alumne.cognom=(char*)malloc(strlen(cognom)+1);
        if(llista[i].alumne.cognom==NULL || llista[i].alumne.nom==NULL){
            printf("No hi ha suficient memòria.\n");
            return 1;
        }
        strcpy(llista[i].alumne.nom,nom);
        strcpy(llista[i].alumne.cognom,cognom);
        printf("\tEscriu la nota %i: ",i+1);
        fflush(stdin);
        scanf("%lf",&(llista[i].nota));
    }
    printf("\n\tEL RESULTAT HA ESTAT:\n");
    for(int i=0;i<NALUM;i++){
        printf("\tAlumne %i:\n",i+1);
        printf("\t\tNom: %s %s\n",llista[i].alumne.nom,llista[i].alumne.cognom);
        printf("\t\tNota: %3.1lf\n",llista[i].nota );
        free(llista[i].alumne.nom);
        free(llista[i].alumne.cognom);
    }
    return 0;
}
