# include <stdio.h>
# include <string.h>

int main(){
    char cadena1 [10],cadena2 [10];
    strcpy(cadena1,"Hola");
    printf("%s\n",cadena1);
    strncpy(cadena2,cadena1,3);
    cadena2[3]='\0';
    printf("%s\n",cadena2);
    return 0;
}
