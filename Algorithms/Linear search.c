#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool linear_search(int arr[], int length,int y) ;

int main()
{

   int arr[]={5,30,-5,15,20,40} ;
   int length= sizeof arr/sizeof arr[0] ;
   int x ;

   printf("please Enter number to search : \n") ;
   scanf("%d",&x);

   int y = linear_search(arr,length,x);
   printf("%d : \n",y) ;

    return 0;
}

bool linear_search(int arr[], int length,int y)
{
    int flag=0 ;
   for (int i = 0 ; i<length ; i++ )
   {
       if (y==arr[i])
       {
           printf("the number is exist\n");
           flag ++ ;
           return false ;
       }

   }
          if (flag==0)
       {
           printf("the number is not exist\n");
       }


}
