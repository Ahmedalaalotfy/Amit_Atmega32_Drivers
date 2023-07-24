#include <stdio.h>

void edit(int*);
int main()
{
    int x ;
    int *ptr=&x ;

    printf("Enter the value of x : \n");
    scanf("%d",&x);

    printf("Before calling edit x = %d \n",x);

    edit(ptr);

    printf("After calling edit x = %d \n",x);
    return 0 ;

}

void edit(int*p)
{
    (*p)=(*p)+1 ;
}

