#include <stdio.h>

int main()
{
  int x, first , second , result;
  first = 0 ;
  second = 1 ;
  printf("Enter The number : \n");
  scanf("%d", &x);
  printf("Fibonacci Series is: ");
  for (int i = 0; i < x; i++)
  {
    if (i <= 1)
      result = i;
    else
    {
      result = first + second;
      first = second;
      second = result;
    }
    printf("%d ,", result);
  }
  return 0;
}
