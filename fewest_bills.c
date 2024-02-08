
/*
*Program takes a number as amount of money to be withdrawn
*Outputs the fewest number of 100, 50, 20, 10, 5, and 1 bills which will equal the amount of money.
*Function has no parameters
*/

#include<stdio.h>

int main() {
    int userInput;
    int hundreds;
    int fifties;
    int twenties;
    int tens;
    int fives;

    printf("Please enter the amount of money you wish to withdraw: ");
    scanf("%d", &userInput);
    hundreds = userInput / 100;
    userInput %= 100;
    printf("You received %d hundred(s)\n", hundreds);

    fifties = (userInput) / 50;
    userInput %= 50;
    printf("You received %d fifty(s)\n", fifties);

    twenties = (userInput) / 20;
    userInput %=20;
    printf("You received %d twenty(s)\n", twenties);

    tens = (userInput) / 10;
    userInput %=10;
    printf("You received %d ten(s)\n", tens);

    fives = (userInput / 5);
    userInput %= 5;
    printf("You received %d five(s)\n", fives);

    printf("You received %d one(s)\n", userInput);

    return 0;

}