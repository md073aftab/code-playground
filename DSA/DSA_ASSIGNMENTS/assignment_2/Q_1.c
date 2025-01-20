#include<stdio.h>
#include<stdlib.h>
int input(int *p[3]);
int dislay(int *q[3]);
int product(int *a[3],int *b[3],int *c[3]);
int main(){
    int *A[3],*B[3],*C[3];
    for (int i=0;i<3;i++){
        A[i]=(int*)malloc(3*sizeof(int));
        B[i]=(int*)malloc(3*sizeof(int));   
        C[i]=(int*)malloc(3*sizeof(int));
    }
    printf("enter matrix A \n");
    input(A);
    printf("\nenter matrix B \n");
    input(B);
    product(A,B,C);
    printf("\nproduct of matrix A and B \n");
    display(C);
}
int input(int *p[3]){
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            scanf("%d",(*(p+i)+j));
        }
    }
}
int product(int *a[3],int *b[3],int *c[3]){
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            *((c+i)+j)=0;
            for(int k=0;k<3;k++){
                *((c+i)+j)+=(((a+i)+k))*((*(b+j)+k));
            }
        }
    }
}
int display(int *q[3])
{   
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
        {
            printf("%d\t",((q+i)+j));
        }
        printf("\n");
    }
}