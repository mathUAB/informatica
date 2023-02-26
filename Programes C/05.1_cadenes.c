#include <stdio.h>

int main(){

    char cadena1 [21]={'B','o','n',' ','d','i','a',0};
    char cadena2 [21]="Bon dia";
    char missatge []="Bon dia vida";
    missatge[10]=0;
    printf("%s\n",cadena1 );
    printf("%s\n",cadena2 );
    printf("%s\n",missatge );

    return 0;
}
