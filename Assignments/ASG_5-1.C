#include <stdio.h>

int main()

{
    int arr_1[5], i,x,j;


    printf("please enter 5 numbers : \n ") ;

    for (i = 0; i<5 ; i++ )
    {
        scanf("%d",&arr_1[i]);
    }

        for ( i = 0; i<5 ; i++)
    {
        printf("%d\t",arr_1[i]);
    }

    int max = arr_1[0];
    int min = arr_1[0];
    int max1=0;
    int min1=0;


        for ( i = 0; i<5 ; i++)
    {
        if (arr_1[i]>max)
        {
            max =arr_1[i];
            max1= i ;
        }

        if (arr_1[i]<min)
        {
            min =arr_1[i];
            min1= i ;
        }

    }

        printf("\nthe maximum number is %d in position %d\n",max,max1);
        printf("the mimimum number is %d in position %d\n",min,min1);

       for (i = 0; i < 5; ++i)
        {

            for (j = i + 1; j < 5; ++j)
            {

                if (arr_1[i] > arr_1[j])
                {

                    x =  arr_1[i];
                    arr_1[i] = arr_1[j];
                    arr_1[j] = x;

                }

            }

        }
printf("the ascending sort of the numbers is : ");
   for ( i = 0; i<5 ; i++)
    {
        printf("%d\t",arr_1[i]);
    }


    return 0 ;
}
