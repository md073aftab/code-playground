#include <stdio.h>
#include <stdlib.h>

struct queue{
    int size;
    int f;
    int r;
    int* arr;
};

int isempty(struct queue *q){
    if(q->r==q->f){  // if both index coincide than queue is empty
        return 1;
    }
    return 0;
}

int isfull(struct queue *q){
    if(q->r==q->size-1){
        return 1;
    }
    return 0;
}

void enqueue(struct queue *q,int val){
    if(isfull(q)){
        printf("this queue is full\n");
    }
    else{
        q->r++;
        q->arr[q->r]=val;
        printf("enqued element : %d\n",val);
    }
}

int dequeue(struct queue *q){
    int a=-1;
    if(isempty(q)){
        printf("this queue is empty\n");
    }
    else{
        q->f++;
        a=q->arr[q->f];
    }
    return a;
}
int main() {
    struct queue q;
    q.size=4;
    q.f=q.r=0;
    q.arr=(int*)malloc(q.size*sizeof(int));
    
    return 0;
}
