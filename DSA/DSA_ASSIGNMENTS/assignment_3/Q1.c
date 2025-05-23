// Write a program in C to create and display a Singly link list.

#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node* next;
};

int main(){

    struct node *n1=(struct node *)malloc(sizeof(struct node));
    struct node *n2=(struct node *)malloc(sizeof(struct node));

    n1->data=10;
    n1->next=n2;
    n2->data=20;
    n2->next=NULL;

    printf("%d\n",n1->data);
    printf("%d\n",n2->data);
    
    free(n1);
    free(n2);

    return 0;
}
