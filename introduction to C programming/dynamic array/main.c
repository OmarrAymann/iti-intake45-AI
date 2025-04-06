#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i , size ;
    printf("Enter your array size :");
    scanf("%d",&size);
    int* ptr=(int*)malloc(size*sizeof(int));
    //if (ptr != NULL)
    {
        for(i=0;i<size;i++)
    {
            scanf("%d",&ptr[i]);
    }
    printf("The array =");
        for(i=0;i<size;i++)
    {
            printf("[%d]",ptr[i]);
    }
    free(ptr);
    }
    return 0;
}
