#include <stdio.h>
#include<stdlib.h>

void matrix_input(int **a) {
    // Allocate memory for a 3x3 matrix (flattened as a 1D array)
    *a = (int *)malloc(3 * 3 * sizeof(int));
    if (*a == NULL){
        printf("Memory allocation failed.\n");
        return;
    }

    // Input the elements of the matrix
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            printf("Enter the (%d,%d) element of the array: ", i + 1, j + 1);
            scanf("%d", (*a) + i * 3 + j); // Use pointer arithmetic to access elements
        }
    }
}

void matrix_product(int*p,int*q,int*r){

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            for (int h = 0; h < 3; h++)
            {
                r[i][j]= 
                
            }
            
        }
        
    }
    

}
void resultant_matrix(int **r){

    for (int  i = 0; i < 3; i++)
    {
        for (int j = 0; j <3; j++)
        {
            printf("%d\t",r[i][j]);
        }
        printf("\n");
        
    }

}
int main(){


    int *matrix_1=(int*)malloc(3*3*sizeof(int));
    int *matrix_2=(int*)malloc(3*3*sizeof(int));
    int *matrix_3=(int*)malloc(3*3*sizeof(int));

    matrix_input(&matrix_1);
    matrix_input(&matrix_2);
    resultant_matrix(&matrix_1);
    
    

    return 0;
}
