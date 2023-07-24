#include<stdio.h>


int main(){

  int array[] = {1, 2, 3, 4, 5};
  int temp ;

  int i=0;
  int j=4;

  printf("Original array: ");
  for(int i=0; i<5; i++)
    {
    printf("%d \t",array[i]);
    }


  while(i<j)
    {
    temp = array[i];
    array[i] = array[j];
    array[j] = temp;

    i++;
    j--;
    }


  printf("\nReverse of array: ");
    for(int i=0; i<5; i++)
    {
    printf("%d \t",array[i]);
    }


  return 0;
}
