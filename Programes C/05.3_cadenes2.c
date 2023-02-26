#include <stdio.h>
#include <string.h>

int main(){

    char cadena1 [21]={'B','o','n',' ','d','i','a',0};
    char cadena2 [21]="Bon dia";
    printf("%d\n",strlen(cadena1));
    printf("%d\n",strlen(cadena2));
    printf("%d\n",strlen(cadena1+2));
    printf("%s",cadena1+2);

    return 0;
}
