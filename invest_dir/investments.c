/*
Program calculates if it's more beneficial to pay off loans first before investing
or to make minimum payments and invest the rest
*/

#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>

/*Input validation code from class drive*/

bool isValidFormat(const int numArgsRead, const int numArgsNeed);
bool isValidFormat(const int numArgsRead, const int numArgsNeed) {
  bool formatIsGood = numArgsRead == numArgsNeed;
  char character;
  do{
    scanf("%c", &character);
		if(!isspace(character)){ 
			formatIsGood = false;
		}
	}while(character != '\n');
  return formatIsGood;
}

int getValidInt(const char* prompt){
  int num;
  const int numArgsNeeded = 1;
  int numArgsRead;
  do{
    printf("%s", prompt);
    numArgsRead = scanf(" %d", &num);
  }while(!isValidFormat(numArgsRead, numArgsNeeded));

  return num;
}

double getValidDouble(const char* prompt){
  double num;
  const int numArgsNeeded = 1;
  int numArgsRead;
  do{
    printf("%s", prompt);
    numArgsRead = scanf(" %lf", &num);
  }while(!isValidFormat(numArgsRead, numArgsNeeded));

  return num;
}

int getIntAtLeast(int min_val, const char* prompt){
  int num;
  do{
    num = getValidInt(prompt);
  }while(!(num >= min_val));

  return num;
}

double getDoubleAtLeast(double min_val, const char* prompt){
  double num;
  do{
    num = getValidDouble(prompt);
  }while(!(num >= min_val));

  return num;
}

/*
calculates the result of paying off loan first
@param loan: how much owed in loans
@param monthlyInt: monthly interest rate on loans
@param moneyPerMonth: money put towards loans/retirement each month
@param monthlyReturns: predicted return on investment
@param numMonths: number of months between current age and retirement age
@return: amount of money you have when you retire
*/
double payOff(double loan, double monthlyInt, double moneyPerMonth, double monthlyReturn, double numMonths) {
  double investment = 0;
  for(int i = 0; i < numMonths; i++) {
      loan *= (1.0 + monthlyInt);
      investment *= (1.0 + monthlyReturn);
      if(loan - moneyPerMonth  > 0) {
        loan -= moneyPerMonth;
      }
      else {
        investment += moneyPerMonth - loan;
        loan = 0;

      }
  }
  return investment - loan;
}

/*
calculates the result of minimum loan payment and investing
@param loan: how much owed in loans
@param monthlyInt: monthly interest rate on loans
@param minPay: minimum monthly loan payment
@param moneyPerMonth: money put towards loans/retirement each month
@param monthlyReturns: predicted return on investment
@param numMonths: number of months between current age and retirement age
@return: amount of money you have when you retire
*/

double invest(double loan, double monthlyInt, double minPay, double moneyPerMonth, double monthlyReturn, double numMonths) {
  double investment = 0;
  for(int i = 0; i < numMonths; i++) {
      loan *= (1.0 + monthlyInt);
      investment *= (1.0 + monthlyReturn);
      if(loan - minPay> 0) {
      loan -= minPay;
      }
      else {
        investment += loan * -1;
        loan = 0;
        minPay = 0;
      }
      investment += moneyPerMonth - minPay;

  }
  return investment - loan;

}
/*
compares between result of paying off loan first or investing and outputs accordingly
@param invest: result of investing
@param payLoan: result of paying off loan first
@param money: money put towards loans/retirement each month

*/
void comparePrint(double invest, double payLoan, double money) {
  if(invest >= payLoan) {
    printf("You should only make the minimum payments on your loan and apply the rest towards retirement.\n");
    printf("If you do you will have $%.2lf when you retire as opposed to $%.2lf if you paid off your loan before investing.\n", invest, payLoan);
  }
  else {
    printf("You should apply all $%.2lf towards your loan before making any investments.\n", money);
    printf("If you do you will have $%.2lf when you retire as opposed to $%.2lf if you only made minimum payments.\n", payLoan, invest);
  }

}


int main() {
    double loan;
    double monthlyInt;
    double minPay;
    double moneyPerMonth;
    int age;
    int retire;
    int totalMonths;
    double monthlyReturn;

    double loanFirst;
    double investRest;
    
    loan = getDoubleAtLeast(0, "Enter how much you owe in loans: ");
    monthlyInt = getDoubleAtLeast(0, "Enter the annual interest rate of the loans: ") / 12.0;
    minPay = getDoubleAtLeast(0, "Enter your minimum monthly loan payment: ");\
    moneyPerMonth = getDoubleAtLeast(minPay, "Enter how much money you will be putting towards loans/retirement each month: ");
    age = getIntAtLeast(0,"Enter your current age: ");
    retire = getIntAtLeast(age, "Enter the age you plan to retire at: ");
    monthlyReturn = getDoubleAtLeast(0, "Enter your predicted annual rate of return: ") / 12.0;

    totalMonths = (retire - age) * 12;

    investRest = invest(loan, monthlyInt, minPay, moneyPerMonth, monthlyReturn, totalMonths);
    loanFirst = payOff(loan, monthlyInt, moneyPerMonth, monthlyReturn, totalMonths);
    
    comparePrint(investRest, loanFirst, moneyPerMonth);

    return 0;
}