#include <stdio.h>
#include <stdlib.h>
struct node{
    int data;
    struct node* next;
};

void linkedlisttraversal(struct node* ptr){
    while(ptr!=NULL){
        printf("%d\t",ptr->data);
        ptr=ptr->next;
    }
    printf("\n");
}

int isempty(struct node* top){
    if(top==NULL){
        return 1;
    }
    else{
        return 0;
    }
}

int isfull(struct node* top){
    struct node* 
}
int main() {
    
    return 0;
}
