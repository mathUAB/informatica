#include <stdio.h>
#include <string.h>
#define NALUM 5


typedef struct{
    char nom[20],cognom[20];
}alu;
typedef struct{
    alu alumne;
    double nota;
}notes;
void entranotes(notes *alu){
    printf("\tEntra nom, cognom i nota alumne: ");
    scanf("%s%s%lf",(*alu).alumne.nom,(*alu).alumne.cognom,&((*alu).nota));
}
void imprimeixnotes(notes Alumne){
    printf("\t\tNom: %s %s\n",Alumne.alumne.nom,Alumne.alumne.cognom);
    printf("\t\tNota: %3.1lf\n",Alumne.nota);
}
int main (){
    notes llista[NALUM];
    printf("\tNOTES ALUMNES\n");
    for(int i=0;i<NALUM;i++)
        entranotes(&llista[i]);
    printf("\n\tEL RESULTAT HA ESTAT:\n");
    for(int i=0;i< NALUM ;i++){
        printf("\tAlumne %i:\n",i+1);
        imprimeixnotes(llista[i]);
    }
    return 0;
}
