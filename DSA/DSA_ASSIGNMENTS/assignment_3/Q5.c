//Write a C program that converts a singly linked list into an array and returns it.
#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* next;
};

void array_display(int* ptr, int size) {
    for (int i = 0; i < size; i++) {
        printf("%d  ", ptr[i]);
    }
    printf("\n");
}

void create_array(struct node* ptr,int *array_ptr) {
    while (ptr != NULL) {
        *(array_ptr++)=ptr->data;
        ptr = ptr->next;
    }
}

void linkedListTraversal(struct node* ptr) {
    while (ptr != NULL) {
        printf("Element: %d\n", ptr->data);
        ptr = ptr->next;
    }
}

int main() {
    int linked_list_size;
    /*printf("Enter the Number of nodes in linked list : ");
    scanf("%d", &linked_list_size);*/
    int array[6];

    
    struct node* head = (struct node*)malloc(sizeof(struct node));
    struct node* first = (struct node*)malloc(sizeof(struct node));
    struct node* second = (struct node*)malloc(sizeof(struct node));
    struct node* third = (struct node*)malloc(sizeof(struct node));
    struct node* fourth = (struct node*)malloc(sizeof(struct node));
    struct node* fifth = (struct node*)malloc(sizeof(struct node));
    head->data = 0;
    head->next = first;
    first->data = 1;
    first->next = second;
    second->data = 2;
    second->next = third;
    third->data = 3;
    third->next = fourth;
    fourth->data = 4;
    fourth->next = fifth;
    fifth->data = 5;
    fifth->next = NULL;

    create_array(head,array);

    // Display linked list
    printf("Linked list elements:\n");
    linkedListTraversal(head);

    // Display array elements
    printf("Array elements: ");
    array_display(array, 6);


    return 0;
}
