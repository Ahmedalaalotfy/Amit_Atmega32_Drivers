#include <stdio.h>

void bubble_search(int arr[],int length) ;

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

    bubble_search(arr,length);


    return 0 ;
}

void bubble_search(int arr[],int length)
{
    int i ,j,k,temp;

    for (i=0; i<length ; i++)
{
        for (j=0; j<length-1-i ;j++)
    {
      if (arr[j]>arr[j+1])
      {
        temp = arr[j+1];
        arr[j+1]= arr[j];
        arr[j]=temp;
      }
    }
}
printf("the sorted numbers are : ");
    for (k=0 ;k<length ;k++)
    {
        printf("%d \t",arr[k]);
    }
}
