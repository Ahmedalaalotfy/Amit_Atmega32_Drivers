#include <stdio.h>

int main()
{
    int x,y ;
    char a ;

    printf("Enter the first number : \n ");
    scanf("%d",&x);

    printf("Enter the operator : \n ");
    scanf(" %c",&a);

    printf("Enter the second number : \n ");
    scanf("%d",&y);

    switch (a)
 {


    case '+' :
        printf("the result is : %d",x+y);
        break ;


    case '-' :
        printf("the result is : %d",x-y);
        break ;


    case '/' :
        printf("the result is : %d",x/y);
        break ;


    case '*' :
        printf("the result is : %d",x*y);
        break ;
}
    return 0;
}


