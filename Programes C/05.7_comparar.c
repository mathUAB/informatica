# include <stdio.h>
# include <string.h>
int main (){

    char cadena1 []=" Hola ",cadena2 []=" Hole ",cadena3 []=" Hola ";
    printf ("Diferència entre %s i %s: %d\n",cadena1,cadena2,strncmp(cadena1,cadena2,3));
    printf ("Diferència entre %s i %s: %d\n",cadena2,cadena1,strncmp(cadena2,cadena1,3));
    printf ("Diferència entre %s i %s: %d\n",cadena1,cadena3,strncmp(cadena1,cadena3,3));
    return 0;
}
