#include <stdio.h>
#include <stdlib.h>
int main(){
    char str1[]="124z3yu87";
    char str2[]="-3.14159";
    char str3[]="1e24";
    printf("str1 com a enter: %d\n",atoi(str1));
    printf("str2 com a enter: %d\n",atoi(str2));
    printf("str3 com a enter: %d\n",atoi(str3));
    printf("str1 com a double: % lf \n",atof(str1));
    printf("str2 com a double: % lf \n",atof(str2));
    printf("str3 com a double: % lf \n",atof(str3));
    return 0;
}
