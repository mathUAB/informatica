#include<stdio.h>
#include<math.h>
#define TOL 1e-8


double determinant(int n,double A[n][n]);
int rowEchelonForm(int m,int n,double[m][n]);
void rowReducedForm(int m,int n,double A[m][n]);
void approxMatrix(int m,int n,double A[m][n]);
void readMatrix(int m,int n,double A[m][n]);
void printMatrix(int m,int n,double A[m][n]);
int min(int m,int n);
void copyvector(double u[],double v[],int dim);

int main(){
    int n;
    printf("Enter the order of the matrix: \n");
    scanf("%d",&n);
    double A[n][n];
    printf("\nEnter the elements of matrix:\n");
    readMatrix(n,n,A);
    rowReducedForm(n,n,A);
    printMatrix(n,n,A);
    printf("\n%lf",determinant(n,A));
    return 0;
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
                copyvector(A[i],vect,n);
                for(j=i;j<m-1;j++)
                    copyvector(A[j+1],A[j],n);
                copyvector(vect,A[m-1],n);
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
int min(int m,int n){
    if(n<m)
        return n;
    else
        return m;
}
void copyvector(double u[],double v[],int dim){
    //Copiar el vector u al vector v.
    for(int i=0;i<dim;i++)
        v[i]=u[i];
}
