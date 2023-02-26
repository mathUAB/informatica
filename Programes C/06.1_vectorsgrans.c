#include <stdio.h>

int main(){
    long long unsigned int mida=128;
    long long int *v;

    for(int i=0;i<40;i++){
        v=(long long int *) malloc(mida*sizeof(long long int));
        if(v==NULL){
            printf("No hi ha prou espai a la memoria de l'ordinador.");
            return 1;
        }
        v[0]=1;
        printf("He creat i usat un vector de %llu components.\n",mida);
        printf("Ocupa %llu Kb.\n",mida*sizeof(long long int)/1024);
        mida*=2;
    }
    free(v);
    return 0;
}
