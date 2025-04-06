#include <stdio.h>
#include <stdlib.h>
#define size 2
struct emp
{
    int id ;
    char name[30];
    int age ;
};
int main()
{
struct emp arr[size];
int i=0;

for (i=0;i<size;i++)
{
    printf("%d) Employee id :",i+1);
    scanf("%d %s %d",&arr[i].id,&arr[i].name,&arr[i].age);

}

for (i=0;i<size;i++)
    printf("\n %d)the id :%d",i+1,arr[i].id);
for (i=0;i<size;i++)
    printf("\n %d) the age :%d",i+1,arr[i].age);
for (i=0;i<size;i++)
    printf("\n %d) the name :%s",i+1,arr[i].name);
    return 0;
}
