#include <stdio.h>
#include <stdlib.h>
typedef struct Dada{
    int niu;
    float notes[4];
    struct Dada *seg;
}Alu;

void inserir(Alu **inicill,Alu *actual);
void imprimeixllista(Alu *inicill);
void treurelement(Alu **inicill,int nn);

int main(){
    FILE *dades;
    int n,i,lrg=0;
    Alu *inicill=NULL,*actual=NULL;
    dades=fopen("Llista.txt","r");
    if(dades==NULL){
        printf("\nNo s’ha accedit al fitxer de dades\n");
        return 1;
    }
    while(!(fscanf(dades,"%i;",&n)==EOF)){
        if((actual=(Alu *) malloc(sizeof(Alu)))==NULL){
            printf("Problema assignant espai de memoria\n");
            return 2;
        }
        lrg++;
        actual->niu=n;
        for(i=0;i<4;i++){
            fscanf(dades,"%f",&actual->notes[i]);
            fgetc(dades);
        }
        inserir(&inicill,actual);
    }
    fclose(dades);
    imprimeixllista(inicill);
    printf("\n");
    treurelement(&inicill,3592508);
    imprimeixllista(inicill);
    printf("\nS'ha llegit informacio de %d linies.\n\n",lrg);
    return 0;
}

void inserir(Alu **inicill,Alu *actual){
    Alu *anterior;
    if(*inicill==NULL){
        actual->seg=NULL;
        *inicill=actual;
    }else{
        if(actual->niu<(*inicill)->niu){
            actual->seg=*inicill;
            *inicill=actual;
        }else{
            anterior=*inicill;
            while(anterior->seg!=NULL && (anterior->seg)->niu<actual->niu)
                anterior=anterior->seg;
            actual->seg=anterior->seg;
            anterior->seg=actual;
        }
    }
}

void imprimeixllista(Alu *inicill){
    Alu *actual=inicill;
    while(!(actual==NULL)){
        printf("%d | ",actual->niu);
        for (int i=0;i<4;i++)
            printf("%5.1f",actual->notes[i]);
        printf("\n");
        actual=actual->seg;
    }
}

void treurelement(Alu **inicill,int nn){
    Alu *actual=*inicill,*elim;
    if((*inicill)->niu==nn){
        *inicill=(*inicill)->seg;
        free(actual);
    }else{
        while(actual->seg!=NULL && actual->seg->niu!=nn)
            actual=actual->seg;
        if(actual->seg!=NULL){
            elim=actual->seg;
            actual->seg=elim->seg;
            free(elim);
        }
        else
            printf("No s'ha localitzat.\n\n");
    }
}
