# include <stdio.h>
# include <string.h>

int main (){

    char cadena1 [25]="Hola",cadena2 []=" a tothom";
    printf("%s!\n",cadena1);
    strncat(cadena1,cadena2,12);
    printf("%s!\n",cadena1);
    return 0;
}
