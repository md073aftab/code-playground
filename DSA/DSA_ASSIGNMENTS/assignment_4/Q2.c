// Q2: Given an unsorted linked list of n nodes, remove duplicates from the list.

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
        printf("%d  ", ptr->data);
        ptr = ptr->next;
    }
}
void duplicate_node_deletion(struct node* ptr){

    int data;
    struct node* ptr2;
    struct node* ptr3;
    while(ptr!=NULL){
        data= ptr->data;
        ptr2=ptr->next;
        ptr3 =ptr;
        if (ptr2->data= ptr->data)
        {
            ptr3->next=ptr2->next;
        }
        else
        {
            ptr2=ptr2->next;
            ptr3=ptr3->next;
        }
    ptr= ptr->next;
    }


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
    fourth->data=1;
    fourth->next=fifth;
    fifth->data=3;
    fifth->next=sixth;
    sixth->data=6;
    sixth->next=NULL;

    linkedListTraversal(first);
    printf("\n");
    duplicate_node_deletion(first);
    linkedListTraversal(first);
    
    return 0;
}
