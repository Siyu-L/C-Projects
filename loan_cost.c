/*
* Program gets user input on borrowed amount, annual interest rate, and number of payments
* Calculates cost of monthly payments and total cost of loan based on inputted info
* Function takes no parameters
*/


#include <stdio.h>
#include <math.h>

int main() {
    double borrowed;            //principle amount
    double interest;            //annual interest rate
    double monthlyInterest;     //monthly interest rate
    int numPayments;            //number of payments
    double monthly;             //monthly payment of loan
    double totalCost;           //total money paid for loan

    printf("Please enter the amount of money you borrowed: $");
    scanf("%lf", &borrowed);
    printf("Please enter the annual interest rate: ");
    scanf("%lf", &interest);
    printf("Please enter the number of payments to be made: ");
    scanf("%d", &numPayments);

    monthlyInterest = interest / 12;

    monthly = (borrowed * monthlyInterest) / (1- pow(1 + monthlyInterest, -numPayments));
    printf("A loan of $%.2lf with an annual interest of %.2lf paid off over %d months will have monthly payments of $%.2lf.\n", borrowed, interest, numPayments, monthly);

    totalCost = monthly * numPayments;

    printf("In total, you will pay $%.2lf, making the cost of your loan $%.2lf.\n", totalCost, totalCost - borrowed);


    return 0;
}