// numbers must be sorted

#include <stdio.h>
#include <stdlib.h>
void binary_search(int arr[], int length,int y) ;

int main()
{

   int arr[]={5,10,12,16,20} ;
   int length = (sizeof(arr)/sizeof(arr[0])) ;
   int x ;

   printf("please Enter number to search : \n") ;
   scanf("%d",&x);

  binary_search(arr,length,x);


    return 0;
}

void binary_search(int arr[], int length,int y)
{
    int r,l,m ;
    r=length-1;
    l=0;

    while (l<=r)
    {
        m=(l+r)/2 ;
        if (arr[m]==y)
        {
            printf("value is exist");
            return ;
        }
        else if (y>arr[m])
        {
            l=m+1;
        }
        else if (y<arr[m])
        {
            r=m-1;
        }

    }
    printf("value is not exist");

}
