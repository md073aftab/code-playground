#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* next;
};

void linkedListTraversal(struct node *ptr)
{
    while (ptr != NULL)
    {
        printf("%d  ", ptr->data);
        ptr = ptr->next;
    }
}

void duplicate_node_deletion(struct node* ptr) {
    struct node* ptr2;
    struct node* ptr3;
    while (ptr != NULL && ptr->next != NULL) {
        ptr2 = ptr->next;
        ptr3 = ptr;
        while (ptr2 != NULL) {
            if (ptr->data == ptr2->data) {
                ptr3->next = ptr2->next;  // Remove the duplicate node
                free(ptr2);  // Free the duplicate node memory
                ptr2 = ptr3->next;  // Continue checking next nodes after the deletion
            } else {
                ptr3 = ptr2;
                ptr2 = ptr2->next;
            }
        }
        ptr = ptr->next;  // Move to the next node in the list
    }
}

int main() {
    struct node* first = (struct node*)malloc(sizeof(struct node));
    struct node* second = (struct node*)malloc(sizeof(struct node));
    struct node* third = (struct node*)malloc(sizeof(struct node));
    struct node* fourth = (struct node*)malloc(sizeof(struct node));
    struct node* fifth = (struct node*)malloc(sizeof(struct node));
    struct node* sixth = (struct node*)malloc(sizeof(struct node));

    first->data = 1;
    first->next = second;
    second->data = 2;
    second->next = third;
    third->data = 3;
    third->next = fourth;
    fourth->data = 1;
    fourth->next = fifth;
    fifth->data = 3;
    fifth->next = sixth;
    sixth->data = 6;
    sixth->next = NULL;

    printf("Original List: \n");
    linkedListTraversal(first);
    printf("\n");

    duplicate_node_deletion(first);

    printf("List after duplicate node deletion: \n");
    linkedListTraversal(first);
    printf("\n");

    return 0;
}
