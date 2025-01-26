#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* next;
};

void Array_Insertion(int* ptr, int size){
    for (int i = 0; i < size; i++){
        printf("Insert element %d of Array: ", i + 1);
        scanf("%d", &ptr[i]);
    }
}

void array_display(int* ptr, int size) {
    for (int i = 0; i < size; i++) {
        printf("%d  ", ptr[i]);
    }
    printf("\n");
}

void linkedListTraversal(struct node* ptr) {
    while (ptr != NULL) {
        printf("Element: %d\n", ptr->data);
        ptr = ptr->next;
    }
}

struct node* InsertAtLast(struct node* last, int data) {
    struct node* tail = (struct node*)malloc(sizeof(struct node));
    tail->data = data;
    tail->next = NULL;
    last->next = tail;
    return tail;
}

int main() {
    int array_size;
    printf("Enter the size of array: ");
    scanf("%d", &array_size);
    int array[array_size];

    // Input array elements
    Array_Insertion(array, array_size);

    // Display array elements
    printf("Array elements: ");
    array_display(array, array_size);

    // Create the linked list and insert array elements
    struct node* head = (struct node*)malloc(sizeof(struct node));
    head->data = array[0];
    head->next = NULL;

    struct node* last = head;
    for (int i = 1; i < array_size; i++) {
        last = InsertAtLast(last, array[i]);
    }

    // Display linked list
    printf("Linked list elements:\n");
    linkedListTraversal(head);

    return 0;
}
