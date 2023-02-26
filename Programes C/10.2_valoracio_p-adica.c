#include <stdio.h>
#include <math.h>

int main(){
    int n,p,e=0;

    printf("Escriu un nombre natural i un nombre primer: ");
    scanf("%d%d",&n,&p);
    for(int i=p-1;i-1;i--){
        if(!(p%i)){
            printf("\n%d no es primer.",p);
            return 1;
        }
    }
    while(!(n%p)){
        e++;
        n/=p;
    }
    printf("La valoracio %d-adica de %d es %d",p,(int) pow(p,e)*n,e);
    return 0;
}
