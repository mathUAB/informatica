#include <stdio.h>
#include <stdlib.h>
typedef struct Dada{
    int niu;
    float notes[4];
    struct Dada *seg;
}Alu;

void inserir(Alu **inicill,Alu *actual);
void imprimeixnotes(int n,Alu **index);

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
    int inf=0,sup=lrg-1,pos,nniu;
    printf("Quin niu te la persona? ");
    scanf("%d",&nniu);
    for(i=0;i<lrg;i++){
        if(index[inf]->niu==nniu){
            imprimeixnotes(inf,index);
            break;
        }else if(index[sup]->niu==nniu){
            imprimeixnotes(sup,index);
            break;
        }else{
            pos=(inf+sup)/2;
            if(index[pos]->niu>nniu)
                sup=pos;
            else if(index[pos]->niu<nniu)
                inf=pos;
            else{
                imprimeixnotes(pos,index);
                break;
            }
        }
        if(i==lrg-1)
            printf("No s'ha trobat cap alumne amb aquest NIU.");
    }
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
void imprimeixnotes(int n,Alu **index){
    for(int j=0;j<4;j++)
        printf("%5.1f\t",index[n]->notes[j]);
    printf("\n");
}
