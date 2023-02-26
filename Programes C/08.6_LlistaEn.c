#include <stdio.h>
#include <stdlib.h>
typedef struct Dada{
    int niu;
    float notes[4];
    struct Dada *seg;
}Alu;

void inserir(Alu **inicill,Alu *actual);
void imprimeixllista(int lgr,Alu **index);
void treurelement(int *lrg,Alu **index,int nn);

int main(){
    FILE *dades;
    int n,i,lrg=0;
    Alu *inicill=NULL,*actual=NULL,**index;
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
    if((index=(Alu **) malloc(lrg*sizeof(Alu *)))==NULL){
        printf("Problema assignant espai de memoria.\n");
        return 2;
    }
    actual=inicill;
    int j=0;
    while(!(actual==NULL)){
        index[j]=actual;
        j++;
        actual=actual->seg;
    }
    imprimeixllista(lrg,index);
    printf("\n");
    treurelement(&lrg,index,3186478);
    imprimeixllista(lrg,index);
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
void imprimeixllista(int lrg,Alu **index){
    for(int i=0;i<lrg;i++) {
        printf("%d | ",index[i]->niu);
        for(int j=0;j<4;j++)
            printf("%5.1f",index[i]->notes[j]);
        printf("\n");
    }
}
void treurelement(int *lrg,Alu **index,int nn){
    int c=0;
    for(int i=0;i<*lrg;i++){
        if(index[i]->niu==nn){
            c=1;
            if(index[i+1]!=NULL){
                for(int j=i;j<*lrg-1;j++)
                    index[j]=index[j+1];
            }
            (*lrg)--;
            break;
        }
    }
    if(c==0)
        printf("No s'ha localitzat.\n\n");
}




