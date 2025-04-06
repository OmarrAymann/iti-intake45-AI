#include <stdio.h>
#include <stdlib.h>
#include <stdio.h>     // For input-output functions like printf
#include <stdlib.h>    // For system calls like system("cls") to clear the console
#include <Windows.h>   // For manipulating the console (e.g., cursor position, text attributes)
#include <string.h>    // For handling strings (used later in the menu)
#define null -32       // A constant used to handle special keys (like arrow keys)
#include <conio.h>

void gotoxy(int x,int y)
{
    COORD coord= {0,0};                          // Initialize a COORD structure
    coord.X = x;                                 // Set the X-coordinate (column)
    coord.Y = y;                                 // Set the Y-coordinate (row)
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord); // Move cursor to specified position
}
void textattr(int i)
{
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),i);
}
struct emp
{
    int age;
    int id;
    char name[30];
};
int main()
{
    int size ;
    printf("Enter your number of Employees  :");
    scanf("%d",&size);
    struct emp* ptr=(struct emp*)malloc(size*sizeof(struct emp));
    char menu [4][30] = {"NEW ", "DISPLAY OF ALL ID ","DISPLAY OF ONE ID ONLY" , "EXIT"};
    int i , j , k;
    int flag=0;
    int n=0;
    char ch;

    do
    {
        system("cls");

        for(i=0; i<4; i++)
        {
            gotoxy(1,1+i);
            if (i==n)
                textattr(0x04);
            _cprintf("%s",menu[i]);
            textattr(0x07);
        }
        ch = _getch();
        switch (ch)
        {
        case -32 :
            ch = _getch();
            switch (ch)
        {case 72 :
            n--;
            if(n<0)
                n=3;
            break;
        case 80 :
            n++;
            if(n>3)
                n=0;
            break;
        }
        break;
        case 27:
            flag = 1;
            break;
        case 13 :
            if(n==0)
            {
                system("cls");

        for(j=0;j<size;j++)
        {
            //printf("The age of (%d) Employee :",i+1);
            //scanf("%d",&ptr[i].age);
            printf("The id of (%d) The Employee :",j+1);
            scanf("%d",&ptr[j].id);
            //printf("The name of The Employee :");
            //scanf("%s",ptr[i].name);
        }
                ch = _getch();
            }

            else if(n==1)
            {
                system("cls");
                for(j=0;j<size;j++)
                    {
                        printf("The (%d) Employees Id : %d\n",j+1,ptr[j].id);
                    }
                ch = _getch();

            }
            else if(n==2)
            {

                system("cls");
                printf("which id : ..?");
                scanf("%d",&k);
                for (j=0;j<size;j++)
                {
                    if (k==j)
                {
                    printf("the id is : %d ",ptr[j].id);
                }
                }

                ch = _getch();

            }

            else if(n==3)
            {
                system("cls");
                printf("EXIT is selected");
                flag = 1;
            }

        }
    }
    while (flag == 0);
    return 0;
}
