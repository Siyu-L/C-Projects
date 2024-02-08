/*
Program takes two complex numbers as input and outputs the product
Function takes no parameters
*/

#include <stdio.h>

int main() {
    int a;      //first number imaginary part
    int b;      //first number real part
    int c;      //second number imaginary part
    int d;      //second number real part

    printf("Enter the first complex number in the form ai + b: ");
    scanf("%d i + %d", &a, &b);
    printf("Enter the second complex number in the form ai + b: ");
    scanf("%d i + %d", &c, &d);
    printf("(%di + %d) * (%di + %d) = %di + %d\n", a, b, c, d, d*a + b*c, d*b - a*c);

    return 0;
}