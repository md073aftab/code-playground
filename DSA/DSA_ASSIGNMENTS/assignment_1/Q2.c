#include <stdio.h>
int main(){
    int n,count=0;

    printf("enter size of array\n");
   scanf("%d",&n);

    int a[n];

    printf("enter the elements of the array\n");

    for (int i = 0; i < n; i++)
    {
        scanf("%d",&a[i]);
    }

    for (int i = 0; i < n-1; i++)
    {
        for (int j =  i+1 ; j < n; j++)         
        {
            if (a[i]>a[j])
            {
                count++;
            }
            else
            continue;
            
        }
           }

    printf("number of inversion of array A : %d",count);
    
    
    
    return 0;
}


