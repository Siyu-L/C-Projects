/* Program prints out pascal triangle with number of levels specified by user*/

#include <stdio.h>

/*
prints out a level of the pascal triangle
@param level: array to print out
@param num: number of elements to be printed
*/
void printLevel(int level[], int num) {
    for(int i = 0; i< num; i++) {
        printf("%d ", level[i]);
    }
    printf("\n");

}

/*
sets the current level of triangle based on previous level
@param prevLevel: previous level of triangle
@param currLevel: current level of triangle
@param num: number of elements in current level 
*/
void currentLevel(int prevLevel[], int currLevel[], int num) {
    currLevel[0] = 1;
    currLevel[num-1] = 1;
    for(int i = 1; i < num-1; i++) {
        currLevel[i] = prevLevel[i-1] + prevLevel[i];
    }

}

/*
creates the pascal's triangle
@param lvl: levels of pascal's triangle to be printed
*/
void triangle(int lvl) {

    int output[lvl][lvl];
    for(int i = 0; i < lvl; i++) {
        if((i+1) == 1) {
                output[i][0] = 1;
                printLevel(output[i], i+1);
            }
        else if ((i+1) == 2) {
                output[i][0] = 1;
                output[i][1] = 1;
                printLevel(output[i], i+1);
            }
        else {
                
                currentLevel(output[i-1], output[i], i+1);
                printLevel(output[i], i+1);
        }  

    }

}

int main() {
    int levels;
    printf("Please enter how many levels of Pascal's Triangle you would like to see: ");
    scanf("%d", &levels);
    triangle(levels);

    return 0;
}