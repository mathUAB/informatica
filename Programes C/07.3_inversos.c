#include<stdio.h>

int main(int argc,char *argv[]){
    double a,b,c,d;
    while(EOF!=fscanf(stdin,"%lf%lf%lf%lf",&a,&b,&c,&d))
        printf("%.6lf\t%.6lf\t%.6lf\t%.6lf\n",1./a,1./b,1./c,1./d);
    return 0;
}
