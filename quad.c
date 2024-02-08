/*
Program takes three numbers as user input which are used as the coefficients of quadratic formula
ax^2 + bx + c and outputs the number of real solutions and the solutions.
*/


#include <stdio.h>
#include <math.h>
/*
Given the quadratic formula ax^2 + bx + c, function returns one of the real solutions
Function takes the doubles a, b, and c, which are the coefficients of the quadratic formula as parameters
*/

double quadPlus(double a, double b, double c) {
    return (-b + sqrt(b*b - 4*a*c))/ (2*a);

}
/*
Given the quadratic formula ax^2 + bx + c, function returns one of the real solutions
Function takes the doubles a, b, and c, which are the coefficients of the quadratic formula as parameters
*/
double quadMinus(double a, double b, double c) {
    return (-b - sqrt(b*b - 4*a*c))/ (2*a);

}
/*
Given the quadratic formula ax^2 + bx + c, function returns the number of real solutions based on the coefficients
Function takes the doubles a, b, and c, which are the coefficients of the quadratic formula as parameters
*/

int realSol(double a, double b, double c) {
    if((b*b - (4*a*c)) > 0) {
        return 2;
    }
    else if ((b*b - (4*a*c)) == 0) {
        return 1;
    }
    else {
        return 0;
    }
}
int main() {
    double a;               //coefficient a
    double b;               //coefficient b
    double c;               //coefficient c
    int numSols;            //number of real solutions
    double firstSol;        //first real solution
    double secondSol;       //second real solution

    printf("Given a quadratic equation of the form a*x^2 + b * x + c\n");
    printf("Please enter a: ");
    scanf("%lf", &a);
    printf("Please enter b: ");
    scanf("%lf", &b);
    printf("Please enter c: ");
    scanf("%lf", &c);
    
    numSols = realSol(a,b,c);
    if(numSols == 0) {
        printf("There are no real solutions\n");
    }
    else if (numSols == 1) {
        firstSol = quadPlus(a,b,c);
        printf("There is one real solution: %.2lf\n", firstSol);

    }
    else {
        firstSol = quadPlus(a,b,c);
        secondSol = quadMinus(a,b,c);
        printf("There are 2 real solutions\n");
        printf("Solution 1: %.2lf\n", firstSol);
        printf("Solution 2: %.2lf\n", secondSol);

    } 


    return 0;
}