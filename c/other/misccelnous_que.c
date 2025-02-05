#include<stdio.h>

void plusminus(int arr_len, int *arr)
{
    int positive_num=0,negative_num=0,zero_num=0;
    for (int i = 0; i < arr_len; i++)
    {
        if (arr[i]>0)
        {
            positive_num++ ;
        }
        else if (arr[i]<0)
        {
            negative_num++ ;
        }
        else 
        {
            zero_num++ ;
        }
        
    }
    printf("%f\n",(float)positive_num/arr_len);
    printf("%f\n",(float)negative_num/arr_len);
    printf("%f\n",(float)zero_num/arr_len);
    

}
int main()
{
    int arr_len;
    scanf("%d",&arr_len);
    int arr[arr_len] ;
    
    for (int i = 0; i < arr_len; i++)
    {
        scanf("%d",&arr[i]);
    }
    plusminus(arr_len, arr);

    return 0;
    
}