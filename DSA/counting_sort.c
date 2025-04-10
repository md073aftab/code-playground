#include <stdio.h>

// finding maximum element from array
int FindMax(int arr[],int n){
    int max=arr[0];
    for(int i=1;i<n;i++){  
        if(arr[i]>max)
            max=arr[i];
    }
    return max;
}

// countingsort function
void CountingSort(int arr[],int n){
    int max=FindMax(arr,n);
    int count[max+1]; //create and initialize count array
    for(int i=0;i<n;i++){
        count[i]=0;
    }
    // store count of each element 
    for(int i=0;i<n;i++){
        count[arr[i]]++;
    }
    // modify count array to store cumulative sum
    for(int i=1;i<=max;i++){
        count[i]+=count[i-1];
    }
    // create output array
    int output[n];
    // place element in sorted array
    for(int i=n-1;i>=0;i--){
        output[count[arr[i]]-1]=arr[i];
        count[arr[i]]--;
    }
    // copy sorted elements back to original array
    for (int i = 0; i < n; i++)
    {
        arr[i]=output[i];
    }   
}
void PrintArray(int arr[],int n){
    for(int i=0;i<n;i++){
        printf("%d  ",arr[i]);
    }
    printf("\n");
}
int main() {
    int arr[]={4,2,5,6,8,3,2,4,5,1,};
    int n= sizeof(arr)/sizeof(arr[0]);
    printf("Original Array: \n");
    PrintArray(arr,n);
    CountingSort(arr,n);
    printf("sorted Array: \n");
    PrintArray(arr,n);
    return 0;
}


