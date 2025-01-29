//Given a singly linked list of n nodes, detect if it contains a loop or not.

#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* next;
};

void loop_search(struct node* ptr) {

    struct node* head=ptr;

    while (ptr != NULL) {
        if (head==ptr->next)
        {
            printf("given linked has loop\n");
            return;
        }
        ptr = ptr->next;
    }
    printf("no loop found");
}

int main() {
    
    struct node* first =(struct node*)malloc(sizeof(struct node));
    struct node* second =(struct node*)malloc(sizeof(struct node));
    struct node* third =(struct node*)malloc(sizeof(struct node));
    struct node* fourth =(struct node*)malloc(sizeof(struct node));
    struct node* fifth =(struct node*)malloc(sizeof(struct node));
    struct node* sixth =(struct node*)malloc(sizeof(struct node));

    first->data=1;
    first->next=second;
    second->data=2;
    second->next=third;
    third->data=3;
    third->next=fourth;
    fourth->data=4;
    fourth->next=fifth;
    fifth->data=5;
    fifth->next=sixth;
    sixth->data=6;
    sixth->next=first;

    loop_search(first);

    return 0;
}
