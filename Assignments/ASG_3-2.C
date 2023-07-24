#include<stdio.h>

int Fibonacci(int x);

int main()
{
   int x, y ;
   y = 0 ;

   printf("Enter The Number\n");
   scanf("%d",&x);

   printf("Fibonacci series:");

   for ( int i = 1 ; i <= x ; i++ )
   {
      printf("%d, ", Fibonacci(y));
      y++;
   }

   return 0;
}

int Fibonacci(int x)
{
   if ( x == 0 )
      return 0;
   else if ( x == 1 )
      return 1;
   else
      return ( Fibonacci(x-1) + Fibonacci(x-2) );
}
