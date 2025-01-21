#include<stdio.h> 

int main(){
    int n;
    printf("Enter number of elements:");
    scanf("%d",&n);5
    int arr[n];
    printf("\nInput biotonic array\n");
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    int min=0,max=n-1;
    int mid= (n-1)/2;
    while(1){
        if(arr[mid]>arr[mid-1]&&arr[mid]<arr[mid+1]){
            min=mid;
            max=n-1;
        }
        else if(arr[mid]<arr[mid-1]&&arr[mid]>arr[mid+1]){
            max=mid;
            min=0;
        }
        else{
            printf("greatest element is:%d",arr[mid]);
            break;
        }
        mid=min+(max-min)/2;
    }
    
    return 0 ;
}