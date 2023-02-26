#include <stdio.h>

int main(int argc,char *argv[]){
    FILE *meufitxer;

    meufitxer=fopen(argv[1],"w");
    if(meufitxer==NULL){
        fprintf(stderr,"ERROR: El fitxer '%s.txt' no es pot obrir...\n\n",argv[1]);
        return 1;
    }
    fprintf(meufitxer,"%s\n",argv[2]);
    fclose(meufitxer);
    printf("Fet!\n");
    return 0;
}
