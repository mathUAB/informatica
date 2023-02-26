//Calcuar el factorial (de 7, per exemple) des de consola: ./factorial 7

#include <stdio.h>
#include <stdlib.h>

int main(int argc,char *argv[]){
	long long int fact=1;

   	if (argc != 2) {
        printf("S'ha d'especificar un nombre per el qual calcular el factorial.\n");
        return 1;
   	}
   	if(atoi(argv[1])!=0 || atoi(argv[1])!=1){
 		for(int i=2;i<=atoi(argv[1]);i++){
            fact*=i;
        }
    }
    printf("%s!=%ld\n",argv[1],fact);
	return 0;
}

