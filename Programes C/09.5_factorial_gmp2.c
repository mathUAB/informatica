#include <stdio.h>
#include <stdlib.h>
#include <gmp.h>
#include <time.h>

int main(int argc,char *argv[]){
    clock_t t0,t1;
    t0=clock();
    mpz_t factorial,n;
    mpz_init(factorial);
    mpz_init(n);
    if(argc==1){
        printf("Us: ./factorial_gmp n retorna el factorial del nombre n\n");
        return 1;
    }
    mpz_set_str(n,argv [1],10);
    mpz_out_str(stdout,10,n);
    printf("!=");
    for(mpz_set_ui(factorial,1);mpz_cmp_ui(n,1)>0;mpz_sub_ui(n,n,1)) //mpz_cmp_ui(n,1) retorna un valor positiu si n>1, 0 si n=1 i negatiu si n<1.
        mpz_mul(factorial,factorial,n);
    mpz_out_str(stdout,10,factorial);
    t1=clock();
    printf("\nS'ha trigat %lf segons\n",(double)(t1-t0)/CLOCKS_PER_SEC);
    mpz_clear(factorial);
    mpz_clear(n);
    return 0;
}
