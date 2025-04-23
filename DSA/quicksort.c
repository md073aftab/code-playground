#include<stdio.h>

void swap(int *a,int *b){  //function to swap two element
    int temp =*a;
    *a=*b;
    *b=temp;
}
// partition funtion
int partition(int arr[],int low,int high){
    int pivot =arr[high]; // choosing last element as pivot 
    int i=(low-1); //index of smaller element 
    for(int j=low;j<high;j++){
        if(arr[j]<pivot){
            i++;
            swap(&arr[i],&arr[j]);
        }
    }
    swap(&arr[i+1],&arr[high]);
    //swap pivot to the correct position
    return (i+1);
}
//quicksort function
void quicksort(int arr[],int low,int high){
    if(low<high){
        int pi=partition(arr,low,high);
        // recursively sort elements before and after partition
        quicksort(arr,low,pi-1);
        quicksort(arr,pi+1,high); 
    }
}

void printarray(int arr[],int size){
    for(int i=0;i<size;i++)
        printf(" %d |",arr[i]);
    printf("\n");    
}

int main(){
    int arr[]={10,3,5,9,2,1,4,3};
    int n=sizeof(arr)/sizeof(arr[0]);
    printarray(arr,n);
    quicksort(arr,0,n-1);
    printarray(arr,n);
    return 0;
}