#include <stdio.h>
#include <stdlib.h> // Use stdlib.h for malloc

struct array {
    int *p;
    int *q;
};

int main() {
    int array_1[10];
    int array_2[10];

    printf("enter the first element of array");// Input for the first array
    for (int i = 0; i < 10; i++) {
        scanf("%d", &array_1[i]);
    }

    // Allocate memory for the structure
    struct array *array1 = (struct array *)malloc(sizeof(struct array));
    if (array1 == NULL) {
        printf("Memory allocation failed for structure.\n");
        return 1;
    }

    // Set structure members to point to the arrays
    array1->p = array_1;
    array1->q = array_2;

    // Copy and process the arrays
    for (int i = 0; i < 10; i++) {
        if (i % 2 == 1 && i < 9) {
            // Replace odd-positioned elements (1-based) with the product of adjacent elements
            *(array1->q + i) = (*(array1->p + i - 1)) * (*(array1->p + i + 1));
        } else {
            *(array1->q + i) = *(array1->p + i);
        }
    }

    // Output the first array
    printf("First array:\n");
    for (int i = 0; i < 10; i++) {
        printf("%d ", *(array1->p + i));
    }
    printf("\n");

    // Output the second array
    printf("Second array:\n");
    for (int i = 0; i < 10; i++) {
        printf("%d ", *(array1->q + i));
    }
    printf("\n");

    // Free allocated memory for the structure
    free(array1);

    return 0;
}
