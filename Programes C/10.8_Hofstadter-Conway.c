//Calcula els termes de la successió de Hofstadter-Conway:
//a(1)=a(2)=1;a(n)=a(a(n-1))+a(n-a(n-1)) n>2
#include <stdio.h>

int hc(int n);

int main(){
    int n;
    printf("Escriu un nombre natural diferent de 0: ");
    scanf("%d",&n);
    printf("El %d-enessim terme de la successio de Hofstadter-Conway es %d",n,hc(n));
    return 0;
}

int hc(int n){
    int a[n+1];
    a[1]=1;
    a[2]=1;
    for(int i=3;i<n+1;i++)
        a[i]=a[a[i-1]]+a[i-a[i-1]];
    return a[n];
}
