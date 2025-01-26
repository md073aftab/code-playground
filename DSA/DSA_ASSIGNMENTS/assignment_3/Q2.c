/*Write a program in C to insert a new node at the beginning of a Singly
Linked List.*/


#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node* next;
};
void linkedListTraversal(struct node *ptr)
{
    while (ptr != NULL)
    {
        printf("Element: %d\n", ptr->data);
        ptr = ptr->next;
    }
}
struct node * insert_at_first(struct node* head, int data) 
{
    struct node *ptr =(struct node *)malloc(sizeof(struct node));
    ptr->data=data;
    ptr->next=head;
}

int main(){

    struct node *n1=(struct node *)malloc(sizeof(struct node));
    struct node *n2=(struct node *)malloc(sizeof(struct node));
    struct node *n0=(struct node *)malloc(sizeof(struct node));

    n1->data=10;
    n1->next=n2;
    n2->data=20;
    n2->next=NULL;

    linkedListTraversal(n1);
    n0=insert_at_first(n1,25);
    printf("traversing linkedlist after insertion :\n");
    linkedListTraversal(n0);
    
    free(n0);
    free(n1);
    free(n2);

    return 0;
}

