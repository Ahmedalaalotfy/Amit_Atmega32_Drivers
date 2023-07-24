#include <stdio.h>
#include <stdlib.h>

int main()
{
   int x ;

   printf("Please Enter The Number : \n");
   scanf("%d",&x);

   if((x & 1)==0)
   {
    printf("The number is odd=0 \n");
    printf("The number is even=1 \n");
   }

   else
   {
    printf("The number is odd=1 \n");
    printf("The number is even=0 \n");
   }

    return 0;
}




