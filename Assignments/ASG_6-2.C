#include <stdio.h>
struct complex
{
    float real;
    float imag;
} ;

struct complex add(struct complex number_1, struct complex number_2);

int main()
{
    struct complex number_1 ;
    struct complex number_2 ;
    struct complex result ;

    printf("For 1st complex number");
    printf("\nEnter the real and imaginary parts respectively : \n");
    scanf("%f",&number_1.real);
    scanf("%f",&number_1.imag);
    printf("\nFor 2nd complex number");
    printf("\nEnter the real and imaginary parts respectively : \n");
    scanf("%f",&number_2.real);
    scanf("%f",&number_2.imag);
    result = add(number_1,number_2);

    printf("Sum = %.1f + %.1fi", result.real, result.imag);
    return 0;
}

struct complex add(struct complex number_1, struct complex number_2)

 {
    struct complex sum;
    sum.real = number_1.real + number_2.real;
    sum.imag = number_1.imag + number_2.imag;
    return (sum);
}
