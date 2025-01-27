//Q1: Given a linked list of n nodes and an integer k, write a function to rotate the linked list counter clockwise by k nodes.   

#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* next;
};

void linkedListTraversal(struct node* ptr) {
    while (ptr != NULL) {
        printf("%d  ", ptr->data);
        ptr = ptr->next;
    }
}

struct node*  linkedListShift(struct node* head, struct node* last, int number, int nodes){
    int counter=0;
    struct node* ptr=head;
    last->next=head;
    while (counter<(nodes-number-1)) {
        ptr = ptr->next;
        counter++;
    }
    head=ptr->next;
    ptr->next=NULL;

    return head;
}

int main(){

    int number;

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
    sixth->next=NULL;

    printf("enter the number by which you want linkedelist to be shifted :");
    scanf("%d",&number);

    linkedListTraversal(first);
    printf("\n");
    first=linkedListShift(first,sixth,number,6);
    linkedListTraversal(first);
    
    return 0;
}

