#include<stdio.h>


int main()

{
    int x,y,sum ,temp;
    sum = 0 ;

    printf("Enter the number :\n");
    scanf("%d",&x);

    temp=x ;

    while(x>0)
    {
        y=x%10;
        sum=sum+(y*y*y);
        x=x/10;
    }

    if(temp==sum)
        printf("Armstrong Number\n");
    else
        printf("Not Armstrong Number\n");
    return 0;
}
