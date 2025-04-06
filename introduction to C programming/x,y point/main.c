#include <stdio.h>
#include <stdlib.h>

struct emp
{
    int x ;
    int y ;
};
int main()
{
    struct emp e1 ={1,24};
    printf("please enter x :");
    scanf("%d",&(e1.x));
    printf("please enter y :");
    scanf("%d",&(e1.y));
    printf("The point (%d,%d)",e1.x,e1.y);
    return 0;
}
