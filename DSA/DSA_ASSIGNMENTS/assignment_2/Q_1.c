#include <stdio.h>
#include <stdlib.h>

void input(int *p[3]);
void display(int *q[3]);
void product(int *a[3], int *b[3], int *c[3]);

int main() {
    int *A[3], *B[3], *C[3];

    
    for (int i = 0; i < 3; i++) {
        A[i] = (int *)malloc(3 * sizeof(int));
        B[i] = (int *)malloc(3 * sizeof(int));
        C[i] = (int *)malloc(3 * sizeof(int));

        if (A[i] == NULL || B[i] == NULL || C[i] == NULL) {
            printf("Memory allocation failed\n");
            return 1;
        }
    }

    printf("Enter matrix A:\n");
    input(A);

    printf("\nEnter matrix B:\n");
    input(B);

    product(A, B, C);

    printf("\nProduct of matrix A and B:\n");
    display(C);


    for (int i = 0; i < 3; i++) {
        free(A[i]);
        free(B[i]);
        free(C[i]);
    }

    return 0;
}

void input(int *p[3]) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            scanf("%d", (*(p + i) + j));
        }
    }
}

void product(int *a[3], int *b[3], int *c[3]) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            *(*(c + i) + j) = 0;
            for (int k = 0; k < 3; k++) {
                *(*(c + i) + j) += (*(*(a + i) + k)) * (*(*(b + k) + j));
            }
        }
    }
}

void display(int *q[3]) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            printf("%d\t", *(*(q + i) + j));
        }
        printf("\n");
    }
}
