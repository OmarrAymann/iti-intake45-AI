#include <stdio.h>
#include <stdlib.h>

int main()
{
    int num , i ;
    printf("Enter the number : ");
    scanf("%d",&num);
    do{
        i = num % 10 ;
        printf("%d",i) ;
        num = num /10 ;

    }
    while(num !=0 ) ;
    return 0;
}
