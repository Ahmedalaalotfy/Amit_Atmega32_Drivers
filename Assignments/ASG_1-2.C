#include <stdio.h>

int main()
{
    int x, n, y ;


    printf("Enter any number: ");
    scanf("%d", &x);

    printf("Enter nth bit to toggle (0-31): ");
    scanf("%d", &n);

    y = x ^ (1 << n);

    printf("Bit toggled successfully.\n");
    printf("Number before toggling %d bit: %d (in decimal)\n", n, x);
    printf("Number after toggling %d bit: %d (in decimal)\n", n, y);

    return 0;
}
