#include <stdio.h>
#include <stdlib.h>

int main()
{
    int degree ;
    printf("please enter your degree : ");
    scanf("%d",&degree);
    if (degree >= 85)
        printf("Excellent");
    else if (degree >= 75)
        printf("Very good");
    else if (degree >= 65)
        printf("Good");
    else if (degree >= 60)
        printf("fair");
     else
          printf("fail");
    return 0;
}
