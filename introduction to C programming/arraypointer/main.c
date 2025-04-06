#include <stdio.h>
#include <stdlib.h>

int main()
{
    int arr[5];
    int i=0;
    int *ptr=arr;
    for(i=0;i<5;i++)
        {
        scanf("%d",ptr+i);
        }
    for(i=0;i<5;i++)
        {
        printf("[%d]",*(ptr+i));
        }
    return 0;
}
