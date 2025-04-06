#include <stdio.h>
#include <stdlib.h>
#define row 3
#define col 4
int main()
{
    int i=0 , j=0 , sum = 0 ;
    int arr[row][col]={0} ;
    int summation[3]={0};
    for(i=0;i<row;i++)
    {
        for(j=0;j<col;j++)
        {
        printf("array[%d][%d] : ",i,j);
        scanf("%d",&arr[i][j]);
        }
    }
    for(i=0;i<row;i++)
    {
        sum=0;
        summation[i]=0 ;
        for(j=0;j<row;j++)
           {
            sum += arr[i][j] ;
           }
           summation[i] = sum;
           printf("\nrow %d sum = %d \n",i,sum);
    }
    printf("\nthe summation :");
    for (i = 0; i < row; i++) {
        printf("%d ", summation[i]);
    }
    return 0;
}
