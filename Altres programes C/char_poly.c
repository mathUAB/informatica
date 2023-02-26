#include<stdio.h>
#include<math.h>
#define TOL 1e-8

void derivative_sym(int deg,double v[deg+1]);
double determinant(int n,double A[n][n]);
int rowEchelonForm(int m,int n,double[m][n]);
void rowReducedForm(int m,int n,double A[m][n]);
void charpoly(int n,double A[n][n]);
void identity_matrix(int n,double I[n][n]);
void matrices_prod(int m,int n,int p,double A[m][n],double B[n][p],double prod[m][p]);
void matrix_sum(int m,int n,double A[m][n],double B[m][n],double sum[m][n]);
void matrix_escalar_prod(int m,int n,double A[m][n],double c,double prod[m][n]);
double trace(int n,double A[n][n]);
void approxMatrix(int m,int n,double A[m][n]);
void readMatrix(int m,int n,double A[m][n]);
void printMatrix(int m,int n,double A[m][n]);
void printPolynomial(int deg,double v[deg+1]);
int min(int m,int n);
void copyvector(int n,double u[],double v[]);
void copymatrix(int m,int n,double A[m][n],double B[m][n]);

int main(){
    int n=4;
    double A[4]={4.,6.,7.,8.};

    printf("%g",1.989999);
    return 0;
}

void derivative_sym(int deg,double v[deg+1]){
    //Symbolic derivative of a polynomial of degree deg.
    for(int i=1;i<deg+1;i++)
        v[i-1]=i*v[i];
}
double determinant(int n,double A[n][n]){
    double det=1;
    int swap=rowEchelonForm(n,n,A);
    for(int i=0;i<n;i++)
        det*=A[i][i];
    return det*pow(-1,swap);
}
int rowEchelonForm(int m,int n,double A[m][n]){
    //Return the number of swaps between rows.
    int i,j,k;
    int c=0,d=-1,swap=0;
    double vect[n];
    for(i=0;i<min(m,n);i++){
        d++;
        if(d==n)
            break;
        if(A[i][d]!=0){
            for(j=i+1;j<m;j++){
                for(k=n-1;k>d-1;k--)
                    A[j][k]-=(A[j][d]/A[i][d])*A[i][k];
            }
        }else{
            //Permuto les files.
            if(c<m-i){
                copyvector(n,A[i],vect);
                for(j=i;j<m-1;j++)
                    copyvector(n,A[j+1],A[j]);
                copyvector(n,vect,A[m-1]);
                c++;
                swap+=m-i+1;
            }else
                d++;
            if(A[i][d]!=0)
                c=0;
            i--;
            d--;
        }
    }
    approxMatrix(m,n,A);
    return swap;
}
void rowReducedForm(int m,int n,double A[m][n]){
    rowEchelonForm(m,n,A);
    for(int i=m-1;i>-1;i--){
        for(int j=0;j<n;j++){
            if(A[i][j]!=0){
                for(int k=n-1;k>j-1;k--){
                    A[i][k]/=A[i][j];
                    if(i!=0){
                        for(int l=i-1;l>-1;l--)
                            A[l][k]-=A[l][j]*A[i][k];
                    }
                }
                break;
            }
        }
    }
}
void charpoly(int n,double A[n][n]){
    //Compute characteristic polynomial with Faddeev–LeVerrier algorithm.
    int i,j;
    double M0[n][n],M1[n][n],I[n][n];
    double v[n+1];
    v[n]=1;

    for(i=0;i<n;i++){
        for(j=0;j<n;j++)
            M0[i][j]=0;
    }
    for(i=1;i<n+1;i++){
        identity_matrix(n,I);
        matrix_escalar_prod(n,n,I,v[n-i+1],I);
        matrices_prod(n,n,n,A,M0,M1);
        matrix_sum(n,n,M1,I,M1);
        matrices_prod(n,n,n,A,M1,M0);
        v[n-i]=-trace(n,M0)/i;
        copymatrix(n,n,M1,M0);
    }
    printPolynomial(n+1,v);
}
void identity_matrix(int n,double I[n][n]){
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(i==j)
                I[i][j]=1;
            else
                I[i][j]=0;
        }
    }
}
void matrices_prod(int m,int n,int p,double A[m][n],double B[n][p],double prod[m][p]){
    for(int i=0;i<m;i++){
        for(int j=0;j<p;j++){
            for(int k=0;k<n;k++){
                if(k==0)
                    prod[i][j]=0;
                prod[i][j]+=A[i][k]*B[k][j];
            }
        }
    }
}
void matrix_sum(int m,int n,double A[m][n],double B[m][n],double sum[m][n]){
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++)
            sum[i][j]=A[i][j]+B[i][j];
    }
}
void matrix_escalar_prod(int m,int n,double A[m][n],double c,double prod[m][n]){
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++)
            prod[i][j]=c*A[i][j];
    }
}
double trace(int n,double A[n][n]){
    double trace=0;
    for(int i=0;i<n;i++)
        trace+=A[i][i];
    return trace;
}
void approxMatrix(int m,int n,double A[m][n]){
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(fabs(A[i][j])<TOL)
                A[i][j]=0;
        }
    }
}
void readMatrix(int m,int n,double A[m][n]){
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            printf("a(%d,%d)= ",i+1,j+1);
            scanf("%lf",&A[i][j]);
        }
    }
    return;
}
void printMatrix(int m,int n,double A[m][n]){
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++)
            printf("%.4g\t",A[i][j]);
        printf("\n");
    }
}
void printPolynomial(int deg,double v[deg+1]){
    for(int i=deg;i>-1;i--){
        switch(i){
            case 0:
                if(v[i]>0)
                    printf("+%g",v[i]);
                else if(v[i]<0)
                    printf("-%g",v[i]);
                break;
            case 1:
                if(v[i]>0){
                    printf("+%gx",v[i]);
                }else if(v[i]<0)
                    printf("-%gx",v[i]);
                break;
            default:
                if(v[i]>0){
                    if(v[i]==1)
                        printf("+x^%d",i);
                    else
                        printf("+%gx^%d",v[i],i);
                }else if(v[i]<0)
                    printf("-%gx^%d",v[i],i);
        }
    }
}
int min(int m,int n){
    if(n<m)
        return n;
    else
        return m;
}
void copyvector(int n,double u[],double v[]){
    //Copy vector u to vector v.
    for(int i=0;i<n;i++)
        v[i]=u[i];
}
void copymatrix(int m,int n,double A[m][n],double B[m][n]){
    //Copy el matrix A to matrix B.
    for(int i=0;i<m;i++)
        copyvector(n,A[i],B[i]);
}
