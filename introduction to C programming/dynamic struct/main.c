#include <stdio.h>
#include <stdlib.h>

struct emp
{
    int age;
    int id;
    char name[30];
};
int main()
{
    int i , size ;
    printf("Enter your number of Employees  :");
    scanf("%d",&size);
    struct emp* ptr=(struct emp*)malloc(size*sizeof(struct emp));
    if (ptr != NULL)
    {
        for(i=0;i<size;i++)
    {
            printf("The age of (%d) Employee :",i+1);
            scanf("%d",&ptr[i].age);
            printf("The id of The Employee :");
            scanf("%d",&ptr[i].id);
            printf("The name of The Employee :");
            scanf("%s",ptr[i].name);
    }
        for(i=0;i<size;i++)
    {
            printf("The (%d) Employee data : \nTHE age : %d\nTHE id :%d\nTHE Name :%s \n",i+1,ptr[i].age,ptr[i].id,ptr[i].name);
    }
    free(ptr);
    }
    return 0;
}
