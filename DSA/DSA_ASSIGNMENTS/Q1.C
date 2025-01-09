#include <stdio.h>
int main()
{
    int n;

    printf("enter the number of elements in array : \n");
    scanf("%d",&n);

    int a[n];

    printf("enter the elements of array :\n");

    for (int i = 0; i < n; i++)
    {
        scanf("%d",a[i]);

    }
    int min = 0 ;
    int max = n-1 ;

    int mid =(min + max)/2 ;

    while (1)
    {
        if (a[mid]>a[mid -1] && a[mid]<a[mid + 1])
        {
            max= n-1 ;
            min =mid ;

        }
        else if (a[mid]<a[mid -1] && a[mid]>a[mid + 1])
        {
            max= mid ;
            min=0 ;

        }
        else{
            printf("max element from array is : %d", a[mid]);

        }

        mid = (min+max)/2 ;
        
        
    }

    printf("max element from array is : %d", a[mid]);

    return 0;
    


}


    
    
    
    
