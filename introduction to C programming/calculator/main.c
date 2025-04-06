#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n1 , n2 ;
    char ch ;

    printf("Enter operation :");
    scanf("%c",&ch);
    printf("Enter first number :");
    scanf("%d",&n1);
    printf("Enter second number :");
    scanf("%d",&n2);


    switch (ch) {
    case '+' :
        printf("%d + %d = %d", n1, n2, n1+n2);
        break;
    case '-' :
        printf("%d - %d = %d", n1, n2, n1-n2);
        break;
    case '*' :
        printf("%d * %d = %d", n1, n2, n1*n2);
        break;
    default :
        printf("invalid character");
        break;
}

    return 0;
}
