/*
* Program asks user for what grade they want, the required percentage to get said grade, their current grade, and the weight of the final
* Returns the percent they need to get on the final to get the grade they want
* Function takes no parameters 
*/

#include <stdio.h>

int main (){
    char letter;            //letter grade
    double req_percent;     //required percent to get grade
    double cur_percent;     //current percent
    double weight;          //weight of the final
    double final;           //percent on the final

    printf("Enter the grade you want in the class: ");
    scanf("%c", &letter);
    printf("Enter the percent you need to get that grade: ");
    scanf("%lf", &req_percent);
    printf("Enter your current percent in the class: ");
    scanf("%lf", &cur_percent);
    printf("Enter the weight of the final: ");
    scanf("%lf", &weight);

    final = (req_percent - (cur_percent * (1-(weight / 100))))/ (weight/100);
    
    printf("You need to get at least %.2lf%% on the final to get a %c in the class.\n", final, letter);

    return 0;
}