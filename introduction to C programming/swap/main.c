#include <stdio.h>
#include <stdlib.h>
void swap (int* x,int* y);
int main()
{
    int x ;
    int y ;
    printf(" please enter first number : ");
    scanf("%d",&x);
    printf(" please enter second number : ");
    scanf("%d",&y);
    swap(&x,&y);
    printf("x = %d , y = %d",x,y);

    return 0 ;
}
void swap (int *x,int *y)
{
    int z = *x ;
*x = *y ;
*y = z ;
}

