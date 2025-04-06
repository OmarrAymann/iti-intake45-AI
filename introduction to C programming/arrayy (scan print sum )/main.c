#include <stdio.h>
#include <stdlib.h>
#define size 5
int getsum(int arr[]);

int main()
{
        int i=0 , sum = 0 ;
    int arr[size]={0} ;
    for(i=0;i<size;i++)
    {
        printf("please enter your number %d : ",i+1);
        scanf("%d",&arr[i]);
    }
    for(i=0;i<size;i++)
    {
       printf("%d , ",arr[i]);
    }
    int z=getsum(arr);
    printf("\nthe summation : %d",z);

    return 0;
}
int getsum(int arr[])
{
    int sum = 0;
    int i ;
    for (i=0;i<size;i++)
        sum+=arr[i];
    return sum ;
}
