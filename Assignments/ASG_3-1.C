#include <stdio.h>

void swap(int x , int y);

int main ()

{
    int x,y ;

    printf("please Enter the first Number : \n ");
    scanf("%d",&x);

    printf("please Enter the second Number : \n ");
    scanf("%d",&y);

    swap(x,y);
    return 0;
}

void swap(int x , int y)
{
    printf("Before swapping\n first number : %d \t second number : %d \n ",x,y);

    x= x+y ;
    y= x-y ;
    x= x-y ;


    printf("After swapping\n first number : %d \t second number : %d \n ",x,y);
}
