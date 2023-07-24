#include <stdio.h>

void selection_search(int arr[],int length) ;

int main ()
{
    int x , length ,i ;
    printf("Please enter the length of your array : ");
    scanf("%d",&length);
    int arr[length];

    printf("\nPlease enter the %d elements of your array : \n",length);

    for (i=0 ;i<length ;i++)
    {
        scanf("%d",&arr[i]);
    }

    selection_search(arr,length);


    return 0 ;
}

void selection_search(int arr[],int length)
{
    int i ,j,k,min,temp;

    for (i=0; i<length-1 ; i++)
{
    min = i ;
        for (j=i+1; j<length ;j++)
    {
      if (arr[j]<arr[min])
      {
         min = j ;
      }
    }
    if (min!=i)
    {
        temp=arr[i] ;
        arr[i]=arr[min];
        arr[min]=temp;
    }
}
printf("the sorted numbers are : ");
    for (k=0 ;k<length ;k++)
    {
        printf("%d \t",arr[k]);
    }
}
