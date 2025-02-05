/*Q4: Write a C/C++ program to implement doubly linked list with the following function
(i) insertAtFirst(&head, new_data): This function should insert the new data/element at the beginning of the linked list.
(ii) insertAtEnd(&head, new_data): This function should insert the new data/element at the end of the linked list
(iii) insertAtMiddle(&head, new_data): This function should insert the new data/element at the middle of the linked list
(iv) insertAfterNode(&head, given_node, new_data): This function should insert the new data/element after the given node in the linked list.
Example: Suppose, you want to insert 60 after node 40 in the given linked list 10 → 20 → 30 → 40 → 50,
the updated linked list will be 10 → 20 → 30 → 40 → 60 → 50\
(v) display(&head): This function should display the content of the linked list*/

#include <stdio.h>
#include <stdlib.h>

struct node{
    struct node* prev;
    int data;
    struct node* next;
};

void display(struct node *ptr)
{
    while (ptr != NULL)
    {
        printf("%d  ", ptr->data);
        ptr = ptr->next;
    }
}

struct node* insert_at_first(struct node* head,int new_data){
    struct node* new=(struct node*)malloc(sizeof(struct node));
    new->data=new_data;
    new->next=head;
    new->prev=NULL;
    head->prev=new;

    return new;
}

void insert_at_middle(struct node* head,int new_data){
    struct node* middle=(struct node*)malloc(sizeof(struct node)); 
    int counter=1;
    struct node* ptr=head;
    
    while (ptr!=NULL)
    {
        ptr=ptr->next;
        counter++;
    }
    
    ptr=head;
    for (int i = 0; i <(counter/2)-1; i++)
    {
        ptr=ptr->next;
    }
    middle->next=ptr->next;
    ptr->next=middle;
    middle->prev=ptr;
    middle->data=new_data;   
}

void insert_at_last(struct node* head, int new_data){
    struct node* last=(struct node*)malloc(sizeof(struct node));
    struct node* ptr=head;

    while(ptr->next!=NULL){
        ptr=ptr->next;
    }

    ptr->next=last;
    last->prev=ptr;
    last->next=NULL;
    last->data=new_data;
}

void insert_after_node(struct node* ptr, int node ,int new_data){

    struct node* new_node=(struct node*)malloc(sizeof(struct node));
    struct node* next_node=(struct node*)malloc(sizeof(struct node));

    while(ptr->data != node){
        ptr=ptr->next;
    }
    next_node=ptr->next;
    ptr->next=new_node;
    new_node->next=next_node;
    new_node->prev=ptr;
    new_node->prev=new_node;
    new_node->data=new_data;

}


int main(){

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

    int choice;
    int data;
    int node;

    while(choice!=6){

        printf("\n");
        printf("Enter the choice from below :\n ");
        printf("1.Insert a node at first position of linkedlist\n ") ; 
        printf("2.Insert a node at last position of linkedlist\n ") ; 
        printf("3.Insert a node at middle position of linkedlist\n ") ; 
        printf("4.Insert a node after the given node in linkedlist\n ") ; 
        printf("5.display all elements of linkedlist\n ") ; 
        printf("6.EXIT\n ") ; 
        scanf("%d",&choice);
        
        switch (choice)
        {
        case 1 :
            printf("enter the data you want to insert in linkedlist :\n");
            scanf("%d",&data);
            printf("Your updated linkedlist is :\n");
            display(insert_at_first(first,data));
            break;
        case 2 :
            printf("enter the data you want to insert in linkedlist :\n");
            scanf("%d",&data);
            insert_at_last(first,data);
            printf("Your updated linkedlist is :\n");
            display(first);
            break;
        case 3 :
            printf("enter the data you want to insert in linkedlist :\n");
            scanf("%d",&data);
            insert_at_middle(first,data);
            printf("Your updated linkedlist is :\n");
            display(first);
            break;
        case 4 :
            printf("enter the data you want to insert in linkedlist :\n");
            scanf("%d",&data);
            printf("enter the node after which  you want to insert the element in linkedlist");
            scanf("%d",&node);

            insert_after_node(first,node,data);
            printf("Your updated linkedlist is :\n");
            display(first);
            break;
        case 5 :
            display(first);
            break;
            
        
        case 6:
            break;
        }
    }    
    
    return 0;
}
