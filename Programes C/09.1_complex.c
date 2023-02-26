#include <stdio.h>
#include <complex.h>

int main(){
    double real,imag;
    printf("Escriu la part real del nombre complex: ");
    scanf("%lf",&real);
    printf("Escriu la part imaginaria del nombre complex: ");
    scanf("%lf",&imag);
    double complex z=real+imag*I;

    printf("El quadrat del nombre complex intoduit val %lf%+lfi.\n",creal(z*z),cimag(z*z));
    printf("L'invers del nombre complex intoduit val  %lf%+lfi.\n",creal(1/z),cimag(1/z));
    printf("El conjugat del nombre complex intoduit val  %lf%+lfi.\n",creal(z),-cimag(z));
    printf("El modul del nombre complex intoduit val  %lf.\n",cabs(z));
    printf("L'argument del nombre complex intoduit val  %lf.\n",carg(z));
    return 0;
}
