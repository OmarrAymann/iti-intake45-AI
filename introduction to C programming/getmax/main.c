#include <stdio.h>
#include <stdlib.h>
int getmax(int x, int y);

int main()
{
    int x ;
    int y ;
    printf(" please enter first number : ");
    scanf("%d",&x);
    printf(" please enter second number : ");
    scanf("%d",&y);
    int z = getmax(x,y);
    printf("%d",z);
    return 0;
}
int getmax(int x, int y)
{

    if(x>y)
        return x;
    else
        return y;
}
