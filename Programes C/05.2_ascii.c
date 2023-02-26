#include <stdio.h>

int main(){
    char cadena[30]="L'endemà és un món nou.";
    char c;
    for(c=0;c<=30;c++){
        printf("ASCII %i -> %c\n",cadena[c],cadena[c]);
    }

    return 0;
}
