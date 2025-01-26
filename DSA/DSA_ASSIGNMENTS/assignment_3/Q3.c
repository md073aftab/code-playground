//Write a program in C to traverse in a singly linked list.

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

int main(){

    struct node *n1=(struct node *)malloc(sizeof(struct node));
    struct node *n2=(struct node *)malloc(sizeof(struct node));

    n1->data=10;
    n1->next=n2;
    n2->data=20;
    n2->next=NULL;

    linkedListTraversal(n1);
    
    free(n1);
    free(n2);

    return 0;
}
